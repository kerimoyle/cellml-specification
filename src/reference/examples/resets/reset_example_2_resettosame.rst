.. _example_reset_example2:

Example: Reset to same
----------------------

**Description**: This example shows how reset evaluation halts if the model's set of system values :math:`(x, t, p)` has stopped changing.
The reset itself doesn't actually do anything, but it does go through the process of checking the active resets, applying them, and deciding whether or not to continue the reset evaluation loop.

.. container:: shortlist

    Note that:

    - all elements are in the same component;
    - the order values of resets are not shown; and
    - all variables have dimensionless units.

.. code-block:: text

    component: 
      ├─ math: ode(A, t) = 1
      └─ variable: A initially 1
          └─ reset: 
              ├─ when t == 1
              └─ then A = 2

.. container:: toggle

    .. container:: header

        See CellML syntax

    .. code-block:: xml

        <variable name="t" units="dimensionless" />
        <variable name="A" units="dimensionless" initial_value="1" />

        <math>
            <apply><eq/>
                <diff>
                    <ci>A</ci>
                    <bvar>t</bvar>
                </diff>
                <cn cellml:units="dimensionless">1</cn>
            </apply>
        </math>

        <reset variable="A" test_variable="t">
            <test_value>
                <cn units="cellml:dimensionless">1</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">2</cn>
            </reset_value>
        </reset>

+-----+-----+-----+-----+-----+-----+
| *t* | 0.0 | ... | 0.8 | 0.9 | 1.0 |
+-----+-----+-----+-----+-----+-----+
| *A* | 1   | ... | 1.8 | 1.9 | 2   |
+-----+-----+-----+-----+-----+-----+

At :code:`t = 1.0` the reset rule for *A* becomes active.
The update is calculated as :code:`A = 2`, and (finding no other values need to be calculated) the change is applied. 

After applying the change, the new point :math:`(x^\prime, t, p)` equals the old point :math:`(x, t, p)` and so reset evaluation is halted, and model dynamics continue.

+-----+-----+-----+-----+-----+-------+-----+-----+
| *t* | 0.0 | ... | 0.8 | 0.9 | 1.0   | 1.1 | 1.2 |
+-----+-----+-----+-----+-----+-------+-----+-----+
| *A* | 1   | ... | 1.8 | 1.9 | 2 → 2 | 2.1 | 2.2 |
+-----+-----+-----+-----+-----+-------+-----+-----+
