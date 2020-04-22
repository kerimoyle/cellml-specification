.. example_reset_usecase_1:

Use Case 1: Cell growth
-----------------------

Here, *A* represents the size of a cell, which grows until it reaches a threshold size and then divides.

.. code::

    component: UseCase1
        math: ode(A, t) = 1
        variable: A, initially 1
        reset:
            when A equals 2
            then set A to 1

.. container:: toggle

    .. container:: header

        See CellML syntax

    .. code-block:: xml

        <variable name="A" initial_value="1" units="dimensionless" />
        <reset variable="A" test_variable="A">
            <test_value>
                <cn units="cellml:dimensionless">2</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">1</cn>
            </reset_value>
        </reset>

+-----+-----+-----+-----+-----+-------+-----+-----+
| *t* | 0.0 | ... | 0.8 | 0.9 | 1.0   | 1.1 | 1.2 |
+-----+-----+-----+-----+-----+-------+-----+-----+
| *A* | 1.1 | ... | 1.8 | 1.9 | 2 → 1 | 1.1 | 1.2 |
+-----+-----+-----+-----+-----+-------+-----+-----+

1. At :math:`t=1.0` we detect that :math:`A==2`, so the reset rule becomes active.
2. The reset value is calculated to be 1.
3. The reset value is applied
4. The system is now in a new state :math:`(x’,t,p’)!=(x,t,p)` (note that A is included in x), we restart at step 1
1. No reset rules are active, so evaluation halts
