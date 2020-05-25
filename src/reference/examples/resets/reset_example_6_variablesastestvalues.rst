.. _example_reset_example6:

Example: Using variables as test values
---------------------------------------

**Description**: A simple example showing the behaviour when a reset test value is given by a variable.

.. container:: shortlist

    Note that:

    - all elements are in the same component;
    - the order values of resets are not shown; and
    - all variables have dimensionless units.

.. code-block:: text

    component: 
      ├─ math: 
      │   └─ ode(A, t) = 1
      │
      ├─ variable: A initially 1
      │
      └─ variable: B initially 2
          └─ reset: 
              ├─ when B == A
              └─ then B = B + 1
        
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
                    <ci>B</ci>
                    <bvar>t</bvar>
                </diff>
                <cn cellml:units="dimensionless">1</cn>
            </apply>
        </math>

        <reset variable="B" test_variable="B">
            <test_value>
                <ci>A</ci>
            </test_value>
            <!-- Variable B is given a value of B+1 when B equals A. -->
            <reset_value>
                <apply><plus/>
                    <ci>B</ci>
                    <cn cellml:units="dimensionless">1</cn>
                </apply>
            </reset_value>
        </reset>

At :code:`t = 1` the following situation occurs:

+-----+---+-----+-----+---+
| *t* | 0 | 0.1 | ... | 1 |
+-----+---+-----+-----+---+
| *A* | 1 | 1.1 | ... | 2 |
+-----+---+-----+-----+---+
| *B* | 2 | 2   | ... | 2 |
+-----+---+-----+-----+---+

The reset for B is now active, leading to the following update:

+-----+---+-----+-----+-------+
| *t* | 0 | 0.1 | ... | 1     |
+-----+---+-----+-----+-------+
| *A* | 1 | 1.1 | ... | 2     |
+-----+---+-----+-----+-------+
| *B* | 2 | 2   | ... | 2 → 3 |
+-----+---+-----+-----+-------+

A change has been made, so a second cycle of evaluations is started.
No resets are found to be active (*B* no longer equals *A*), and so model dynamics continue.

+-----+---+-----+-----+-------+-----+-----+-------+-----+
| *t* | 0 | 0.1 | ... | 1     | 1.1 | ... | 2     | 2.1 |
+-----+---+-----+-----+-------+-----+-----+-------+-----+
| *A* | 1 | 1.1 | ... | 2     | 2.1 | ... | 3     | 3.1 |
+-----+---+-----+-----+-------+-----+-----+-------+-----+
| *B* | 2 | 2   | ... | 2 → 3 | 3   | 3   | 3 → 4 | 4   |
+-----+---+-----+-----+-------+-----+-----+-------+-----+

At :code:`t = 2` the reset rule is triggered a second time, in a similar fashion.
