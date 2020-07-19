.. _informC11_interpretation_of_resets1:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding reset variables and test variables

    Consider the following example which represents the mythological story of Sisyphus.
    Sisyphus was condemned to live in Tartarus - a section of the Underworld - and roll a huge boulder up a mountain each day.
    And, every midnight, the boulder would roll to the bottom and the process would begin all over again.

    We will assume in this model that Sisyphus' position up the mountain increments by 1 metre each second, and that he works constantly through day and night.

    .. code::

      model: UnderworldOfTartarus
        └─ component: Sisyphus
            ├─ units: metre_per_second
            ├─ maths: 
            │    └─ ode(position, time) = 1 [metre_per_second]
            ├─ variable: time [second]
            └─ variable: position [metre], initially 0
                └─ reset:
                    ├─ "when time is midnight"
                    └─ "then the boulder's position is the bottom of the hill"

    In this example it's clear that for the reset to operate, it must know what is happening and when; this is the interpretation of the *when* and *then* statements above, which (as outlined in :numref:`{number} {name}<reset>`) are controlled by the :code:`test_variable` / :code:`test_value` and :code:`variable` / :code:`reset_value` combinations respectively.

    .. code::

      model: UnderworldOfTartarus
        └─ component: Sisyphus
            ├─ units: metre_per_second
            ├─ maths: 
            │    └─ ode(position, time) = 1 [metre_per_second]
            ├─ variable: time [second]
            └─ variable: position [metre], initially 0
                └─ reset:
                    ├─ "when time is midnight"
                    │     ├─ test_variable: time
                    │     └─ test_value:
                    │          └─ math: "is midnight"
                    │              └─ 86400
                    │
                    └─ "then the boulder's position is the bottom of the hill"
                          ├─ variable: position
                          └─ reset_value:
                               └─ math: "bottom of the hill"
                                    └─ 0

    .. container:: toggle

      .. container:: header

        Show CellML syntax

      .. code-block:: xml

        <model name="Tartarus">
          <component name="Sisyphus">
            <variable name="time" units="second" />
            <variable name="position" units="metre" initial_value="0" />

            <!-- The reset which will move the rock to the bottom of the hill each midnight: -->
            <reset variable="position" test_variable="time" order="1">
              <!-- The "when" statement above is given by testing the equality 
                   of the test_variable's value and the test_value: -->
              <test_value>
                <cn cellml:units="second">86400</cn>
              </test_value>

              <!-- The "then" statement above is specified by setting the variable's
                   value to the evaluation of the reset_value: -->
              <reset_value>
                <cn cellml:units="metre">0</cn>
              </reset_value>
            </reset>

            <!-- Simple ODE for position of the rock with time: -->
            <math>
              <apply><eq/>
                <diff>
                  <ci>position</ci>
                  <bvar>time</bvar>
                </diff>
                <cn cellml:units="metre_per_second">1</cn>
              </apply>
            </math>

            <!-- Custom units needed to define the ODE above: -->
            <units name="metre_per_second">
              <unit units="metre" />
              <unit units="second" exponent="-1" />
            </units>

          </component>
        </model>
 
    In the next block we will explore what happens when more than one reset tries to change a variable's value at the same time.
