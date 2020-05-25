.. _example_reset_misuse_infiniteloop:

Misuse: Infinite loop
---------------------

**Description**: It's possible to write valid CellML syntax that produces an invalid or meaningless outcome.
One such example is the use of resets to create infinite evaluation loops, where resets change a variable's value back and forth forever.

.. container:: shortlist

    Note that:

    - all elements are in the same component;
    - the order values of resets are not shown; and
    - all variables have dimensionless units.

.. code-block:: text

    component: InfiniteLoop
      ├─ math: 
      │   └─ ode(A, t) = 1
      │
      └─ variable: A initially 1
          ├─ reset: rule 1
          │   ├─ when A == 2
          │   └─ then A = 3
          │
          └─ reset: rule 2
              ├─ when A == 3
              └─ then A = 2

.. container:: toggle

    .. container:: header

        See CellML syntax

    .. code-block:: xml

        <variable name="t" units="dimensionless" />
        <variable name="A" units="dimensionless" initial_value="1" />

        <math>
            <apply><eq/>
                <diff>
                    <ci>A</ci>
                    <bvar>t</bvar>
                </diff>
                <cn cellml:units="dimensionless">1</cn>
            </apply>
        </math>

        <!-- Reset rule 1: -->
        <reset variable="A" test_variable="A">
            <test_value>
                <cn units="cellml:dimensionless">2</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">3</cn>
            </reset_value>
        </reset>

        <!-- Reset rule 2: -->
        <reset variable="A" test_variable="A">
            <test_value>
                <cn units="cellml:dimensionless">3</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">2</cn>
            </reset_value>
        </reset>

At :code:`t = 1` the following situation occurs:

+-----+---+---+
| *t* | 0 | 1 |
+-----+---+---+
| *A* | 1 | 2 |
+-----+---+---+

There is exactly one reset rule active for A, and its change gets applied:

+-----+---+-------+
| *t* | 0 | 1     |
+-----+---+-------+
| *A* | 1 | 2 → 3 |
+-----+---+-------+

Because the new point differs from the last, a second cycle of reset rule checking is started.
Again, a reset rule is active, and gets applied:

+-----+---+---------------+
| *t* | 0 | 1             |
+-----+---+---------------+
| *A* | 1 | 2 → 3 → 2 ... |
+-----+---+---------------+

Now we're back in the original situation where the first reset rule is active, and so reset rule evaluation continues ad infinitum.
Good software might, at this point, detect that (1) the new point equals the original point before reset evaluation, but (2) reset rule evaluation has not yet terminated.
This points to an infinite loop, and so perhaps a runtime error.
But note that, as with e.g. :code:`x = 1 / 0` there is nothing in CellML to prevent users writing these things down.
