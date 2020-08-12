.. _example_reset_misuse_touchingnotcrossing:

Misuse: Touching, not crossing
------------------------------

**Description:** Resets whose :code:`test_value` coincides with a turning point of the :code:`test_variable` risk missing detection of the reset point.

.. container:: shortlist

    Note that:

    - all elements are in the same component;
    - the order values of resets are not shown; and
    - the units of variables are not shown.

.. code-block:: text

    component: TouchingNotCrossing
      ├─ math: x = sin(t*pi/2)
      ├─ variable: x
      └─ variable: y initially 0
          ├─ reset: rule 1
          │   ├─ when x == 1
          │   └─ then y = 1
          └─ reset: rule 2
              ├─ when x == -1
              └─ then y = 0

.. container:: toggle

    .. container:: header

        See CellML syntax

    .. code-block:: xml

        <variable name="t" units="dimensionless" />
        <variable name="x" units="dimensionless" />
        <variable name="y" units="dimensionless" initial_value="0" />

        <math>
            <apply><eq/>
                <ci>x</ci>
                <apply><sin/>
                    <apply><times/>
                        <ci>t</ci>
                        <apply><divide/>
                            <pi/>
                            <cn cellml:units="dimensionless">2</cn>
                        </apply>
                    </apply>
                </apply>
            </apply>
        </math>

        <!-- Reset rule 1: -->
        <reset variable="y" test_variable="x">
            <test_value>
                <cn units="cellml:dimensionless">1</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">1</cn>
            </reset_value>
        </reset>

        <!-- Reset rule 2: -->
        <reset variable="y" test_variable="x">
            <test_value>
                <cn units="cellml:dimensionless">-1</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">0</cn>
            </reset_value>
        </reset>

A simulation with this model might proceed as follows:

+-----+-----+-------+-----+-------+-------+-------+-----+--------+-------+-------+-----+
| *t* | 0.0 | 0.1   | ... | 0.9   | 1.0   | 1.1   | ... | 2.9    | 3.0   | 3.3   | ... |
+-----+-----+-------+-----+-------+-------+-------+-----+--------+-------+-------+-----+
| *x* | 0   | 0.156 | ... | 0.988 | 1     | 0.988 | ... | -0.988 | -1    | 0.988 | ... |
+-----+-----+-------+-----+-------+-------+-------+-----+--------+-------+-------+-----+
| *y* | 0   | 0     | ... | 0     | 0 → 1 | 1     | ... | 1      | 1 → 0 | 0     | ... |
+-----+-----+-------+-----+-------+-------+-------+-----+--------+-------+-------+-----+

However, it is easy for implementations to "miss" this type of reset in a simulation.
For example, the following may occur in an implementation with adaptive step sizes that uses root finding to detect resets (i.e.: by searching for sign changes in :code:`x - 1`):

+---------+-----+--------+-----+-------+-------+--------+-----+
| *t*     | 0.0 | 0.4    | ... | 0.9   | 1.1   | 1.7    | ... |
+---------+-----+--------+-----+-------+-------+--------+-----+
| *x*     | 0   | 0.588  | ... | 0.988 | 0.988 | 0.454  | ... |
+---------+-----+--------+-----+-------+-------+--------+-----+
| *y*     | 0   | 0      | ... | 0     | 0     | 0      | 0   |
+---------+-----+--------+-----+-------+-------+--------+-----+
| *x - 1* | -1  | -0.412 | ... | -0.12 | -0.12 | -0.546 | ... |
+---------+-----+--------+-----+-------+-------+--------+-----+

This behaviour is expected to be common in implementations. 
For example, the popular adaptive solver :cvode:`CVODE` has a root finding mechanism that can be used to implement reset rules, but its documentation explicitly states it is unlikely to find roots where the sign does not change.
As a result, this type of reset rule is probably best avoided.

Suggestions
~~~~~~~~~~~
**TODO** ?