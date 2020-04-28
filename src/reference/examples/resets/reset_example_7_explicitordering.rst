.. _example_reset_example7:

Example: Explicit reset ordering
--------------------------------

**Description**: Resets which address the same variable can use the :code:`order` attribute to establish a priority for evaluation.
Note that "order" here refers to the sequence in which resets are *tested*, not the sequence in which they are *applied*. 
The former determines which reset is selected in an evaluation cycle (only one reset per variable is applied); the latter does not affect the final system values (see :numref:`Figure {number}<reset_rules_2_composite>`).

.. container:: shortlist

    Note that:

    - all elements are in the same component; and
    - all variables have dimensionless units.

.. code-block:: text

    component: 
      ├─ math: 
      │      ode(B, t) = 1
      │
      ├─ variable: A initially 2
      │    ├─ reset: rule 1
      │    │    ├─ order = 1
      │    │    ├─ when B == 4
      │    │    └─ then A = 1
      │    │
      │    └─ reset: rule 2
      │         ├─ order = 2
      │         ├─ when B == 4
      │         └─ then A = 3
      │
      └─ variable: B initially 3

        
.. container:: toggle

    .. container:: header

        See CellML syntax

    .. code-block:: xml

        <variable name="t" units="dimensionless" />
        <variable name="A" units="dimensionless" initial_value="2" />
        <variable name="B" units="dimensionless" initial_value="3" />

        <math>
            <apply><eq/>
                <diff>
                    <ci>B</ci>
                    <bvar>t</bvar>
                </diff>
                <cn cellml:units="dimensionless">1</cn>
            </apply>
        </math>

        <!-- Reset rule 1: order = 1 -->
        <reset variable="A" test_variable="B" order="1">
            <test_value>
                <cn cellml:units="dimensionless">4</cn>
            </test_value>
            <reset_value>
                <cn cellml:units="dimensionless">1</cn>
            </reset_value>
        </reset>

        <!-- Reset rule 2: order = 2 -->
        <reset variable="A" test_variable="B" order="2">
            <test_value>
                <cn cellml:units="dimensionless">4</cn>
            </test_value>
            <reset_value>
                <cn cellml:units="dimensionless">3</cn>
            </reset_value>
        </reset>

At :code:`t = 1` the following situation occurs:

+-----+---+---+
| *t* | 0 | 1 |
+-----+---+---+
| *A* | 2 | 2 |
+-----+---+---+
| *B* | 3 | 4 |
+-----+---+---+

There are now two different reset rules for *A* that could be active, so the one with the lower order (reset rule 1) is selected.

+-----+---+-------+
| *t* | 0 | 1     |
+-----+---+-------+
| *A* | 2 | 2 → 1 |
+-----+---+-------+
| *B* | 3 | 4     |
+-----+---+-------+

The system has moved to a new point, so a second round of resets is run.
Both resets are still active so again the reset with the lowest order is selected and applied, leading to the same result.
After this second cycle the system has not changed, so reset evaluation is halted.
