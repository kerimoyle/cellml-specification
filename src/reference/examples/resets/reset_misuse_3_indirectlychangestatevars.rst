.. _reset_misuse_indirectlychangestatevars:

Misuse: Indirect change of state variables
------------------------------------------

**Description:** **TODO**

.. container:: shortlist

    Note that:

    - all elements are in the same component;
    - the order values of resets are not shown; and
    - the units of variables are not shown.

.. code-block:: text

    component: IndirectlyChangeStateVariables
      ├─ math: 
      │    ├─ ode(A, t) = 1
      │    └─ B = A
      │
      ├─ variable: A initially 1
      │
      └─ variable: B initially 0
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

This is similar to the previous case, but now the situation is solvable:

When :code:`B == 2`, *B* it must be reset to 1.
But since :code:`B = A` is specified in the :code:`math` block, then *A* must also be 1.
Since *A* is a state variable this is allowed.

However, in most implementations the code will get converted to assignments (e.g.: :code:`B := A`) before the system is solved.
Allowing this type of situation would mean solvers need to recognise potential situations like this and add an :code:`if (...) then B := A else A := B`.

(In addition, determining whether a situation like this does or does not have a solution has the potential to be difficult.)
