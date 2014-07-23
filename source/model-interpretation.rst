Interpretation of CellML models
===============================

Interpretation of imports
-------------------------

1. Each ``import`` element present in a CellML infoset (the importing
   infoset) SHALL define a new and separate instance of the CellML
   infoset referenced by the ``href`` attribute (the imported infoset).

2. The following ``component`` elements SHALL be "pertinent component
   elements":

   a. All ``component`` elements in the top-level CellML infoset for the
      CellML model;

   b. All ``component`` elements referenced by ``import component``
      elements in the top-level CellML infoset; and

   c. All ``component`` elements which are descendants in the encapsulation
      digraph of a pertinent ``component`` element.

.. _units-reference:

Units reference
---------------

1. A units reference SHALL be a CellML identifier, and SHALL be
   interpreted based on the context within the CellML model in which it
   occurs.

2. A CellML infoset MUST NOT contain a units reference to which all
   scoping rules are inapplicable.

3. Where more than one of the units scoping rules apply, the applicable
   rule which appears first in this specification SHALL be used.

4. The units scoping rules are as follows:

   a. Where a units reference appears in an information item which is
      descended from a ``component`` element, and there is a ``units`` element
      child of that ``component`` element with a ``name`` attribute identical to
      the units reference, then the units reference SHALL refer to that
      ``units`` element.

   b. Where a units reference appears in an information item which is
      descended from the ``model`` element, and there is a ``units`` element
      child of that ``model`` element with a ``name`` attribute identical to the
      units reference, then the units reference SHALL refer to that
      ``units`` element.

   c. Where there is an ``import units`` element in the CellML infoset, such
      that the ``import units`` element has a ``name`` attribute identical to
      the units reference, then the units reference SHALL be treated as
      if the units reference appeared in the imported model, and
      referred to the name specified in the ``units_ref`` attribute of the
      ``import units`` element.

   d. Where the units reference is equal to a cell in the name column of
      the :ref:`built-in-units` table, then the units reference SHALL be
      a reference to the built-in unit corresponding to that row of the table.

.. _built-in-units:

.. table:: Built-in units

   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | Name          | Base unit? | Multiplier and dimensions in terms of base units                                 | Offset from base units |
   +===============+============+==================================================================================+========================+
   | ampere        | yes        | `-`                                                                              | `-`                    |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | becquerel     | no         | :math:`1 \cdot second^{-1}`                                                      | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | candela       | yes        | `-`                                                                              | `-`                    |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | celsius       | no         | :math:`1 \cdot kelvin`                                                           | :math:`273.15`         |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | coulomb       | no         | :math:`1 \cdot second \cdot ampere`                                              | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | dimensionless | no         | :math:`1`                                                                        | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | farad         | no         | :math:`1 \cdot metre^{-2} \cdot kilogram^{-1} \cdot second^{4} \cdot ampere^{2}` | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | gram          | no         | :math:`10^{-3} \cdot kilogram`                                                   | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | gray          | no         | :math:`1 \cdot metre^{2} \cdot second^{-2}`                                      | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | henry         | no         | :math:`1 \cdot metre^{2} \cdot kilogram \cdot second^{-2} \cdot ampere^{-2}`     | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | hertz         | no         | :math:`1 \cdot second^{-1}`                                                      | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | joule         | no         | :math:`1 \cdot metre^{2} \cdot kilogram \cdot second^{-2}`                       | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | katal         | no         | :math:`1 \cdot second^{-1} \cdot mole`                                           | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | kelvin        | yes        | `-`                                                                              | `-`                    |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | kilogram      | yes        | `-`                                                                              | `-`                    |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | liter         | no         | :math:`10^{-3} \cdot metre^{3}`                                                  | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | litre         | no         | :math:`10^{-3} \cdot metre^{3}`                                                  | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | lumen         | no         | :math:`1 \cdot candela`                                                          | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | lux           | no         | :math:`1 \cdot metre^{-2} \cdot candela`                                         | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | meter         | no         | :math:`1 \cdot metre`                                                            | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | metre         | yes        | `-`                                                                              | `-`                    |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | mole          | yes        | `-`                                                                              | `-`                    |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | newton        | no         | :math:`1 \cdot metre \cdot kilogram \cdot second^{-2}`                           | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | ohm           | no         | :math:`1 \cdot metre^{2} \cdot kilogram \cdot second^{-3} \cdot ampere^{-2}`     | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | pascal        | no         | :math:`1 \cdot metre^{-1} \cdot kilogram \cdot second^{-2}`                      | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | radian        | no         | :math:`1`                                                                        | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | second        | yes        | `-`                                                                              | `-`                    |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | siemens       | no         | :math:`1 \cdot metre^{-2} \cdot kilogram^{-1} \cdot second^{3} \cdot ampere^{2}` | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | sievert       | no         | :math:`1 \cdot metre^{2} \cdot second^{-2}`                                      | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | steradian     | no         | :math:`1`                                                                        | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | tesla         | no         | :math:`1 \cdot kilogram \cdot second^{-2} \cdot ampere^{-1}`                     | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | volt          | no         | :math:`1 \cdot metre^{2} \cdot kilogram \cdot second^{-3} \cdot ampere^{-1}`     | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | watt          | no         | :math:`1 \cdot metre^{2} \cdot kilogram \cdot second^{-3}`                       | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+
   | weber         | no         | :math:`1 \cdot metre^{2} \cdot kilogram \cdot second^{-2} \cdot ampere^{-1}`     | :math:`0`              |
   +---------------+------------+----------------------------------------------------------------------------------+------------------------+

