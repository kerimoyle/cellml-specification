.. _example_reset_preamble:

Preamble
--------

This document is not part of the CellML specification.
It gives a suggested interpretation of resets, and involves adding some rules and restrictions on the mathematics described by a CellML document.
It is perfectly valid for a CellML model to break these rules / go beyond these restrictions.
In this case, the interpretation given here may not hold.

For the purposes of this document, we use the term "variable" to mean "the mathematical variable represented by a connected variable set").
A model's variables can be divided into four sets:

- The variable or variables of integration, :math:`t`.
  These are defined as all variables which appear inside the MathML :code:`<bvar>` element inside a :code:`<diff>`.
- The state variables, :math:`x`. 
  These are defined as all variables for which an initial value is defined. 
- The constant variables (or parameters), :math:`p`.
  These are all variables which are not in *(x, t)*, and whose value does not depend on any other variable.
- The derived variables, :math:`z`. 
  The variables that are not in :math:`(x, t, p)`.

Some extra restrictions
~~~~~~~~~~~~~~~~~~~~~~~

- None of the variables can have boolean values.
- The variables in :math:`t` must not be constrained by the model equations or resets: they must be free variables.
- Any variable for which a derivative is used (i.e.: the variables in a :code:`<diff>` but not in its :code:`<bvar>`) must define an initial value.
- The model must not be overdefined or underdefined.
- The sets *t, x, z,* and :math:`p` must not overlap.

Note that, while some of the most biologically interesting variables are found be in z, for the purposes of evaluating the system trajectory they are simply functions of :math:`(x, t, p)`, so for the sake of clarity we can omit them and could, for example, specify a function of the model's state as *f(x, t, p)* instead of *f(x, t, p, g(x, t, p))*.
