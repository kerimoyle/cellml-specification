.. _example_reset_usecase_1:

Usecase: Cell growth and division
---------------------------------

**Description:** In this example, *A* represents the size of a cell, which grows until it reaches a threshold size and then divides.

.. code-block:: text

    component: CellGrowthAndDivision
      ├─ math: ode(A, t) = 1
      └─ variable: A, initially 1
          └─ reset:
              ├─ when A == 2
              └─ then A = 1

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

.. table::

    +-----+-----+-----+-----+-----+-------+-----+-----+
    | *t* | 0.0 | ... | 0.8 | 0.9 | 1.0   | 1.1 | 1.2 |
    +-----+-----+-----+-----+-----+-------+-----+-----+
    | *A* | 1.1 | ... | 1.8 | 1.9 | 2 → 1 | 1.1 | 1.2 |
    +-----+-----+-----+-----+-----+-------+-----+-----+

.. container:: heading4

    Processing steps

- **Cycle 1**:

    1. At :code:`t = 1.0` we detect that :code:`A == 2`, so the reset rule becomes active.
    2. The reset value is calculated to be 1.
    3. The reset value is applied.
    4. The system is now in a new state :math:`(x^\prime, t, p) \neq (x, t, p)` (note that :math:`A` is included in :math:`x`), we restart at step 1.

- **Cycle 2**:

    1. No reset rules are active, so evaluation halts.
