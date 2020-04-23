.. _example_reset_usecase_3:

Use Case 3: Reset at initial point
----------------------------------

**Description:** **TODO**

Note that:

- all elements are in the same component;
- the order values of resets are not shown;
- the units of variables are not shown;
- the initial conditions hold when :code:`t = 0`.

.. code-block:: text

    component: UseCase3
        math: x = t % 1000
        variable: x 
        variable: y, initially 0
        reset: rule 1
            when x == 0
            then y = 1
        reset: rule 2 
            when x == 1
            then y = 0

.. container:: toggle

    .. container:: header

        See CellML syntax

    .. code-block:: xml

        <variable name="t" units="dimensionless" />
        <variable name="x" units="dimensionless" />
        <variable name="y" units="dimensionless" initial_value="0" />

        <!-- Reset rule 1: -->
        <reset variable="y" test_variable="x">
            <test_value>
                <cn units="cellml:dimensionless">0</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">1</cn>
            </reset_value>
        </reset>

        <!-- Reset rule 2: -->
        <reset variable="y" test_variable="x">
            <test_value>
                <cn units="cellml:dimensionless">1</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">0</cn>
            </reset_value>
        </reset>

+---+-------+-----+-----+-----+-------+-----+-----+
| t | 0.0   | 0.1 | ... | 0.9 | 1.0   | 1.1 | ... |
+---+-------+-----+-----+-----+-------+-----+-----+
| x | 0     | 0.1 | ... | 0.9 | 1.0   | 1.1 | ... |
+---+-------+-----+-----+-----+-------+-----+-----+
| y | 0 → 1 | 1   | ... | 1   | 1 → 0 | 0   | ... |
+---+-------+-----+-----+-----+-------+-----+-----+

.. container:: heading4

    Processing steps

- **Cycle**

    1. At :code:`t = 0` we detect that :code:`x == 0`, so rule 1 becomes active.
    #. The reset value for rule 1 is calculated to be 1.
    #. The reset value for rule 1 is applied to :code:`y`.
    #. The system is now in a new state: :math:`(x^\prime, t, p^\prime) \neq (x,t,p)`, we restart at step 1.

- **Cycle**

    1. Since it is still true that :code:`x == 0`, rule 1 is still active.
    2. The reset value is calculated,
    3. And applied.
    4. The state hasn’t changed: :math:`(x^\prime, t, p^\prime) == (x,t,p)`, so reset rule 1 processing halts.

- **Cycle** 

    1. At :code:`t = 1` we detect that :code:`x == 1`, so rule 2 becomes active.
    2. The reset value for rule 2 is calculated to be 1.
    3. The reset value for rule 2 is applied tp :code:`y`.
    4. The system is now in a new state: :math:`(x^\prime, t, p^\prime) \neq (x,t,p)`, so restart.

- **Cycle**

    1. Since it is still true that :code:`x == 1`, rule 2 is still active.
    2. The reset value is calculated,
    3. And applied.
    4. The state hasn’t changed: :math:`(x^\prime, t, p^\prime) == (x,t,p)`, so reset rule 2 processing halts.
