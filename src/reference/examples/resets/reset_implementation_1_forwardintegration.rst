.. _example_reset_implementation_1:

Implementation: Forward integration
-----------------------------------

**Description:** This example shows two possible strategies to handle resets.
No particular method is prescribed (just as no method is prescribed for the solution of ODEs either).

.. container:: shortlist

    Note that:

    - all elements are in the same component;
    - the order values of resets are not shown; and
    - the units of variables are not shown.

.. code-block:: text

    component: ForwardIntegration
      ├─ math: 
      │    └─ ode(A, t) = 1
      │
      └─ variable: A initially 1 
          └─ reset: 
              ├─ when A == 3
              └─ then A = 1

.. container:: toggle

    .. container:: header

        See CellML syntax

    .. code-block:: xml

        <variable name="t" units="dimensionless" />
        <variable name="A" units="dimensionless" initial_value="1" />

        <!-- Reset rule 1: -->
        <reset variable="A" test_variable="A">
            <test_value>
                <cn units="cellml:dimensionless">3</cn>
            </test_value>
            <reset_value>
                <cn units="cellml:dimensionless">1</cn>
            </reset_value>
        </reset>


Near :code:`t = 1.9`, an integration step proceeds as normal: the derivatives :math:`f(x_1, t_1)` are calculated, and used to estimate a step :math:`(x_2, t_2)`.
The quantity :code:`A - 3` (test variable minus test value) is calculated and monitored for sign changes.

+---------+------+--------------+--+
| *t*     | 1.9  | Propose: 2.1 |  |
+---------+------+--------------+--+
| *A*     | 2.9  | Propose: 3.1 |  |
+---------+------+--------------+--+
| *A - 3* | -0.1 | Propose: 0.1 |  |
+---------+------+--------------+--+

After this step is proposed, the test variables are checked. Because the sign of :code:`A - 3` has changed, the integrator notices a discontinuity has occurred, and so the reset should be carried out as soon as possible.

To do this, the *reset value* is evaluated at :math:`(x_1, t_1)` - just like the *derivatives* were evaluated at :math:`(x_1, t_1)` earlier - and :math:`x_2` is updated to reflect this change:

+---------+------+--------------+-------------+
| *t*     | 1.9  | Propose: 2.1 | Accept: 2.1 |
+---------+------+--------------+-------------+
| *A*     | 2.9  | Propose: 3.1 | Accept: 1   |
+---------+------+--------------+-------------+
| *A - 3* | -0.1 | Propose: 0.1 |             |
+---------+------+--------------+-------------+

Variable time-step methods can try and *find* the discontinuity, for example they could use threshold crossing algorithms to find a better proposed step:

+---------+------+--------------+-------------+-------------+
| *t*     | 1.9  | Propose: 2.1 | Update: 2.0 | Accept: 2.0 |
+---------+------+--------------+-------------+-------------+
| *A*     | 2.9  | Propose: 3.1 | Update: 3   | Accept: 1   |
+---------+------+--------------+-------------+-------------+
| *A - 3* | -0.1 | Propose: 0.1 | Update: 0   |             |
+---------+------+--------------+-------------+-------------+
