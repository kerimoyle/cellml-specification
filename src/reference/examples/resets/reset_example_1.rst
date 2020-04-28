.. _example_reset_example1:

Example: Duplicated test conditions
-----------------------------------

**Description**: Here we show a simple example involving two resets which are both triggered by the same :code:`test_variable` and :code:`test_value` condition: :code:`B == 3`.
Despite this, the resets alter different variables (they have different :code:`reset_variable` attributes) and can thus be evaluated during the same loop, without needing to refer to the :code:`order` attribute.

.. container:: shortlist

    Note that:

    - all elements are in the same component;
    - the order values of resets are not shown; and
    - all variables have dimensionless units.

.. code-block:: text

    component: 
      ├─ math: ode(B, t) = 1
      │
      ├─ variable: A initially 1
      │   └─ reset: rule 1
      │       ├─ when B == 3
      │       └─ then A = 2
      │
      └─ variable: B initially 1 
          └─ reset: rule 2
              ├─ when B == 3
              └─ then B = 1

.. container:: toggle

    .. container:: header

        See CellML syntax

    .. code-block:: xml

        <variable name="A" units="dimensionless" initial_value="1" />
        <variable name="B" units="dimensionless" initial_value="1" />

        <math>
            <apply><eq/>
                <diff>
                    <ci>B</ci>
                    <bvar>t</bvar>
                </diff>
                <cn cellml:units="dimensionless">1</cn>
            </apply>
        </math>

        <!-- Reset rule 1: -->
        <reset variable="A" test_variable="B">
            <test_value>
                <cn units="cellml:dimensionless">3</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">2</cn>
            </reset_value>
        </reset>

        <!-- Reset rule 2: -->
        <reset variable="B" test_variable="B">
            <test_value>
                <cn units="cellml:dimensionless">3</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">1</cn>
            </reset_value>
        </reset>

At :code:`t = 2` the following situation occurs:

+-----+---+---+---+
| *t* | 0 | 1 | 2 |
+-----+---+---+---+
| *A* | 1 | 1 | 1 |
+-----+---+---+---+
| *B* | 1 | 2 | 3 |
+-----+---+---+---+

At this point, the integrator checks all reset rules, finding an active reset for both *A* and *B*. As a result, both values are updated:

+-----+---+---+-------+
| *t* | 0 | 1 | 2     |
+-----+---+---+-------+
| *A* | 1 | 1 | 1 → 2 |
+-----+---+---+-------+
| *B* | 1 | 2 | 3 → 1 |
+-----+---+---+-------+

Changes have been made, so a second cycle of reset evaluations is started.
No active reset rules are found so model dynamics continue.

+-----+---+---+-------+--------+---+
| *t* | 0 | 1 | 2     | 2 + dt | 3 |
+-----+---+---+-------+--------+---+
| *A* | 1 | 1 | 1 → 2 | 2      | 2 |
+-----+---+---+-------+--------+---+
| *B* | 1 | 2 | 3 → 1 | 1 + dt | 2 |
+-----+---+---+-------+--------+---+