.. _prefix-values:

.. table:: Prefix values

   +-------+-------------+
   | Name  | Value       |
   +=======+=============+
   | yotta | :math:`24`  |
   +-------+-------------+
   | zetta | :math:`21`  |
   +-------+-------------+
   | exa   | :math:`18`  |
   +-------+-------------+
   | peta  | :math:`15`  |
   +-------+-------------+
   | tera  | :math:`12`  |
   +-------+-------------+
   | giga  | :math:`9`   |
   +-------+-------------+
   | mega  | :math:`6`   |
   +-------+-------------+
   | kilo  | :math:`3`   |
   +-------+-------------+
   | hecto | :math:`2`   |
   +-------+-------------+
   | deka  | :math:`1`   |
   +-------+-------------+
   | deci  | :math:`-1`  |
   +-------+-------------+
   | centi | :math:`-2`  |
   +-------+-------------+
   | milli | :math:`-3`  |
   +-------+-------------+
   | micro | :math:`-6`  |
   +-------+-------------+
   | nano  | :math:`-9`  |
   +-------+-------------+
   | pico  | :math:`-12` |
   +-------+-------------+
   | femto | :math:`-15` |
   +-------+-------------+
   | atto  | :math:`-18` |
   +-------+-------------+
   | zepto | :math:`-21` |
   +-------+-------------+
   | yocto | :math:`-24` |
   +-------+-------------+

.. _interpretation-of-units:

Interpretation of units
-----------------------

1. The base units SHALL consist of the user defined base units, and the
   built-in base units (those units defined in rows of the :ref:`built-in-units`
   table having 'yes' in the 'Base unit?' column).

2. There SHALL be one user defined base unit for every ``units`` element in the
   CellML model which has a ``base_units`` attribute in the empty namespace,
   having value ``yes``.

