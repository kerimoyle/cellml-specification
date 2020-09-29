.. _informC11_interpretation_of_resets2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding the reset order

    CellML is designed to represent complicated model behaviour, and this includes the idea that a single variable might need to be reset based different kinds of behaviour; or, that more than one reset is permitted per variable.

    Continuing the example from the previous block, we'll now add the behaviour of the automatic vacuum cleaner when it reaches its starting position at the first side of the room.

    .. code::

      model: CleaningTheHouse
        └─ component: Roomba
            ├─ variable: position 
            ├─ variable: width 
            │
            ├─ variable: velocity
            │    ├─ reset A: order = 1
            │    │   ├─ "when position equals width"
            │    │   └─ "then set negative velocity"
            │    └─ reset B: order = 2
            │        ├─ "when position equals start"
            │        └─ "then set positive velocity"
            │
            └─ math: 
                └─ ode(position, time) = velocity

    At present it's clear from the conditions on the two resets (the position at the start and at the far wall) that they cannot occur simulataneously, but this is not always the case.
    For this reason, every reset must specify an :code:`order` attribute which will be used as a tie-breaker in situations where more than one reset on a variable is active at the same time.

    It's also worth noting that because of the variable equivalence functionality, when we talk about "per variable" here, we're really including *all* resets which directly (as above, through the same :code:`variable` attribute) or indirectly (where another variable in the same equivalent variable set is referenced) change a variable's value.

    To illustrate the idea of the equivalent variables and order, we'll add a new component which represents the battery charge on the device.
    When the battery reaches a lower limit the machine will stop moving.

    .. code::

      model: CleaningTheHouse
        └─ component: Roomba
            ├─ variable: position 
            ├─ variable: width 
            ├─ variable: battery_level [charge], initially 100
            │
            ├─ variable: velocity
            │    ├─ reset A: order = 1
            │    │   ├─ "when position equals width"
            │    │   └─ "then set negative velocity"
            │    ├─ reset B: order = 2
            │    │   ├─ "when position equals start"
            │    │   └─ "then set positive velocity"
            │    └─ reset C: order = -1
            │        ├─ "when battery level is less than 10"
            │        └─ "then stop"
            │
            └─ math: 
                ├─ ode(position, time) = velocity
                └─ ode(battery_level, time) = -abs(velocity)

    .. container:: toggle

      .. container:: header

        Show CellML syntax

      .. code-block:: xml

        <model name="CleaningTheHouse">
          <component name="Roomba">
            <variable name="position" units="metre" />
            <variable name="width" units="metre" />
            <variable name="battery_level" units="charge" initial_value="100" />
            <variable name="velocity" units="metre_per_second" initial_value="0.1" />

            <!-- Reset A will set a negative velocity when the Roomba reaches 
                    the opposite wall: -->
            <reset variable="velocity" test_variable="position" order="1">
              <test_value>
                <ci>width</ci>
              </test_value>
              <reset_value>
                <cn cellml:units="metre_per_second">-0.1</cn>
              </reset_value>
            </reset>

            <!-- Reset B will set a positive velocity when the Roomba reaches
                    the starting wall: -->
            <reset variable="velocity" test_variable="position" order="2">
              <test_value>
                <cn cellml:units="metre">0</cn>
              </test_value>
              <reset_value>
                <cn cellml:units="metre_per_second">0.1</cn>
              </reset_value>
            </reset>

            <!-- Reset C will stop the Roomba when its charge is 10. -->
            <reset variable="velocity" test_variable="battery_level" order="-1">
              <test_value>
                <cn cellml:units="charge">10</cn>
              </test_value>
              <reset_value>
                <cn cellml:units="metre_per_second">0</cn>
              </reset_value>
            </reset>

            <math>
              <!-- Setting the width of the room as a constant: -->
              <apply>
                <eq/>
                <ci>width</ci>
                <cn cellml:units="metre">5</cn>
              </apply>

              <!-- Simple ODE for position of the Roomba with time: -->
              <apply>
                <eq/>
                <diff>
                  <ci>position</ci>
                  <bvar>time</bvar>
                </diff>
                <ci>velocity</ci>
              </apply>

              <!-- Simple ODE for charge of the Roomba with time: -->
              <apply>
                <eq/>
                <diff>
                  <ci>battery_level</ci>
                  <bvar>time</bvar>
                </diff>
                <apply>
                  <times/>
                  <apply>
                    <abs/>
                    <ci>velocity</ci>
                  </apply>
                  <cn units:cellml="charge_second_per_metre">-1</cn>
                </apply>
              </apply>

            </math>
          </component>

          <!-- Custom units needed: -->
          <units name="metre_per_second">
            <unit units="metre" />
            <unit units="second" exponent="-1" />
          </units>

          <units name="charge"/>

          <units name="charge_second_per_metre">
            <unit units="charge" />
            <unit units="metre_per_second" exponent="-1"/>
          </units>

        </model>
        
    In order for the machine to be able to stop when the battery is low, reset C must always be able to trump either of the other two as the conditions of reaching a wall and having a low battery could occur at the same time.
    This is accomplished by using an order of -1, making it lower than the order values of the other two resets, which also illustrates the idea that orders can be negative numbers (where the most negative is the most "important").

    .. container:: heading3
      
      Enacting the reset algorithm

    Behind the syntax of the resets is an algorithm which determines how they are interpreted.
    This algorithm is outlined below.

    1. For each reset item, determine whether its test criterion (the "when" idea above) has been met.

       a. If yes, the reset is said to be "active".
       b. If not, it is "inactive".

    2. Collect all *active resets* for a variable and its equivalent variables into a "variable active set".

    3. For each variable, select the lowest order reset from the *variable active set* and designate it "pending".

    4. Calculate, but do not apply, the update changes specified by each *pending* reset based on the current state of the model.

    5. Apply the updates calculated in (4).  
       This step means that the order in which the variables' values are altered does not affect the overall behaviour of the resets, as all of the updates are based on the unchanged state of the system.
    
    6. Test whether the set of variable values in the model has changed: 

       a. If yes, repeat the steps above from (1) using the updated values as the basis for the tests.
       b. If not, continue the modelling process with the updated values.

    Let's apply this to the example and see how it works. 
    Consider the state when the roomba has reached the other side of the room, and the battery level has fallen to 10.

    - Applying (1), both resets A and C are designated *active*.
    - Applying (2), both resets A and C explicitly reference the variable :code:`velocity`, so are in the same *active set* for that variable.  
    - Applying (3), we select reset C as having the lower order within the *active set*, and call it *pending*.
    - Applying (4), we evaluate the new value for the velocity variable to be zero because of the *pending* reset C.
    - Applying (5), set the velocity to zero.
    - Applying (6), this loop would be checked through again, but with the same result.
      The second time through the loop, we exit as there would be no further changes to the variables' values.

    There are alternative ways of arranging resets which would have the same functional outcome.
    These are described in :numref:`{number} {name}<index_examples_resets>`.

