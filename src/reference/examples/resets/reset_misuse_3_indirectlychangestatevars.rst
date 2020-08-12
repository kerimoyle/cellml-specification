.. _reset_misuse_indirectlychangestatevars:

Misuse: Indirect change of state variables
------------------------------------------

**Description:** Resets applied at :math:`(x, t, p)` can only change the variables in :math:`x`.
This includes state variables, and variables which have been initialised using the :code:`initial_value` attribute and whose value is not determined through any of the mathematical equations given.
This example shows the valid case of where the mathematical equation may - depending on the implementation - covertly change a state variable.

.. container:: shortlist

    Note that:

    - all elements are in the same component;
    - the order values of resets are not shown; and
    - the units of variables are not shown.

.. code-block:: text

    component: IndirectlyChangeStateVariables
      ├─ math: 
      │   ├─ ode(A, t) = 1
      │   └─ B = A
      │
      ├─ variable: A initially 1
      │
      └─ variable: B
          └─ reset: 
              ├─ when B == 2
              └─ then B = 1

.. container:: toggle

    .. container:: header

        See CellML syntax

    .. code-block:: xml

        <variable name="t" units="dimensionless" />
        <variable name="A" units="dimensionless" initial_value="1"/>
        <variable name="B" units="dimensionless" />

        <math>
            <apply><eq/>
                <diff>
                    <ci>A</ci>
                    <bvar>t</bvar>
                </diff>
                <cn cellml:units="dimensionless">1</cn>
            </apply>
        </math>

        <reset variable="B" test_variable="B">
            <test_value>
                <cn units="cellml:dimensionless">1</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">2</cn>
            </reset_value>
        </reset>

This is similar to :ref:`the previous case<example_reset_misuse_multiple_truths>`, but now the situation could perhaps be solvable:

- Initially, both *A* and *B* are 1.
- As the solution progresses, the solved value for *A* is given as the value for *B* because of the equality :math:`B=A` in the maths block.
- When :code:`B == 2`, the reset is triggered and *B* is reset to 1.

Thus it's unclear whether different implementations and solvers would show consistent behaviour, and this kind of model formulation is better avoided.

.. 
    This is where the ambiguity arises.
    The equality statement in the maths block of :math:`B=A` would commonly be turned into an assignment statement when implemented in code.
    The trouble is which of the values (that of *A* or that of *B*) will be changed to make sure the equality remains.
    The one-way property of the assignment (that :code:`B:=A` has the ability to change the value of *B*, but not the value of *A*) is different from the two-way property of the equality (that *A* and *B* are always the same), and so more information is needed before the behaviour of the model is unambiguous.

+-----+-----+-----+------+---------+
| *t* | 0.0 | ... | 1    |         |
+-----+-----+-----+------+---------+
| *A* | 1   | ... | 2    | ?       |
+-----+-----+-----+------+---------+
| *B* | 1   | ... | 2    | 1 → 2   |
+-----+-----+-----+------+---------+

(In addition, determining whether a situation like this does or does not have a solution has the potential to be difficult.)

Suggestions
~~~~~~~~~~~
Since the issue arises in the interpretation of the reset and mathematics into code, that is where the solution lies also.
In most implementations the equality :math:`=` will be converted to an assignment (e.g.: :code:`B := A`) before the system is solved.
In turn, this means that the system is not over-defined, and solution is possible.
Allowing this type of situation would mean solvers need to recognise potential situations like this and add statements which decide which direction of the assignment should be followed:

.. code::

    if (some condition):
        then: assign the value of A to B
        else: assign the value of B to A