3. The base unit reduction of a units reference SHALL consist of a real
   valued offset, a real valued multiplier, and a set of tuples each
   consisting of a base unit and a real valued exponent. The base unit
   reduction of a units reference SHALL be determined as follows:

   a. Where the units reference is to a unit which is a base unit, then
      the base unit reduction of the units reference SHALL have offset
      :math:`0.0`, multiplier :math:`1.0`, and the set of tuples SHALL
      have a single member, which SHALL consist of the base units being
      referenced and the exponent :math:`1.0`.

   b. Where the units reference is to built-in units other than a base
      unit, then the base unit reduction SHALL be derived from the row
      of ? for which the value in the 'Name' column matches the name of
      the units reference. The offset of the base unit reduction SHALL
      be equal to the number in the 'Offset from base units' column of
      the row, and the multiplier SHALL be equal to the number at the
      start of the 'Multiplier and dimensions in terms of base units'
      column of the row. The set of tuples SHALL contain one member for
      every built-in base unit named in the 'Multiplier and dimensions
      in terms of base units' column of the row, and each of these
      tuples SHALL contain the built-in unit referenced, and the
      exponent appearing in superscript immediately after the units name
      in the table cell.

   c. Where the units reference is to a unit which is neither built-in,
      nor a base unit, the resultant base unit reduction SHALL be
      defined as a composition of the base unit reductions referenced
      from the ``unit`` element information items (the operand base unit
      reductions), in accordance with the following rules:

      i.   The prefix term is a conceptual property of ``unit`` elements,
           defined here for later use. If the ``unit`` element does not have a
           ``prefix`` attribute information item, the prefix term SHALL have
           value :math:`0.0`. If the ``prefix`` attribute information item has
           a value which is a real number string, then the prefix term SHALL have
           the corresponding numerical value. Otherwise, the ``prefix`` attribute
           information item MUST have a value taken from the 'Name'
           column of the :ref:`prefix-values` table, and the prefix term
           SHALL have the value taken from the 'Value' column of the same row.

      ii.  The exponent term is a conceptual property of ``unit`` elements,
           defined here for later use. If a ``unit`` element has no ``exponent``
           attribute information item, the exponent term SHALL have value
           :math:`1.0`. Otherwise, the value of the ``exponent`` attribute
           information item MUST be a real number string, and the value of the
           exponent term SHALL be the numerical value of that string.

      iii. The multiplier term is a conceptual property of ``unit`` elements,
           defined here for later use. The multiplier term SHALL be the
           real number value of the ``multiplier`` attribute information item
           on the ``units`` element (or :math:`1.0` in the absence of such an
           attribute information item), multiplied by :math:`10.0` raised to the
           power of the product of the prefix term and the exponent term.

      iv.  The offset term is a conceptual property of ``unit`` elements,
           defined here for later use. If a ``unit`` element has no ``offset``
           attribute information item, the offset term SHALL have value
           :math:`0.0`. Otherwise, the value of the ``offset`` attribute
           information item MUST be a real number string, and the value of
           the offset term SHALL be the numerical value of that string.

      v.   Where the units reference is to a ``units`` element with a single
           ``unit`` child element, then the resultant base unit reduction
           SHALL have multiplier equal to the product of the multiplier of
           the operand base unit reduction and the multiplier term of the
           ``unit`` element. It SHALL have offset equal to the sum of the
           offset of the operand base unit reduction and the offset term
           of the ``unit`` element.

      vi.  Where the units reference is to a ``units`` element with a number
           of ``unit`` child elements not equal to :math:`1.0`, then the resultant
           base unit reduction SHALL have multiplier equal to the product
           of the multipliers of each operand base unit reduction, and the
           multiplier term of each ``unit`` element. It SHALL have offset
           equal to :math:`0.0`.

      vii. The set of tuples on the resultant base unit reduction SHALL
           have one member for every distinct base unit present in the set
           of tuples for any of the operand base unit reductions. The
           exponent alongside each of these base units in the resultant
           base unit reduction SHALL be the sum, across all tuples for the
           base unit from operand base unit reductions, of pairwise
           products of the exponent term on the corresponding ``unit`` element
           and the exponent from the tuple.

Component reference
-------------------

1. A component reference SHALL be the name of a component, and SHALL be
   interpreted based on the context within the CellML model in which it
   occurs.

2. A component reference present in an information item which is a
   descendant of a ``model`` element SHALL be identical to either the ``name``
   attribute on a ``component`` element or to the ``name`` attribute on an
   ``import component`` element.

3. A component reference which is identical to the ``name`` attribute on a
   ``component`` element SHALL be treated as a reference to that ``component``
   element.

4. A component reference which is identical to the ``name`` attribute on an
   ``import component`` element SHALL be treated as if the component
   reference appeared in the imported model, and referred to the name
   specified in the ``component_ref`` attribute of the ``import component``
   element.

5. It is noted, for the avoidance of doubt, that CellML models MAY apply
   the previous rule recursively, to reference an ``import component``
   element which in turn references another ``import component`` element.

Variable reference
------------------

1. When present in an information item which is a descendant of a
   ``component`` element, a variable reference SHALL be the name of a
   variable, and SHALL refer to the ``variable`` element in the same
   component with a ``name`` attribute identical to the variable reference.

2. In all other cases, a variable reference SHALL consist of a component
   reference and a variable name. In this case, the variable reference
   SHALL be treated as if it was present in the ``component`` element
   referenced by the component reference.

Interpretation of initial values
--------------------------------

