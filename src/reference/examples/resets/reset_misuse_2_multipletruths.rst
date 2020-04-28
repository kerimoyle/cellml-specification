.. _example_reset_misuse_multiple_truths:

Misuse: Multiple truths
-----------------------

**Description:** The behaviour specified in resets must complement the mathematics of the model; it does not over-ride it.
For this reason, models containing reset variables which are also present in maths statements are over-defined.
This is shown in the example below.

Note that:

- all elements are in the same component;
- the order values of resets are not shown; and
- all variables have dimensionless units.

.. code-block:: text

    component: MultipleTruths
        ├─ math: 
        │   ├─ x = t % 1000
        │   └─ y = 0
        │
        ├─ variable: x 
        │
        └─ variable: y 
            ├─ reset: rule 1
            │   ├─ when x == 100
            │   └─ then y = 1
            │
            └─ reset: rule 2
                ├─ when x == 101
                └─ then y = 0

.. container:: toggle

    .. container:: header

        See CellML syntax

    .. code-block:: xml

        <variable name="t" units="dimensionless" />
        <variable name="x" units="dimensionless" />
        <variable name="y" units="dimensionless" />

        <math>
            <!-- x = t % 1000 -->
            <apply><eq/>
                <ci>x</ci>
                <apply><rem/>
                    <ci>t</ci>
                    <cn cellml:units="dimensionless">1000</cn>
                </apply>
            </apply>

            <!-- y = 0 -->
            <apply><eq/>
                <ci>y</ci>
                <cn cellml:units="dimensionless">0</cn>
            </apply>
        </math>

        <!-- Reset rule 1: -->
        <reset variable="y" test_variable="x">
            <test_value>
                <cn units="cellml:dimensionless">100</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">1</cn>
            </reset_value>
        </reset>

        <!-- Reset rule 2: -->
        <reset variable="y" test_variable="x">
            <test_value>
                <cn units="cellml:dimensionless">101</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">0</cn>
            </reset_value>
        </reset>

+-----+-----+-----+------+-------------+
| *t* | 0.0 | ... | 99.9 | 100         |
+-----+-----+-----+------+-------------+
| *x* | 0   | ... | 99.9 | 100         |
+-----+-----+-----+------+-------------+
| *y* | 0   | ... | 0    | **0 → 1 ?** |
+-----+-----+-----+------+-------------+

At this point, the CellML model's interpretation is not defined.
The reset causing :code:`y = 1` and the mathematics :code:`y = 0` cannot both be true.
