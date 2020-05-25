.. _informC11_interpretation_of_variable_resets2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding reset order

    We'll continue the mythological story of Sisyphus rolling a boulder up a mountain, but tweak it a little.  
    The ruler of Tartarus has decided that Sisyphus can have a little help on Tuesdays, so once a week the boulder doesn't roll down the mountain until the following midnight, but Sisyphus still has to continue to push it upwards (I guess the mountain got bigger too).
    Adding a second :code:`reset` to the model gives us the arrangement shown below.

    .. code::

      model: Tartarus
        └─ component: Sisyphus
            ├─ units: metre_per_second
            ├─ maths: 
            │   ├─ time_of_day = time_of_week % 86400 [second]
            │   └─ ode(position, time_of_day) = 1 [metre_per_second]
            │
            ├─ variable: time_of_week [second]
            ├─ variable: time_of_day [second]
            └─ variable: position [metre], initially 0
                ├─ reset: A
                │   ├─ "when time of day is midnight"
                │   ├─ "then position is bottom of hill"
                │   └─ order: 2
                │
                └─ reset: B
                    ├─ "when time of day is midnight, and time of week is between Monday and Tuesday"
                    ├─ "then position is top of the hill"
                    └─ order: 1

    .. container:: toggle

      .. container:: header

        Show CellML syntax

      .. code-block:: xml

        <model name="Tartarus">
          <component name="Sisyphus">
            <variable name="time_of_day" units="second" />
            <variable name="time_of_week" units="second" />
            <variable name="position" units="metre" initial_value="0" />

            <!-- Reset A which will move the rock to the bottom of the hill each midnight: -->
            <reset variable="position" test_variable="time_of_day" order="2" >
              <test_value>
                <cn cellml:units="second">86399</cn>
              </test_value>
              <reset_value>
                <cn cellml:units="metre">0</cn>
              </reset_value>
            </reset>

            <!-- Reset B which will keep the rock at the top of the hill on Tuesdays: -->
            <reset variable="position" test_variable="time_of_week" order="1" >
              <test_value>
                <apply><plus/>
                  <cn cellml:units="second">86399</cn>
                  <cn cellml:units="second">86400</cn>
                </apply>
              </test_value>
              <reset_value>
                <cn cellml:units="metre">0</cn>
              </reset_value>
            </reset>

            <math>
              <!-- Simple ODE for position of the rock with time: -->
              <apply><eq/>
                <diff>
                  <ci>position</ci>
                  <bvar>time_of_day</bvar>
                </diff>
                <cn cellml:units="metre_per_second">1</cn>
              </apply>
              <!-- Calculating the time of day from the time of the week: -->
              <apply><eq/>
                <ci>time_of_day</ci>
                <apply><mod/>
                  <ci>time_of_week</ci>
                  <cn cellml:units="second">86400</cn>
                </apply>
              </apply>
            </math>

            <!-- Custom units needed to define the ODE above: -->
            <units name="metre_per_second">
              <unit units="metre" />
              <unit units="second" exponent="-1" />
            </units>

          </component>
        </model>


    At midnight between Monday and Tuesday *both* of the resets above are active: the first, reset A, because midnight on any day meets the midnight criterion; the second because 00:00 on Tuesday morning also meets the criterion for B.
    To decide which of the two consequences to enact - to roll the stone or not - we need to use the resets' orders as a tie-breaker.
    Here's how that works.

    .. container:: heading3
      
      Enacting the reset algorithm

    Behind the syntax of the resets is an algorithm which determines how they are interpreted.
    This algorithm is outlined below.

    1. For each reset item, determine whether its test criterion (the "when" idea above) has been met.

       a. If yes, set its status to "active".
       b. If not, set its status to "inactive".

    2. Collect all *active resets* for a variable and its equivalent variables into a "variable active set".

    3. For each variable, select the lowest order reset from the *variable active set* and designate it "pending".

    4. Calculate, but do not apply, the update changes specified by each *pending* reset based on the current state of the model.

    5. Apply the updates calculated in (4).  
       This step means that the order in which the variables' values are altered does not affect the overall behaviour of the resets, as all of the updates are based on the unchanged state of the system.
    
    6. Test whether the set of variable values in the model has changed: 

       a. If yes, repeat the steps above from (1) using the updated values as the basis for the tests.
       b. If not, continue the modelling process with the updated values.

    Let's apply this to the example and see how it works. 
    Consider the state when Sisyphus has reached the top of the mountain at midnight between Monday and Tuesday.

    - Applying (1), both resets A and B are designated *active*.
    - Applying (2), both resets A and B explicitly reference the variable :code:`position`, so are in the same *active set* for that variable.  
    - Applying (3), we select reset B as having the lower order within the *active set*, and call it *pending*.
    - Applying (4), we evaluate the new value for the position variable to be the top of the hill based on the *pending* reset B.
    - Applying (5), the boulder's position is unchanged.
    - Applying (6), we exit the reset evaluation cycle, and the model dynamics continue.
