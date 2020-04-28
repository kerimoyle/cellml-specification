.. _example_reset_example5:

Example: Using variables as reset values
----------------------------------------

**Description**: A simple example demonstrating the behaviour where one variable is reset to the value of another. 

.. container:: shortlist

    Note that:

    - all elements are in the same component;
    - the order values of resets are not shown; and
    - all variables have dimensionless units.

.. code-block:: text

    component: 
      ├─ math: 
      │   └─ ode(B, t) = 1
      │
      ├─ variable: A initially 1
      │   └─ reset: rule 1
      │       ├─ when B == 4
      │       └─ then A = A + 1 
      │
      └─ variable: B initially 3
          └─ reset: rule 2
              ├─ when A == 2
              └─ then B = A + B
        
.. container:: toggle

    .. container:: header

        See CellML syntax

    .. code-block:: xml

        <variable name="t" units="dimensionless" />
        <variable name="A" units="dimensionless" initial_value="1" />
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

        <!-- Reset rule 1: -->
        <reset variable="A" test_variable="B">
            <test_value>
                <cn units="cellml:dimensionless">4</cn>
            </test_value>
            <!-- Variable A is given a value of A+1 when B equals 4. -->
            <reset_value>
                <apply><plus/>
                    <ci>A</ci>
                    <cn cellml:units="dimensionless">1</cn>
                </apply>
            </reset_value>
        </reset>

        <!-- Reset rule 2: -->
        <reset variable="B" test_variable="A">
            <test_value>
                <cn units="cellml:dimensionless">2</cn>
            </test_value>
            <!-- Variable B is given a value of A+B when A equals 2. -->
            <reset_value>
                <apply><plus/>
                    <ci>A</ci>
                    <ci>B</ci>
                </apply>
            </reset_value>
        </reset>

At :code:`t = 1` the following situation occurs:

+-----+---+---+
| *t* | 0 | 1 |
+-----+---+---+
| *A* | 1 | 1 |
+-----+---+---+
| *B* | 3 | 4 |
+-----+---+---+

At this point, reset rule 1 for *A* is active.
Its new value is calculated to be :code:`A → A + 1 = 1 + 1 = 2`.

+-----+---+-------+
| *t* | 0 | 1     |
+-----+---+-------+
| *A* | 1 | 1 → 2 |
+-----+---+-------+
| *B* | 3 | 4     |
+-----+---+-------+

This is a new point, so reset evaluation enters a second cycle.
In this cycle, the resets for both *A* and *B* are active.
The new values are calculated to be :code:`A → A + 1 = 2 + 1 = 3`, and :code:`B → A + B = 2 + 4 = 6`.
The new values are applied:

+-----+---+-----------+
| *t* | 0 | 1         |
+-----+---+-----------+
| *A* | 1 | 1 → 2 → 3 |
+-----+---+-----------+
| *B* | 3 |     4 → 6 |
+-----+---+-----------+

A new cycle of reset evaluation is applied, but finds no active resets, so model dynamics continue.
