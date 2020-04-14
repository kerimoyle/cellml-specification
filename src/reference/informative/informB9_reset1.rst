.. _informB9:
.. _inform_reset:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding reset elements

    Resets are a new addition to CellML in version 2.0, and their intention is to allow the user to specify how and when discontinuities can exist in variable values throughout the solution.
    A reset lets you do just that: reset a variable to a totally different value, restart a timer, flip a switch, take a step, start again.
    In order to work, a reset needs to know some information:

    - Which variable's value do you want to change?
      This is called the "reset variable" and is specified by the :code:`variable` attribute in the :code:`reset` block.
    - Which variable will tell us when to trigger the change?
      This is called the "test variable" and is referenced by the :code:`test_variable` attribute in the :code:`reset` block.
      The test variable can be the same as the reset variable.
    - What happens if more than one reset points to the same reset variable?
      This will be sorted out by the unique :code:`order` attribute on each :code:`reset` element which changes this reset variable.
      The order will determine which of the valid competing resets is applied.
    - What new value should be given to the reset variable?
      This is called the "reset value" and is specified by evaluating the MathML content which is inside the :code:`reset_value` element child of this :code:`reset` element.
    - What value of the test variable should be used to trigger the change?
      This is called the "test value" and is specified by evaluating the MathML content inside the :code:`test_value` element child of this :code:`reset` element.

    In the following example we want to model the position of an automatic vacuum cleaner as it deflects off two opposite walls in a room.
    The device follows a straight line until it encounters a wall, at which point it immediately switches direction and travels back to the other wall.
    We will use resets to model the interaction of the device with the wall, but before they're added, we'll start with a very simplistic model which describes the position of the device changing with time:

    .. code::

      model: NotCleaningTheHouse
        units: metres_per_second
          unit: metre
          unit: second, exponent = -1
        component: Roomba
          variable: position (metre), initially 0
          variable: velocity (metres_per_second), initially 0.5
          variable: time (second), initially 0
          variable: time_step (second), constant, 0.1
          variable: width (metre), constant, 5
          math: 
            position = position + time_step*velocity
            time = time + time_step
    
    .. container:: toggle

      .. container:: header

        See CellML syntax

      .. code-block:: xml

        <model name="NotCleaningTheHouse">
          <units name="metres_per_second">
            <unit units="metre" />
            <unit units="second" exponent="-1" />
          </units>
          <component name="Roomba">
            <!-- Variables should be initialised using the initial_value attribute. -->
            <variable name="position" units="metre" initial_value="0" />
            <variable name="velocity" units="metres_per_second" initial_value="0.5" />
            <variable name="time" units="second" initial_value="0" />

            <!-- Constants should be set in the math element so that they are true for all time. -->
            <variable name="time_step" units="second"/>
            <variable name="width" units="metre" />

            <math>
              <!-- Constants: the room is 5m wide. -->
              <apply><eq/>
                <ci>width</ci>
                <cn cellml:units="metre">5</cn>
              </apply>

              <!-- Constant: the timestep for calculations will be 0.1s. -->
              <apply><eq/>
                <ci>time_step</ci>
                <cn cellml:units="second">0.1</cn>
              </apply>
              
              <!-- Variable: the overall time will increment by the timestep each iteration. -->
              <apply><eq/>
                <ci>time</ci>
                <apply><plus/>
                  <ci>time</ci>
                  <ci>time_step</ci>
                </apply>
              </apply>

              <!-- Variable: the position of the device will increment based on its velocity and previous positon. -->
              <apply><eq/>
                <ci>position</ci>
                <apply><plus/>
                  <ci>position</ci>
                  <apply><times/>
                    <ci>time_step</ci>
                    <ci>velocity</ci>
                  </apply>
                </apply>
              </apply>

            </math>
          </component>
        </model>

    Now let's add a reset to this such that when the device reaches the opposite wall its direction of travel reverses.
    In pseudocode this would be:

    .. code::

      if (position equals width)    # statement A below
      then (change direction)       # statement B below
      else (do not change direction)

    In CellML this would be:

    .. code-block:: xml

      <reset variable="velocity" test_variable="position" order="1">

        <!-- Statement A above is true when the test_variable 
             equals the test_value statement: -->
        <test_value>
          <ci>width</ci>
        </test_value>

        <!-- Statement B above is defined by setting the reset
             variable to the reset_value statement: -->
        <reset_value>
          <apply><times/>
            <ci>velocity</ci>
            <cn cellml:units="dimensionless">-1</cn>
          <apply>
        </reset_value>
      </reset>
    
    Finally, we need another reset which will simulate the return of the device to its starting place at the first wall, where it again reverses direction.

    .. code-block:: xml

      <reset variable="velocity" test_variable="position" order="2">
        <test_value>
          <cn units:cellml="metre">0</cn>
        </test_value>
        <reset_value>
          <apply><times/>
            <ci>velocity</ci>
            <cn cellml:units="dimensionless">-1</cn>
          <apply>
        </reset_value>
      </reset>
