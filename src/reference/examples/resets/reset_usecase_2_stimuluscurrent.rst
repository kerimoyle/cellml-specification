.. _example_reset_usecase_2:

Usecase 2: Stimulus current with offset
---------------------------------------

**Description:** **TODO**

.. code-block:: text

    component: UseCase2
        math: x = t % 1000
        variable: x 
        variable: y, initially 0
        reset: rule 1
            when x == 100
            then y = 1
        reset: rule 2 
            when x == 101
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
                <cn units="cellml:dimensionless">100</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">1</cn>
            </reset_value>
        </reset>

        <!-- Reset rule 2: -->
        <reset variable="y" test_variable="x">
            <test_value>
                <cn units="cellml:dimensionless">101</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">0</cn>
            </reset_value>
        </reset>

+-----+-----+-----+------+-------+-----+-------+-------+
| *t* | 0.0 | ... | 99.9 | 100   | ... | 100.9 | 101   |
+-----+-----+-----+------+-------+-----+-------+-------+
| *x* | 0   | ... | 99.9 | 100   | ... | 100.9 | 101   |
+-----+-----+-----+------+-------+-----+-------+-------+
| *y* | 0   | ... | 0    | 0 → 1 | ... | 1     | 1 → 0 | 
+-----+-----+-----+------+-------+-----+-------+-------+

.. container:: heading4

    Processing steps

- **Cycle**

    1. At :code:`t = 100` we detect that :code:`x == 100`, so rule 1 becomes active.
    #. The reset value for rule 1 is calculated to be 1.
    #. The reset value for rule 1 is applied.
    #. The system is now in a new state: :math:`(x^\prime, t, p^\prime) \neq (x,t,p)` (note that y is included in p), we restart at step 1.

- **Cycle**

    1. Since it is still true that :code:`x == 100`, rule 1 is still active.
    2. The reset value is calculated,
    3. And applied.
    4. The state hasn’t changed: :math:`(x^\prime, t, p^\prime) = (x,t,p)`, so reset rule 1 processing halts.

- **Cycle** 

    1. At :code:`t = 101` we detect that :code:`x == 101`, so rule 2 becomes active.
    2. The reset value for rule 2 is calculated to be 0.
    3. The reset value for rule 2 is applied.
    4. The system is now in a new state: :math:`(x^\prime, t, p^\prime) \neq (x,t,p)`, so restart.

- **Cycle**

    1. Since it is still true that :code:`x == 101`, rule 2 is still active.
    2. The reset value is calculated,
    3. And applied.
    4. The state hasn’t changed: :math:`(x^\prime, t, p^\prime) = (x,t,p)`, so reset rule 2 processing halts.
