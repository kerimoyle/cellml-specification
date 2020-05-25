.. _example_reset_example3:

Example: Order of evaluation
----------------------------

**Description**: This example shows the behaviour when a reset value involves a variable.

.. container:: shortlist

    Note that:

    - all elements are in the same component;
    - resets are shown attached to their :code:`variable` attribute; 
    - the order values of resets are not shown; and
    - all variables have dimensionless units.

.. code-block:: text

    component: 
      ├─ math: ode(B, t) = 1
      │
      ├─ variable: A initially 1
      │   └─ reset: rule 1
      │       ├─ when B == 3
      │       └─ then A = B
      │
      └─ variable: B initially 1
          └─ reset: rule 2
              ├─ when B == 3
              └─ then B = 1 

        
.. container:: toggle

    .. container:: header

        See CellML syntax

    .. code-block:: xml

        <variable name="t" units="dimensionless" />
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
                <ci>B</ci>
            </reset_value>
        </reset>

        <!-- Reset rule 2: -->
        <reset variable="A" test_variable="B">
            <test_value>
                <cn units="cellml:dimensionless">3</cn>
            </test_value>
            <reset_value>
                <ci>B</ci>
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

At this point :math:`(x, t, p)`, the test conditions for both resets are true, so both are active. 
New values are first calculated, and then applied to yield a new point :math:`(x^\prime, t, p)`:

+-----+---+---+-------+
| *t* | 0 | 1 | 2     |
+-----+---+---+-------+
| *A* | 1 | 1 | 1 → 3 |
+-----+---+---+-------+
| *B* | 1 | 2 | 3 → 1 |
+-----+---+---+-------+

Note that both tests are performed using :math:`(x, t, p)`, so the order of these tests doesn't change the outcome. 
Secondly, because the changes are orthogonal (each reset affects a different node in the directed acyclic graph), we can apply them in any order and reach the same point :math:`(x^\prime, t, p)`.

Because :math:`(x^\prime,t, p) \neq (x, t, p)` a second round of reset evaluation is started, but no active resets are found, the reset evaluation is halted and model dynamics continue.

+-----+---+---+-------+--------+---+
| *t* | 0 | 1 | 2     | 2 + dt | 3 |
+-----+---+---+-------+--------+---+
| *A* | 1 | 1 | 1 → 3 | 3      | 3 |
+-----+---+---+-------+--------+---+
| *B* | 1 | 2 | 3 → 1 | 1 + dt | 2 |
+-----+---+---+-------+--------+---+
