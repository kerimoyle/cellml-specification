.. _example_reset_misuse_conditionaltestvalue:

Misuse: Conditional test value
------------------------------

**Description**: Similar to the :ref:`conditional reset value<example_reset_misuse_conditionalresetvalue>` situation, the use of conditional statements in the test value is valid CellML, but should be avoided.

The use of conditional statements in the test value is valid CellML, but should be avoided if those conditional statements introduce discontinuities.
The :code:`reset` elements are intended to alert the solver to the presence of a discontinuity in a CellML model, and to provide information on how that discontinuity should be interpreted (especially in the presence of other, possibly conflicting conditions).
Hiding a discontinuity *within* the reset defeats its purpose, as well as being a very difficult case for solvers to handle reliably (like :math:`x = 3e99999 + y - 2e99999 - 1e99999` is mathematically valid but unlikely to be computed well).

Consider the example below.

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

.. 
  From Michael: 
  The why is that it's very hard to detect.
  In the example, at t=0.999 the test condition is
  y == (1 if t == 1 else 0), so effectively "when y == 0", aka "when y - 0 has a root"
  At t=1.001 the test condition is
  y == (1 if t == 1 else 0), so effectively "when y == 0", aka "when y - 0 has a root"
  The "aka" bit is how root-finding algorithms would formulate this: monitor "y - test-value" and see if it changes sign at any point, then zoom in on that area to find the root.
  But a program trying to find a change in the sign of y - test-value = y - (1 if t == 1 else 0) wouldn't pick this up.
  Instead, you'd have to do some kind of symbolical analysis to work out that it's a change at t=1, regardless of the rest of the system.
  So it's valid CellML, but unlikely to lead to the correct result in practice. A bit like Exactly like writing e.g. x = 3e99999 + y - 2e99999 - 1e99999. It's valid CellML, and mathematically fine, but tools probably won't give you the right result


Suggestions
~~~~~~~~~~~
Simply by moving the conditional statement from the test value and into a variable in the maths block gets around the problem; the discontinuity is visible to the solver.
Since the resets will be applied after the mathematics is evaluated, the interpretation of the discontinuity is clear and straightforward.

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
