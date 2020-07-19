.. _informC11_interpretation_of_resets1:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding reset variables and test variables
      
    In the following example we want to model the position of an automatic vacuum cleaner as it deflects off two opposite walls in a room.
    The device follows a straight line until it encounters a wall, at which point it immediately switches direction and travels back to the other wall.
    We will use resets to model the interaction of the device with the wall, but before they're added, we'll start with a very simplistic model which describes the position of the device changing with time:

    .. code::

      model: CleaningTheHouse
        └─ component: Roomba
            ├─ variable: position [metre], initially 0
            ├─ variable: width [metre], constant, 5
            ├─ variable: velocity [metre_per_second], initially 0.1
            └─ math: 
                └─ ode(position, time) = velocity
    
    .. container:: toggle

      .. container:: header

        See CellML syntax

      .. code-block:: xml

        <model name="CleaningTheHouse">

          <component name="Roomba">
            <!-- Variables should be initialised using the initial_value attribute. -->
            <variable name="position" units="metre" initial_value="0" />
            <variable name="velocity" units="metre_per_second" initial_value="0.1" />

            <!-- Constants should be set in the math element so that they are true for all time. -->
            <variable name="width" units="metre" />

            <math>
              <!-- Constant: the room is 5m wide. -->
              <apply><eq/>
                <ci>width</ci>
                <cn cellml:units="metre">5</cn>
              </apply>

              <!-- Variable: the position of the device comes from solving the ODE. -->
              <apply><eq/>
                <diff>
                  <ci>position</ci>
                  <bvar>time</bvar>
                </diff>
                <ci>velocity</ci>
              </apply>

            </math>
          </component>
        </model>

    Now let's add a reset to this such that when the device reaches the opposite wall, its direction of travel is reversed.

    .. code::

      model: CleaningTheHouse
        └─ component: Roomba
            ├─ variable: position 
            ├─ variable: width 
            │
            ├─ variable: velocity
            │    └─reset:
            │      ├─ "when position equals width"
            │      └─ "then go back the other way"
            │
            └─ math: 
                └─ ode(position, time) = velocity

    .. container:: toggle

      .. container:: header

        Show CellML syntax
      
      .. code-block:: xml

        <reset variable="velocity" test_variable="position" order="1">

          <!-- The "when" statement above is true when the test_variable 
              attribute equals the test_value statement: -->
          <test_value>
            <ci>width</ci>
          </test_value>

          <!-- The "then" statement above is defined by setting the
                variable attribute to the reset_value statement: -->
          <reset_value>
              <cn cellml:units="metre_per_second">-0.1</cn>
          </reset_value>
        </reset>
    
    The behaviour at the other end of the wall is discussed in the following section.
