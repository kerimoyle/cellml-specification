.. _informC11_interpretation_of_resets3:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding the ``test_value`` and ``reset_value`` elements

    In the previous block we introduced a model which showed how both a low battery and an encounter with a wall could affect the velocity of the Roomba, and used the :code:`order` attribute to determine which reset was followed.
    Now we'd like to make sure that the low-battery Roomba is only ever stopped at a wall, so that people don't trip up on it.

    Conditional statements are legal inside both the :code:`test_value` block and :code:`reset_value` blocks, so we can write this (excluding units) as:

    .. code::

      model: CleaningTheHouse
        └─ component: Roomba
            ├─ variable: position 
            ├─ variable: width 
            ├─ variable: battery_level [charge], initially 100
            │
            ├─ variable: velocity
            │    ├─ reset A1: order = 1
            │    │   ├─ "when IF position equals width AND battery level is more than 10"
            │    │   └─ "then set negative velocity"
            │    ├─ reset A2: order = 2
            │    │   ├─ "when IF position equals width AND battery level is 10 or less"
            │    │   └─ "then stop"
            │    │
            │    └─ reset B: order = 2
            │        ├─ "when position equals start AND battery level is more than 10"
            │        └─ "then IF battery is more than 10 set positive velocity ELSE stop"
            │
            └─ math: 
                ├─ ode(position, time) = velocity
                └─ ode(battery_level, time) = -abs(velocity)
  
    In this situation, reset A1 is only ever active when there is sufficient battery to change direction.
    This means that we've had to add a second reset A2 that tests for when the far wall is encountered and the battery is low.
    In contrast, similar behaviour is found in reset B using just one reset, where the conditional statement is in the reset value rather than the test value.

    While they will work in this situation, it's better to avoid using conditional statements with resets if possible.
    The situation above could be reframed to supply the extra battery conditions like this:

    .. code:: 

      model: CleaningTheHouse
        └─ component: Roomba
            ├─ variable: position [metre], initially 0
            ├─ variable: width [metre], constant 5
            ├─ variable: battery_level [charge], initially 100
            │
            ├─ variable: battery_check [dimensionless], initially 1
            │    └─ reset C: order = 1
            │        ├─ "when battery_level equals 10"
            │        └─ "then set battery_check to 0"
            │
            ├─ variable: velocity [metre_per_second], initially 0.1
            │    ├─ reset A: order = 1
            │    │   ├─ "when position equals width"
            │    │   └─ "then velocity to be negative product with battery_check"
            │    └─ reset B: order = 2
            │        ├─ "when position equals start"
            │        └─ "then set to be positive product with battery_check"
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
              <variable name="battery_check" units="dimensionless" initial_value="0" />

              <!-- Resets active at any position tell when the battery check means it should
              be stopped at the next wall encounter. Note that this doesn't actually affect 
              the velocity of the Roomba until either reset A or B is active. -->
              <reset variable="battery_check" test_variable="battery_level" order="1">
                  <test_value>
                      <cn cellml:units="charge">10</cn>
                  </test_value>
                  <reset_value>
                      <ci cellml:units="dimensionless">1</ci>
                  </reset_value>
              </reset>

              <!-- Reset A will set a negative velocity when the Roomba reaches 
                  the opposite wall, provided the battery_check is not zero. -->
              <reset variable="velocity" test_variable="position" order="1">
                  <test_value>
                      <ci>width</ci>
                  </test_value>
                  <reset_value>
                      <apply>
                          <times/>
                          <cn cellml:units="metre_per_second">-0.1</cn>
                          <ci>battery_check</ci>
                      </apply>
                  </reset_value>
              </reset>
              <!-- Reset B2 will set a positive velocity when the Roomba reaches
                  the starting wall, provided the battery_check is not zero. -->
              <reset variable="velocity" test_variable="position" order="2">
                  <test_value>
                      <cn cellml:units="metre">0</cn>
                  </test_value>
                  <reset_value>
                      <apply>
                          <times/>
                          <cn cellml:units="metre_per_second">0.1</cn>
                          <ci>battery_check</ci>
                      </apply>
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