1. This section applies to the interpretation of the ``initial_value``
   attribute, when it appears as an attribute information item on a
   ``variable`` element.

2. The ``initial_value`` attribute MUST either be a real number string, or
   a variable reference.

3. Where the ``initial_value`` attribute has a real number value, it SHALL
   be interpreted as a statement that the variable on which the
   attribute appears is equal to that real number value, under the
   conditions when the initial value holds.

4. Where the ``initial_value`` attribute is a variable reference, it SHALL
   be interpreted as a statement that the variable on which the
   attribute appears is equal to the referenced variable under the
   conditions when the initial value holds.

.. todo::

   Need a reasonable definition of the conditions when the
   initial value holds, because we can't really use the 1.1 version
   because it is problematic for a number of reasons.

.. _effect-of-units-on-variables:

Effect of units on variables
----------------------------

1. The ``units`` attribute on a ``variable`` element MUST be a valid units
   reference. The target of this units reference is referred to as
   the variable units, and the corresponding base units reduction is
   referred to as the variable base unit reduction.

2. The variable base unit reduction of a ``variable`` element MUST have an
   identical set of tuples to the set of tuples on the source variable
   base element units reduction. Two sets of tuples SHALL be considered
   identical if and only if neither set contains any tuple not present
   in the other. Two tuples are considered identical if both the base
   units and exponent on the tuple are the same.

3. The following symbols are defined for the purposes of the formulae in
   the :ref:`interpretation-of-mathematics` section:

   a. :math:`m_{V}` is the multiplier on the variable base unit reduction.

   b. :math:`o_{V}` is the offset on the variable base unit reduction.

   c. :math:`m_{S}` is the multiplier on the source variable base unit reduction.

   d. :math:`o_{S}` is the offset on the source variable base unit reduction.

.. _interpretation-of-mathematics:

Interpretation of mathematics
-----------------------------

1. Every MathML element in the CellML model, which appears as a direct
   child information item of the MathML ``math`` element information item,
   which in turn appears as a child information item of a pertinent
   ``component`` element, SHALL be treated as a statement which holds true
   unconditionally.

2. Every variable name given using the MathML ``ci`` element SHALL be
   treated as a variable reference within the component element ancestor
   the MathML is contained within.

3. Every such variable reference SHALL be treated as a linear expression
   :math:`\frac{m_{V}}{m_{S}} \cdot x - o_{V} + \frac{m_{S}}{m_{V}} \cdot o_{S}`.
   In this equation, :math:`x` represents the
   variable in the mathematical model, in the units of the source
   variable element, while the remaining variables SHALL be interpreted
   as specified in the :ref:`effect-of-units-on-variables` section.

4. Every MathML ``cn`` element MUST have an attribute information item in
   the CellML namespace, with local name ``units``. The value of
   this attribute information item MUST be a valid units reference. The
   referenced units SHALL NOT affect the mathematical interpretation of
   the CellML model. However, CellML processing software MAY use this
   information to assist the user in the detection and correction of
   units errors in the CellML model.

Interpretation of grouping
--------------------------

1.  Two ``relationship_ref`` elements SHALL be considered to refer to the
    same relationship if and only if all of the following conditions hold:

    a. The attribute information item with local name ``relationship``
       is in an identical namespace on both element information items;

    b. The attribute information item with local name ``relationship``
       has identical values on each of the element information items; and

    c. Either the attribute information item in the empty namespace and
       with local name ``name`` is absent on both element information
       items, or, it is present on both element information items and
       has identical value.

2.  For every distinct relationship referred to by a ``relationship_ref``
    element in the CellML model, there SHALL be a conceptual
    relationship digraph in which there is one node for every component
    in the CellML model.

3.  Where a ``component_ref`` element appears as a child of another
    ``component_ref`` element, then for all ``relationship_ref`` elements
    which are children of the ancestral ``group`` element, there SHALL be an
    arc in the relationship digraph corresponding to the relationship
    referenced by the ``relationship_ref`` element, and that arc SHALL be
    from the component referenced by the parent ``component_ref`` element
    and to the component referenced by the child ``component_ref`` element.

4.  The term encapsulation digraph SHALL refer to the relationship
    digraph for the relationship corresponding to the ``relationship_ref``
    attribute in the empty namespace and with value ``encapsulation`` (and
    with no ``name`` attribute).

