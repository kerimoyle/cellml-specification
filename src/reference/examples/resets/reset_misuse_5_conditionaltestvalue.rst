.. _example_reset_misuse_conditionaltestvalue:

Misuse: Conditional test value
------------------------------

**Description**: **TODO**

Note that:

- all elements are in the same component;
- the order values of resets are not shown; and
- all variables have dimensionless units.

.. code-block:: text

    component: ConditionalTestValue
        ├─ variable: x initially 0
        └─ variable: y initially 0 
            └─ reset: 
                ├─ when y == if t == 1 
                │              ├─ then 1
                │              └─ else 0
                └─ then y = 1

.. container:: toggle

    .. container:: header

        See CellML syntax

    .. code-block:: xml

        <variable name="t" units="dimensionless" />
        <variable name="x" units="dimensionless" initial_value="0" />
        <variable name="y" units="dimensionless" initial_value="0" />

        <reset variable="y" test_variable="x">
            <!-- The test value is conditional: -->
            <test_value>
                <piecewise>
                    <piece>
                        <!-- Conditional statement to decide the test value. -->
                        <apply><eq/>
                            <ci>t</ci>
                            <cn cellml:units="dimensionless">1</cn>
                        </apply>
                        <!-- If the condition is met, the test value is 0. -->
                        <cn cellml:units="dimensionless">0</cn>
                    </piece>
                    <otherwise>
                        <!-- If the condition above is not met, the test value is 10. -->
                        <cn cellml:units="dimensionless">10</cn>
                    </otherwise>
                </piecewise>
            </test_value>

            <!-- The reset value is constant: -->
            <reset_value>
                <cn cellml:units="dimensionless">1</cn>
            </reset_value>
        </reset>

It is valid, though probably not advisable, to use conditional statements (the MathML :code:`piecewise`, :code:`piece` and :code:`otherwise` items) when specifying a test value.
