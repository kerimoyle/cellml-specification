.. _units_guidelines_for_mathml:

.. container:: heading3

  Units guidelines for MathML operations

- :code:`eq`, :code:`neq`, :code:`gt`, :code:`lt`, :code:`geq`, :code:`leq`, :code:`and`, :code:`or`, :code:`xor`, :code:`not`

  - The inputs to these operators should have equivalent units.
  - The result of these operators is not a number with a unit, but one of the logical constants :code:`true` or :code:`false`. 
    These constants can be used as the second ordinand of the :code:`piece` operator, but cannot be used as input to operators expecting a numerical type.

- :code:`piecewise`

  - The inputs consist of :code:`piece` and :code:`otherwise` elements which have units as described in those sections.
  - The output of this operator has units given by the selected :code:`piece` or :code:`otherwise` element child.

- :code:`piece`, (:code:`otherwise`)

  - The first input may have any units.
  - The second input is a relational statement, which does not have units.
  - The output of each operator has the same units as their first inputs.

- :code:`exp`, :code:`exponentiale`, :code:`ln`, :code:`log`, :code:`logbase`

  - The input of each operator must have units of :code:`dimensionless`.
  - The output of each operator has units of :code:`dimensionless`.

- :code:`sin`, :code:`cos`, :code:`tan`, :code:`sec`, :code:`csc`, :code:`cot`, :code:`sinh`, :code:`cosh`, :code:`tanh`, :code:`sech`, :code:`csch`, :code:`coth`, :code:`arcsin`, :code:`arccos`, :code:`arctan`, :code:`arccosh`, :code:`arccot`, :code:`arccoth`, :code:`arccsc`, :code:`arccsch`, :code:`arcsec`, :code:`arcsech`, :code:`arcsinh`, :code:`arctanh`

  - The input of each operator must have units of :code:`dimensionless`.
  - The output of each operator has units of :code:`dimensionless`.
  
- :code:`plus`, :code:`minus`, :code:`min`, :code:`max`

  - The inputs of each operator must have equivalent units.
  - The output of each operator has the same units as its inputs.

- :code:`abs`, :code:`floor`, :code:`ceiling`

  - The inputs may have any units.
  - The output of each operator has the same units as its input.

- :code:`times`

  - The inputs may have any units.
  - The output has units given by the product of the units of the inputs.
    This product may be simplified as long as the unit reduction is maintained (see :numref:`3.3.3 in {number} {name}<specC_interpretation_of_units>`).

.. hardcodedref above, 3.3.3
  
- :code:`divide`, :code:`rem`

  - The inputs may have any units.
  - The output of each operator has units given by the quotient of the units on the first and second inputs.  
    This quotient may be simplified as long as the unit reduction is maintained (see :numref:`3.3.3 in {number} {name}<specC_interpretation_of_units>`).

.. hardcodedref above, 3.3.3
  
- :code:`power`

  - The first input may have any units.
  - The second input must have units of :code:`dimensionless`.
  - The output has units given by the units of the first input raised to the power of the second input.
  - If the first input has units of :code:`dimensionless`, the output units are :code:`dimensionless` as well.
  
- :code:`root`, (:code:`degree`)

  - The first input may have any units.
  - The :code:`degree` element, if present, must have units of :code:`dimensionless`.
  - The output has units given by the units on the first input raised to the reciprocal of the value of the :code:`degree` qualifier element (the default value of which is 2.0).  
  - If the first input has units of :code:`dimensionless`, the output units are :code:`dimensionless` as well.
  
- :code:`diff`, (:code:`bvar`, :code:`degree`)

  - The input may have any units.
  - The output has units that are the quotient of the units of the input over the units of the term in the :code:`bvar` qualifier element raised to the value of the :code:`degree` qualifier element inside the :code:`bvar` qualifier element (the default value of which is 1.0).
    This quotient may be simplified as long as the unit reduction is maintained (see :numref:`3.3.3 in {number} {name}<specC_interpretation_of_units>`).

.. hardcodedref above, 3.3.3


.. table :: MathML operations and units
  +------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------+
  | Operator                                                                                             | Argument and resulting units                                                                                |
  +------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------+
  | :code:`eq`, :code:`neq`, :code:`gt`, :code:`lt`, :code:`geq`,                                        | | The operands given to these operators should have equivalent units.                                       |
  | :code:`leq`, :code:`and`, :code:`or`, :code:`xor`, :code:`not`                                       | | The result of these operators has units of cellml:boolean. **TODO**                                       |
  |                                                                                                      |                                                                                                             |
  +------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------+
  | | :code:`exp`, :code:`ln`, :code:`log`, :code:`factorial`,                                           | | The operand passed to these operators has units of :code:`dimensionless`.                                         |
  | | :code:`sin`, :code:`cos`, :code:`tan`, :code:`sec`, :code:`csc`, :code:`cot`,                      | | The result of these operators has units of :code:`dimensionless`.                                                 |
  | | :code:`sinh`, :code:`cosh`, :code:`tanh`, :code:`sech`, :code:`csch`, :code:`coth`,                |                                                                                                             |
  | | :code:`arcsin`, :code:`arccos`, :code:`arctan`, :code:`arccosh`, :code:`arccot`, :code:`arccoth`,  |                                                                                                             |
  | | :code:`arccsc`, :code:`arccsch`, :code:`arcsec`, :code:`arcsech`, :code:`arcsinh`, :code:`arctanh` |                                                                                                             |
  +------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------+
  | :code:`plus`, :code:`minus`, :code:`abs`, :code:`floor`, :code:`ceiling`                             | | The operands passed to these operators must have equivalent units.                                        |
  |                                                                                                      | | The result of these operators has the same units as the operands.                                         |
  |                                                                                                      |                                                                                                             |
  +------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------+
  | :code:`times`                                                                                        | The result of this operator has units that are the product of the units on the operands.                    |
  |                                                                                                      | This product may be simplified according to the rules outlined in **TODO**.                                 |
  +------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------+
  | :code:`divide`                                                                                       | The result of this operator has units that are the quotient of the units on the first and second operands.  |
  |                                                                                                      | This quotient may be simplified according to the rules outlined in **TODO**.                                |
  +------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------+
  | :code:`power`                                                                                        | | The second operand must have units of :code:`dimensionless`.                                              |
  |                                                                                                      | | The result of this operator has units that are the units on the first operand raised                      |
  |                                                                                                      |   to the power of the second operand.                                                                       |
  |                                                                                                      |                                                                                                             |
  |                                                                                                      | | If the first operand has units of :code:`dimensionless`, the result will as well.                         |
  |                                                                                                      |                                                                                                             |
  +------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------+
  | :code:`root`                                                                                         | | The result of this operator has units that are the units on the first operand raised to                   |
  |                                                                                                      |   the reciprocal of the value of the :code:`degree` qualifier element (the default value of which is 2.0).  |
  |                                                                                                      |                                                                                                             |
  |                                                                                                      | | If the first operand has units of :code:`dimensionless`, the result will as well.                         |
  |                                                                                                      |                                                                                                             |
  +------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------+
  | :code:`diff`                                                                                         | The result of this operator has units that are the quotient of the units of the operand over                |
  |                                                                                                      | the units of the term in the :code:`bvar` qualifier element raised to the value of the :code:`degree`       |
  |                                                                                                      | qualifier element inside the :code:`bvar` qualifier element (the default value of which is 1.0).            |
  |                                                                                                      | This quotient may be simplified according to the rules outlined in **TODO**.                                |
  +------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------+