5.  The encapsulation digraph MUST NOT contain any loops, and MUST NOT
    contain any cycles in the underlying graph (that is, it must be a
    tree).

6.  The encapsulated set for a component *A* SHALL be the set of all
    components to which there exists an arc in the encapsulation digraph
    from the node corresponding to *A*.

7.  The encapsulation parent for a component *A* SHALL be the component
    corresponding to the node which is the parent node in the
    encapsulation digraph of the node corresponding to *A*.

8.  The sibling set for a component *A* SHALL be the set of all components
    which have the same encapsulation parent as *A*, or in the case that *A*
    has no encapsulation parent, SHALL be the set of all components
    which do not have an encapsulation parent.

9.  The hidden set for a component *A* SHALL be the set of all components
    *B* where component *B* is not in the encapsulated set for component *A*,
    and component *B* is not the encapsulation parent of component *A*, and
    component *B* is not in the sibling set for component *A*.

10. CellML models MUST NOT contain ``map_components`` elements such that
    the component referenced by the ``component_1`` attribute is in the
    hidden set of the component referenced by the ``component_2`` attribute.

Variable equivalence networks
-----------------------------

1.  A variable equivalence network SHALL be a directed graph with one
    node for every ``variable`` element in the CellML model.

2.  For every ``map_variables`` element present in the CellML model, there
    SHALL be an arc in the variable equivalence network.

3.  One endpoint of the arc in the variable equivalence network SHALL be
    the node corresponding to the variable *A* referenced by the
    ``component_1`` and ``variable_1`` attributes.

4.  One endpoint of the arc in the variable equivalence network SHALL be
    the node corresponding to the variable *B* referenced by the
    ``component_2`` and ``variable_2`` attributes.

5.  CellML models MUST NOT contain any pair of ``map_variables`` elements
    which each make reference to the same sets of variables (without
    regard to whether the ``variable_1`` attribute of one ``map_variables``
    element references the variable referenced by the ``variable_1`` or
    ``variable_2`` attribute of the other).

6.  When the ``component`` parent element of variable *A* is in the sibling
    set of the ``component`` parent element of variable *B*, the applicable
    interface for variables *A* and *B* SHALL be the public interface.

7.  Where the ``component`` parent element of variable *A* is in the
    encapsulated set of the ``component`` parent element of variable *B*, the
    applicable interface for variable *A* SHALL be the public interface,
    and the applicable interface for variable *B* SHALL be the private
    interface.

8.  Where the ``component`` parent element of variable *B* is in the
    encapsulated set of the ``component`` parent element of variable *A*, the
    applicable interface for variable *A* SHALL be the private interface,
    and the applicable interface for variable *B* SHALL be the public
    interface.

9.  For a given variable, if the applicable interface is the public
    interface, the applicable interface attribute SHALL be the
    ``public_interface`` attribute information item on the corresponding
    ``variable`` element. If the applicable interface is the private
    interface, the applicable interface attribute SHALL be the
    ``private_interface`` attribute information item on the corresponding
    ``variable`` element.

10. In any case, if the applicable interface attribute is absent, the
    following rules in this section SHALL still apply as if the
    applicable interface attribute was present, and had the value ``none``.

11. CellML models MUST NOT contain ``map_variables`` elements unless the
    value of the applicable interface attributes on variables *A* and *B*
    are both either ``in`` or ``out``, and those two attribute values are
    different from each other.

12. The direction of the arc SHALL be from the node corresponding to the
    variable with the applicable interface attribute equal to ``in``, and
    SHALL be to the node corresponding to the variable with the
    applicable interface attribute equal to ``out``.

13. For the purposes of this specification, the ``variable`` elements in a
    CellML model SHALL be treated as belonging to one of several
    disjoint sets of connected variables. Each set of connected
    variables is the set of all ``variable`` elements for which the
    corresponding nodes in the variable equivalence network form a
    weakly connected subgraph. Each set of connected variables
    represents one variable in the mathematical model.

14. In every set of connected variables, there MUST be exactly one
    ``variable`` element which has neither a public interface of ``in`` nor a
    private interface of ``in``. This ``variable`` element is referred to as the
    source ``variable`` element. Within this specification, the variable in
    the mathematical model is described as if it was in the units
    specified on the source ``variable`` element.
