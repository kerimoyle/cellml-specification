.. _example_reset_example4:

Example: Cascading
------------------

**Description**: Because resets change the value of variables, they can also trigger downstream reset activity as conditions which were not previously met become active.

.. container:: shortlist

    Note that:

    - all elements are in the same component;
    - the order values of resets are not shown; and
    - all variables have dimensionless units.

.. code-block:: text

    component: 
      ├─ math: 
      │   ├─ ode(A, t) = 1
      │   └─ ode(B, t) = 1
      │    
      ├─ variable: A initially 1
      │    └─ reset: rule 1
      │        ├─ when A == 4
      │        └─ then B = 5
      │
      └─ variable: B initially 2
           └─ reset: rule 2
               ├─ when A == 5
               └─ then B = 6
        
.. container:: toggle

    .. container:: header

        See CellML syntax

    .. code-block:: xml

        <variable name="t" units="dimensionless" />
        <variable name="A" units="dimensionless" initial_value="1" />
        <variable name="B" units="dimensionless" initial_value="2" />

        <math>
            <apply><eq/>
                <diff>
                    <ci>A</ci>
                    <bvar>t</bvar>
                </diff>
                <cn cellml:units="dimensionless">1</cn>
            </apply>
        </math>

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
                <cn units="cellml:dimensionless">4</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">5</cn>
            </reset_value>
        </reset>

        <!-- Reset rule 2: -->
        <reset variable="B" test_variable="A">
            <test_value>
                <cn units="cellml:dimensionless">5</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">6</cn>
            </reset_value>
        </reset>

At :code:`t = 2` the following situation occurs:

+-----+---+---+---+
| *t* | 0 | 1 | 2 |
+-----+---+---+---+
| *A* | 1 | 2 | 3 |
+-----+---+---+---+
| *B* | 2 | 3 | 4 |
+-----+---+---+---+

At this point reset rule 1 is the only active reset.
The change is applied:

+-----+---+---+-------+
| *t* | 0 | 1 | 2     |
+-----+---+---+-------+
| *A* | 1 | 2 | 3 → 5 |
+-----+---+---+-------+
| *B* | 2 | 3 | 4     |
+-----+---+---+-------+

Because the new point differs from the last, a second cycle of reset rule checking is started.
In this cycle, only reset rule 2 is active.
Again, the change is applied:

+-----+---+---+-----------+
| *t* | 0 | 1 | 2         |
+-----+---+---+-----------+
| *A* | 1 | 2 | 3 → 5     |
+-----+---+---+-----------+
| *B* | 2 | 3 |     4 → 6 |
+-----+---+---+-----------+

A third cycle is started, in which B is still active, but after applying the updates the new point is the same as at the end of cycle two, so reset evaluations halts and model dynamics continue.

+-----+---+---+-----------+---+-----+
| *t* | 0 | 1 | 2         | 3 | ... |
+-----+---+---+-----------+---+-----+
| *A* | 1 | 2 | 3 → 5     | 6 | ... |
+-----+---+---+-----------+---+-----+
| *B* | 2 | 3 |     4 → 6 | 7 | ... |
+-----+---+---+-----------+---+-----+
