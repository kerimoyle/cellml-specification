.. _example_reset_misuse_conditionaltestvalue:

Misuse: Conditional test value
------------------------------

**Description**: Similar to the :ref:`conditional reset value<example_reset_misuse_conditionalresetvalue>` situation, the use of conditional statements in the test value may be valid CellML, but should be avoided.
**TODO** why??

.. container:: shortlist

    Note that:

    - all elements are in the same component;
    - the order values of resets are not shown; and
    - all variables have dimensionless units.

.. code-block:: text

    component: ConditionalTestValue
      ├─ variable: t
      ├─ variable: x initially 0
      └─ variable: y initially 0 
          └─ reset: 
              ├─ when y == (if t == 1 then 1 else 0)
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
Alternative approaches which avoid this are shown below.

Suggestions
~~~~~~~~~~~
Simply by moving the conditional statement from the test value and into a variable in the maths block gets around the problem.
**TODO** really?? What is the problem actually?? Shouldn't it be addressed with other resets so that we can use the order to decide how they behave??

.. code-block:: text

  component: AvoidConditionalTestValue
    ├─ variable: t
    ├─ variable: x initially 0
    ├─ variable: y initially 0 
    │   └─ reset: 
    │       ├─ when y == r
    │       └─ then y = 1
    ├─ variable: r
    │
    └─ math: 
        └─ r = (if t == 1 then 1 else 0)

.. container:: toggle

  .. container:: header

    See CellML syntax

  .. code-block:: xml

    <variable name="t" units="dimensionless" />
    <variable name="x" units="dimensionless" initial_value="0" />
    <variable name="y" units="dimensionless" initial_value="0" />

    <!-- Adding a dummy variable to transfer the conditional statement to: -->
    <variable name="r" units="dimensionless" />

    <reset variable="y" test_variable="x">
      <!-- The test value is no longer conditional. -->
      <test_value>
        <ci>r</ci>
      </test_value>
      <reset_value>
        <cn cellml:units="dimensionless">1</cn>
      </reset_value>
    </reset>

    <!-- Moving the conditional statement into the MathML block, setting
         the value to the new dummy variable: -->
    <math>
      <apply>
        <eq/>
        <ci>r</ci>
        <piecewise>
          <piece>
            <!-- Conditional statement to decide the test value. -->
            <apply>
              <eq/>
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
      </apply>
    </math>