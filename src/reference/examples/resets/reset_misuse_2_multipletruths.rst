.. _example_reset_misuse_multiple_truths:

Misuse: Multiple truths
-----------------------

**Description:** The behaviour specified in resets must complement the mathematics of the model; it does not over-ride it.
For this reason, models containing reset variables which are also present in maths statements are over-defined.
This is shown in the example below.

.. container:: shortlist

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
            └─ reset: rule 1
                ├─ when x == 100
                └─ then y = 1

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

+-----+-----+-----+------+-------------+
| *t* | 0.0 | ... | 99.9 | 100         |
+-----+-----+-----+------+-------------+
| *x* | 0   | ... | 99.9 | 100         |
+-----+-----+-----+------+-------------+
| *y* | 0   | ... | 0    | **0 → 1 ?** |
+-----+-----+-----+------+-------------+

At this point, the CellML model's interpretation is not defined.
The reset causing :code:`y = 1` and the mathematics :code:`y = 0` cannot both be true.

Suggestions
~~~~~~~~~~~

There is no workaround that will give the behaviour of the model as it is: the situation is not possible. 
However, it's probable that this occurred because you actually wanted a different behaviour:

- **Initial conditions:** If the line in the maths block stating that :math:`y=0` is intended to provide only an initial condition, you should remove it from the maths block.
  Statements here are held to be true for all time, so simple definitions such as :math:`a=1` lock the value of :math:`a` in stone: it cannot be changed by resets, by other mathematics, or by initial conditions.
  To initialise a variable whose value can be changed (including by a reset item) please use the :code:`initial_value` attribute on the variable instead.

- **Default conditions:** If the use of a reset on variable *y* is intended to be a temporary situation, active only when the reset conditions are met, then the mathematics :math:`y=0` should again be removed.
  Resets provide a one-way switch: in the case of the reset above this switch is from :math:`y=0→1`.
  To switch back the other way (making the condition temporary), simply provide a second reset, as shown below.

In any case, the using both maths and resets to set the value of a variable can lead to problems.
Use one, or the other, but not both!

  .. code-block:: text

    component: MultipleTruths
        ├─ math: 
        │   └─ x = t % 1000
        │          <------------- maths involving y is deleted
        │
        ├─ variable: x 
        └─ variable: y 
            ├─ reset: rule 1
            │   ├─ when x == 100
            │   └─ then y = 1
            │
            └─ reset: rule 2  <-------- reset to switch back is provided
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