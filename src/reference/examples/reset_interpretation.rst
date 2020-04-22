.. _example_reset_interpretation:

Interpretation
--------------

CellML models define two functions:

#. *f(x, t, p) → fx* calculates the system derivatives *fx* at any point *(x, t, p)*. 
   Note that x contains variables for which an initial value, but no derivative, was defined. 
   For these variables fx is zero.

#. *g(x, t, p) → (x', t, p)* is a discontinuous mapping from one or more points *(x, t, p)* to points *(x', t, p)*.
   Note that g can only change the values of *x*. 
   The values of variables in p are already fixed by model equations, while we posited above that *t* is not constrained by the model equations or resets.

The first function, *f(x, t, p) → fx*, is defined by the equations in the model. 
The second function, *g(x, t, p) → (x', t, p)*, is defined by the collection of reset rules in the model. 
Note that both parts are optional: a user can supply *f, g,* both, or neither.

When started at some initial point *(x0, t0, p0)*, the derivatives in *f* describe the system’s trajectory through *(x, t, p)*-space. 
Reset rules add the ability to specify *some* values *(x, t, p)* for which the system should instantaneously jump. 
This is illustrated below, where a trajectory (black line) is interrupted at point *(x, t, p)* by a discontinuous jump (dashed line) to *(x', t, p)*.

.. todo : image to go here

Multiple reset rules can act together: *g* is a composite function
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

It is important to note that *g* is defined by all reset rules in the model (including those from imported parts).
An individual reset rule is triggered whenever the value of its test variable (some function of *(x, t, p)*) equals its test value (another function of *(x, t, p)*).
At that point, the value of its reset variable (the variable referenced in the :code:`variable` attribute) should be updated to the reset value. 
If multiple reset rules apply to the same reset variable (which must be in either *x* or *p*) at the same point *(x, t, p)*, only the rule with the lowest order attribute will be triggered. The procedure below can be used to determine the jump occurring at a point *(x, t, p)* :

#. For each reset rule, determine if it’s active by checking if its test variable’s value matches the test value at *(x, t, p)*.

   #. If more than one reset rule holds for the same reset variable, only the rule with the lowest order is held to be active for that reset variable.
   
#. For each active reset rule, calculate the specified change, using the values *(x, t, p)* to perform any calculation of new values.
#. For each active reset rule, apply the calculated change.
#. If the system is now in a new point *(x', t, p) != (x, t, p)*: 

   #. Then let *(x, t, p) := (x’, t, p)* and repeat, starting from step 1. 
   #. If not, return the new *(x, t, p)*.

Note that:

- Reset rule evaluation can consist of multiple cycles through steps 1-4.
- For each cycle, all reset rules are tested before any changes are made.
- For each cycle, because only one reset rule can hold per variable, changes to the system state are orthogonal (see figure below); this ensures that the order in which the rules are applied does not matter.
- It is entirely possible for the user to specify infinite loops using reset rules, e.g. by having the effects of one rule undoing the effects of a previous one.

.. todo : image goes here

Finding the points *(x, t, p)*
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Because it is highly unlikely for a simulated trajectory to include a point *(x, t, p)* exactly, solvers must check if they have passed such a point, e.g. by checking if the sign of (test_variable - test_value) has changed. 
If this occurs, it is up to the solver to decide whether to treat the current point as the discontinuity (inexact), or to backtrack and try to find the threshold crossing point exactly.
A graphical example of a “lazy” implementation is given below.

.. todo: image

A particularly difficult case occurs if a reset rule is defined in such a way that (test_variable - test_value) can pass through a root without changing sign (e.g. a reset when *sin(t) == 1*):

.. todo: image

Using this type of reset rule in a simulation may lead to unexpected results, so - like dividing by zero or using reset rules to create infinite loops - is probably best avoided.
