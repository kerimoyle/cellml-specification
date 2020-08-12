.. _example_reset_usecase_2:

Usecase: Stimulus current with offset
-------------------------------------

**Description:** Many :pmr:`electrophysiology<electrophysiology>` models contain statements such as: :code:`I_stim = stim_amplitude if (time % 1000 < 2) else 0`.
These statements encode discontinuities directly into the mathematics (at t=0, t=1000, t=2000,... and at t=2, t=1002, t=2002, ...), and so can be replaced by reset statements.

.. code-block:: text

    component: StimulusCurrentWithOffset
      ├─ math: 
      │   └─ x = t % 1000
      │
      ├─ variable: x 
      │
      └─ variable: y, initially 0
          ├─ reset: rule 1
          │   ├─ when x == 100
          │   └─ then y = 1
          │
          └─ reset: rule 2 
              ├─ when x == 101
              └─ then y = 0

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
    #. The reset value for rule 1 is applied to :code:`y`.
    #. The system is now in a new state: :math:`(x^\prime, t, p) \neq (x, t, p)` (note that :math:`y` is included in :math:`x`), we restart at step 1.

- **Cycle**

    1. Since it is still true that :code:`x == 100`, rule 1 is still active.
    2. The reset value is calculated,
    3. And applied.
    4. The state hasn't changed: :math:`(x^\prime, t, p) = (x, t, p)`, so reset rule 1 processing halts.

- **Cycle** 

    1. At :code:`t = 101` we detect that :code:`x == 101`, so rule 2 becomes active.
    2. The reset value for rule 2 is calculated to be 0.
    3. The reset value for rule 2 is applied to :code:`y`.
    4. The system is now in a new state: :math:`(x^\prime, t, p) \neq (x, t, p)`, so restart.

- **Cycle**

    1. Since it is still true that :code:`x == 101`, rule 2 is still active.
    2. The reset value is calculated,
    3. And applied.
    4. The state hasn't changed: :math:`(x^\prime, t, p) = (x, t, p)`, so reset rule 2 processing halts.
