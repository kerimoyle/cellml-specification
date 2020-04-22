.. _units_guidelines_for_mathml:

.. container:: heading3

  Units guidelines for MathML operations

- :code:`eq`, :code:`neq`, :code:`gt`, :code:`lt`, :code:`geq`, :code:`leq`, :code:`and`, :code:`or`, :code:`xor`, :code:`not`

  - The result of these operators has units of cellml:boolean. **TODO**

- :code:`exp`, :code:`ln`, :code:`log`, :code:`factorial`, :code:`sin`, :code:`cos`, :code:`tan`, :code:`sec`, :code:`csc`, :code:`cot`, :code:`sinh`, :code:`cosh`, :code:`tanh`, :code:`sech`, :code:`csch`, :code:`coth`, :code:`arcsin`, :code:`arccos`, :code:`arctan`, :code:`arccosh`, :code:`arccot`, :code:`arccoth`, :code:`arccsc`, :code:`arccsch`, :code:`arcsec`, :code:`arcsech`, :code:`arcsinh`, :code:`arctanh`

  - The operand passed to these operators has units of dimensionless.
  - The result of these operators has units of dimensionless.
  
- :code:`plus`, :code:`minus`, :code:`abs`, :code:`floor`, :code:`ceiling`

  - The operands passed to these operators must have equivalent units.
  - The result of these operators has the same units as the operands.

- :code:`times`

  - The result of this operator has units that are the product of the units on the operands.
    This product may be simplified according to the rules outlined in **TODO**.
  
- :code:`divide`

  - The result of this operator has units that are the quotient of the units on the first and second operands.  
    This quotient may be simplified according to the rules outlined in **TODO**.
  
- :code:`power`

  - The second operand must have units of :code:`dimensionless`.
  - The result of this operator has units that are the units on the first operand raised to the power of the second operand.
  - If the first operand has units of :code:`dimensionless`, the result will as well.
  
- :code:`root`

  - The result of this operator has units that are the units on the first operand raised to the reciprocal of the value of the :code:`degree` qualifier element (the default value of which is 2.0).  
  - If the first operand has units of :code:`dimensionless`, the result will as well.                         
  
- :code:`diff`

  - The result of this operator has units that are the quotient of the units of the operand over the units of the term in the :code:`bvar` qualifier element raised to the value of the :code:`degree` qualifier element inside the :code:`bvar` qualifier element (the default value of which is 1.0).
  - This quotient may be simplified according to the rules outlined in **TODO**.









.. table :: MathML operations and units
  +------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------+
  | Operator                                                                                             | Argument and resulting units                                                                                |
  +------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------+
  | :code:`eq`, :code:`neq`, :code:`gt`, :code:`lt`, :code:`geq`,                                        | | The operands given to these operators should have equivalent units.                                       |
  | :code:`leq`, :code:`and`, :code:`or`, :code:`xor`, :code:`not`                                       | | The result of these operators has units of cellml:boolean. **TODO**                                       |
  |                                                                                                      |                                                                                                             |
  +------------------------------------------------------------------------------------------------------+-------------------------------------------------------------------------------------------------------------+
  | | :code:`exp`, :code:`ln`, :code:`log`, :code:`factorial`,                                           | | The operand passed to these operators has units of dimensionless.                                         |
  | | :code:`sin`, :code:`cos`, :code:`tan`, :code:`sec`, :code:`csc`, :code:`cot`,                      | | The result of these operators has units of dimensionless.                                                 |
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




