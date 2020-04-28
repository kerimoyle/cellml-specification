.. _example_reset_misuse_conditionalresetvalue:

Misuse: Conditional reset value
-------------------------------

**Description**: **TODO**

.. container:: shortlist

    Note that:

    - all elements are in the same component;
    - the order values of resets are not shown; and
    - all variables have dimensionless units.

.. code-block:: text

    component: ConditionalResetValue
      ├─ math: 
      │   └─ x = sin(t*pi)
      │
      ├─ variable: x
      │
      └─ variable: y initially 0 
          └─ reset: 
              ├─ when x == 0
              └─ then if sin((t-0.1)*pi) < 0 
                          ├─ then y = 1
                          └─ else y = 0

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
                        <pi/>
                    </apply>
                </apply>
            </apply>
        </math>

        <reset variable="y" test_variable="x">
            <!-- The test value is constant: -->
            <test_value>
                <cn cellml:units="dimensionless">0</cn>
            </test_value>

            <!-- The reset value is decided based on:
                    if sin((t-0.1)*pi) < 0:
                        then reset_value = 1
                        else reset_value = 0 
            -->
            <reset_value>
                <piecewise>
                    <piece>
                        <!-- Conditional statement to decide the reset value. -->
                        <apply><lt/>
                            <apply><sin/>
                                <apply><times/>
                                    <apply><minus/>
                                        <ci>t</ci>
                                        <cn cellml:units="dimensionless">0.1</cn>
                                    </apply>
                                    <pi/>
                                </apply>
                            </apply>
                            <cn cellml:units="dimensionless">0</cn>
                        </apply>
                        <!-- If the condition is met, the reset value is 1. -->
                        <cn cellml:units="dimensionless">1</cn>
                    </piece>
                    <otherwise>
                        <!-- If the condition above is not met, the reset value is 0. -->
                        <cn cellml:units="dimensionless">0</cn>
                    </otherwise>
                </piecewise>
            </reset_value>
        </reset>

It is valid, though probably not advisable, to use conditional statements (the MathML :code:`piecewise`, :code:`piece` and :code:`otherwise` items) when specifying a reset value.
