.. _sectionC:

.. marker_interpretation_of_imports_start

.. _specC_interpretation_of_imports:

Interpretation of ``import`` elements
-------------------------------------

#. Each :code:`import` element present in a :ref:`CellML infoset<specA_cellml_infoset>` (the importing infoset) SHALL define a new and distinct instance of the CellML infoset which is referenced by the :code:`href` attribute (the imported infoset).
   This imported infoset instance SHALL provide the context in which the child of an import element (a :code:`units` or :code:`component` element) is defined and interpreted.

#. The imported infoset SHALL be considered such that items relevant to the imported infoset (:code:`unit` children of imported :code:`units` elements or the :ref:`encapsulated set<specC_encapsulation_set>` of imported :code:`component` elements) are themselves available to that :code:`import` element child.
   It is noted, for the avoidance of doubt, that the importing infoset SHALL NOT have access to such implicitly imported items, but only to explicitly specified :code:`import` element children.

See :ref:`Units reference<specC_units_reference>` and :ref:`Component reference<specC_component_reference>` for the specifics of importing units and components.

.. marker_interpretation_of_imports_end
.. marker_units_reference_start

.. _specC_units_reference:

References to ``units`` elements
--------------------------------

The term "units reference" refers to the value of a :code:`units_ref` attribute in :code:`import` items for :code:`units`, and the values of :code:`units` attributes used in :code:`unit` and :code:`variable` items.

#. A units reference SHALL be a CellML identifier and SHALL be interpreted dependent on the context of the :ref:`CellML model<specA_cellml_model>` in which it occurs, according to the units referencing rules defined later in this section.

#. The units referencing rules are:

   #. Where, within the same infoset, a :code:`units` element has a :code:`name` attribute identical to the units reference, the units reference SHALL refer to that :code:`units` element.

   #. Where there is an :code:`import units` element in the :ref:`CellML infoset<specA_cellml_infoset>`, such that the :code:`import units` element has a :code:`name` attribute identical to the units reference, then the units reference SHALL be treated with respect to referencing rules as if the units reference appeared in the imported infoset, and referring to the :code:`name` specified in the :code:`units_ref` attribute of the :code:`import units` element.

   #. Where the units reference is equal to the value in the "Name" column of the :ref:`Built-in units table<table_built_in_units>`, then the units reference SHALL be a reference to the built-in units corresponding to that row of the table.

.. marker_units_reference1

.. _table_built_in_units:

**Table 3.1: Built-in units**

+-----------------------+-------------------+----------------------------------------------+-------------------------+
| | **Name**            | | **Symbol**      | | **Unit reduction tuple**                   | | **Common**            |
| |                     | |                 | | multiplier⋅(base, exponent)                | | **definitions**       |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`ampere`        | A                 | \-                                           |                         |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`becquerel`     | Bq                | (:code:`second`, -1)                         | 1/s                     |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`candela`       | cd                | \-                                           |                         |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`coulomb`       | C                 | (:code:`second`, 1), (:code:`ampere`, 1)     | | s⋅A                   |
|                       |                   |                                              | | F⋅V                   |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`dimensionless` | \-                | \-                                           |                         |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`farad`         | F                 | (:code:`kilogram`, -1), (:code:`metre`, -2), | | C/V                   |
|                       |                   | (:code:`second`, 4), (:code:`ampere`, 2)     | | s/Ω                   |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`gram`          | g                 | 0.001⋅(:code:`kilogram`, 1)                  |                         |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`gray`          | Gy                | (:code:`metre`, 2), (:code:`second`, -2)     | J/kg                    |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`henry`         | H                 | (:code:`kilogram`, 1), (:code:`metre`, 2),   | | V⋅s/A                 |
|                       |                   | (:code:`second`, -2), (:code:`ampere`, -2)   | | Ω⋅s                   |
|                       |                   |                                              | | Wb/A                  |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`hertz`         | Hz                | (:code:`second`, -1)                         |                         |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`joule`         | J                 | (:code:`kilogram`, 1), (:code:`metre`, 2),   | | N⋅m                   |
|                       |                   | (:code:`second`, -2)                         | | C⋅V                   |
|                       |                   |                                              | | Wb⋅s                  |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`katal`         | kat               | (:code:`second`, -1), (:code:`mole`, 1)      |                         |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`kelvin`        | K                 | \-                                           |                         |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`kilogram`      | kg                | \-                                           |                         |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`litre`         | l                 | 0.001⋅(:code:`metre`, 3)                     |                         |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`lumen`         | lm                | (:code:`candela`, 1)                         | cd⋅sr                   |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`lux`           | lx                | (:code:`metre`, -2), (:code:`candela`, 1)    | lm/m\ :sup:`2`          |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`metre`         | m                 | \-                                           |                         |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`mole`          | mol               | \-                                           |                         |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`newton`        | N                 | (:code:`kilogram`, 1), (:code:`metre`, 1),   |                         |
|                       |                   | (:code:`second`, -2)                         |                         |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`ohm`           | Ω                 | (:code:`kilogram`, 1), (:code:`metre`, 2),   | | 1/S                   |
|                       |                   | (:code:`second`, -3), (:code:`ampere`, -2)   | | V/A                   |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`pascal`        | Pa                | (:code:`kilogram`, 1), (:code:`metre`, -1),  | N/m\ :sup:`2`           |
|                       |                   | (:code:`second`, -2)                         |                         |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`radian`        | rad               | (:code:`dimensionless`, 1)                   | m/m                     |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`second`        | s                 | \-                                           |                         |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`siemens`       | S                 | (:code:`kilogram`, -1), (:code:`metre`, -2), | | 1/Ω                   |
|                       |                   | (:code:`second`, 3), (:code:`ampere`, 2)     | | A/V                   |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`sievert`       | Sv                | (:code:`metre`, 2), (:code:`second`, -2)     | J/kg                    |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`steradian`     | sr                | (:code:`dimensionless`, 1)                   | m\ :sup:`2`/m\ :sup:`2` |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`tesla`         | T                 | (:code:`kilogram`, 1), (:code:`second`, -2), | | V⋅s/m\ :sup:`2`       |
|                       |                   | (:code:`ampere`, -1)                         | | Wb/m\ :sup:`2`        |
|                       |                   |                                              | | N/(A⋅m)               |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`volt`          | V                 | (:code:`kilogram`, 1), (:code:`metre`, 2),   | | W/A                   |
|                       |                   | (:code:`second`, -3), (:code:`ampere`, -1)   | | J/C                   |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`watt`          | W                 | (:code:`kilogram`, 1), (:code:`metre`, 2),   | | J/s                   |
|                       |                   | (:code:`second`, -3)                         | | V⋅A                   |
+-----------------------+-------------------+----------------------------------------------+-------------------------+
| :code:`weber`         | Wb                | (:code:`kilogram`, 1), (:code:`metre`, 2),   | | J/A                   |
|                       |                   | (:code:`second`, -2), (:code:`ampere`, -1)   | | T⋅m\ :sup:`2`         |
+-----------------------+-------------------+----------------------------------------------+-------------------------+


.. marker_units_reference_end
.. marker_interpretation_of_units_start

.. _specC_interpretation_of_units:

Interpretation of ``units`` elements
------------------------------------

1. The :code:`units` element SHALL be interpreted as the product of its
   :code:`unit` element children, according to the following rules:

   1. The prefix term is a conceptual property of :code:`unit` elements.
      If the :code:`unit` element does not have a :code:`prefix` attribute information item, the prefix term SHALL have value 0.
      If the :code:`prefix` attribute information item has a value which is an integer string, then the value of the prefix term SHALL be the numerical value of that string.
      Otherwise, the :code:`prefix` attribute information item MUST have a value taken from the "Name" column of the :ref:`Prefix values table<table_prefix_values>`, and the prefix term SHALL have the value taken from the "Value" column of the same row.

   2. The exponent term is a conceptual property of :code:`unit` elements.
      If a :code:`unit` element has no :code:`exponent` attribute information item, the exponent term SHALL have value 1.0.
      Otherwise, the value of the :code:`exponent` attribute information item MUST be a real number string, and the value of the exponent term SHALL be the numerical value of that string.

   3. The multiplier term is a conceptual property of :code:`unit` elements.
      If a :code:`unit` element has no :code:`multiplier` attribute information item, the multiplier term SHALL have value 1.0.
      Otherwise, the value of the :code:`multiplier` attribute information item MUST be a real number string, and the value of the multiplier term SHALL be the numerical value of that string.

   4. The relationship between the product, :math:`P`, of numerical values given in each and every child :code:`unit` element units, to a numerical value, :math:`x`, with units given by the encompassing :code:`units` element, SHALL be

      .. math::

         x[u_x] = {\dfrac {1} {m_1 \dotsm m_n(10^{p_1})^{e_1} \dotsm (10^{p_1})^{e_n}}} { \left[ \dfrac {u_x}{u^{e_1} \dotsm u^{e_n}} \right ] }P \left[ u^{e_1} \dotsm u^{e_n} \right]

      where :math:`u_x` denotes the units of the :code:`units` element; :math:`p_i`, :math:`e_i`, :math:`m_i` and :math:`u_i` refer to the prefix, exponent and multiplier terms and units of the :math:`i^{th}` :code:`unit` child element, respectively.
      Square brackets encompass the units of numerical values.

.. marker_interpretation_of_units_1

2. For the purposes of this specification, the "irreducible units" of a model SHALL consist of 1) the units defined in a model that are not defined in terms of other units (i.e. the set of :code:`units` elements in the :ref:`CellML model<specA_cellml_model>` which have no :code:`unit` child elements), and 2) built-in irreducible units (those built-in units with "-" in the "Unit Reduction" column of the :ref:`Built-in units<table_built_in_units>` table) referenced by variables or other units in the model.

.. marker_interpretation_of_units_2

3. The "unit reduction" is a conceptual property of :code:`units` elements.
   It consists of a set of tuples where each tuple is composed of a) a unit name and b) a real-valued exponent.
   Tuples SHALL be determined as follows:

   1. If the :code:`units` element has no :code:`unit` child elements, then the set of tuples SHALL have a single member, which SHALL consist of the name of the :code:`units` element and the exponent 1.0.

   2. If the :code:`units` element has one or more :code:`unit` child elements, then the set of tuples SHALL consist of the entire collection of tuples given by all :code:`unit` child elements.
      Tuples for each :code:`unit` child element SHALL be determined as follows:

      1. Where the :ref:`units reference<specC_units_reference>` of the :code:`unit` child element is to a single unit which is an irreducible unit, then the set of tuples SHALL have a single member, which SHALL consist of the name of the irreducible unit being referenced and the exponent 1.0.

      2. Where the units reference of the :code:`unit` child element is to built-in units other than an irreducible unit, then the tuples SHALL be derived directly from the :ref:`Built-in units<table_built_in_units>` table.
         Specifically, the set of tuples SHALL consist of the tuples given in the "Unit reduction tuple set" column of the row for which the value in the "Name" column matches the name of the units reference.

      3. Where the units reference of the :code:`unit` child element is to a unit which is neither built-in, nor an irreducible unit, the set of tuples SHALL be defined recursively as the set of tuples for the :code:`units` element so referenced.

      4. The exponents of each tuple in the set for the current :code:`unit` element, as derived by following rules 3.3.3.2.1, 3.3.3.2.2 or 3.3.3.2.3 above, SHALL be multiplied by the exponent term of the current, referencing, :code:`unit` element.

   3. Tuples which have the name element of "dimensionless" SHALL be removed from the set of tuples.
      Note that this can result in the set of tuples being empty.

   4. Where the set of tuples consists of tuples which have the same name element, those tuples SHALL be combined into a single tuple with that name element and an exponent being the sum of the combined tuples’ exponents.
      If the resulting tuple’s exponent term is zero, the tuple SHALL be removed from the set of tuples.
      Note that this can result in the set of tuples being empty.

.. marker_interpretation_of_units_3

.. _table_prefix_values:

**Table 3.2: Prefix values**

============== ==========
**Name**       **Value**
:code:`yotta`    24
:code:`zetta`    21
:code:`exa`      18
:code:`peta`     15
:code:`tera`     12
:code:`giga`     9
:code:`mega`     6
:code:`kilo`     3
:code:`hecto`    2
:code:`deca`     1
:code:`deci`     −1
:code:`centi`    −2
:code:`milli`    −3
:code:`micro`    −6
:code:`nano`     −9
:code:`pico`     −12
:code:`femto`    −15
:code:`atto`     −18
:code:`zepto`    −21
:code:`yocto`    −24
============== ==========

.. marker_interpretation_of_units_end
.. marker_component_reference_start

.. _specC_component_reference:


References to ``component`` elements
------------------------------------

The term "component reference" refers to the value of a :code:`component_ref` attribute used in an :code:`import` item for :code:`component` items, to :code:`component_ref` elements which occur as children of :code:`encapsulation` items, and to the value of :code:`component_1` and :code:`component_2` attributes used in :code:`connection` items.

#. A component reference SHALL be the name of a component, and SHALL be interpreted based on the context within the :ref:`CellML model<specA_cellml_model>` in which it occurs.

#. Where, within the same infoset, a :code:`component` element has a :code:`name` attribute identical to the component reference, the component reference SHALL refer to that :code:`component` element.

#. A component reference which is identical to the :code:`name` attribute on an :code:`import component` element SHALL be treated for the purposes of referencing as if the component reference appeared in the imported model, and referred to element with the :code:`name` specified in the :code:`component_ref` attribute of the :code:`import component` element.

#. It is noted, for the avoidance of doubt, that CellML models MAY apply the previous rule recursively, to reference an :code:`import component` element which in turn references another :code:`import component` element.

.. marker_component_reference_end
.. marker_variable_reference_start

.. _specC_variable_reference:

References to ``variable`` elements
-----------------------------------

#. When present in a descendant of a :code:`component` element, a variable reference SHALL be the name of a variable, and SHALL refer to the :code:`variable` element in that component with a :code:`name` attribute identical to the variable reference.

#. When present as the value of a :code:`variable_1` attribute of a :code:`map_variables` element, a variable reference SHALL be the name of a variable, and SHALL be interpreted as referring to the :code:`variable` element with a :code:`name` attribute identical to the variable reference and being a child of the :code:`component` named by the value of the :code:`component_1` attribute of the parent :code:`connection` element.

#. When present as the value of a :code:`variable_2` attribute of a :code:`map_variables` element, a variable reference SHALL be the name of a variable, and SHALL be interpreted as referring to the :code:`variable` element with a :code:`name` attribute identical to the variable reference and being a child of the :code:`component` named by the value of the :code:`component_2` attribute of the parent :code:`connection` element.

.. marker_variable_reference_end
.. marker_interpretation_of_initial_values_start

.. _specC_interpretation_of_initial_values:


Interpretation of ``initial_value`` attributes
----------------------------------------------

#. The :code:`initial_value` attribute of a :code:`variable` element MUST either be a real number string, or a :ref:`variable reference<specC_variable_reference>`.

#. The conditions when initial values hold are (by design) not defined in a :ref:`CellML model<specA_cellml_model>` document.

#. Where the :code:`initial_value` attribute has a real number value, it SHALL be interpreted as a statement that the variable on which the attribute appears is equal to that real number value, under the conditions when the initial value holds.

#. Where the :code:`initial_value` attribute is a variable reference, it SHALL be interpreted as a statement that the variable on which the attribute appears is equal to the referenced variable under the conditions when the initial value holds.

.. marker_interpretation_of_initial_values_end
.. marker_effect_of_units_on_variables_start

.. _specC_effect_of_units_on_variables:


Effect of ``units`` on a ``variable``
-------------------------------------

#. The target of the :code:`units` attribute on a variable is referred to as the "variable units", and the corresponding unit reduction (see :ref:`Interpretation of units<specC_interpretation_of_units>`) is referred to as the "variable unit reduction".

.. marker_effect_of_units_on_variables_end
.. marker_interpretation_of_mathematics_start

.. _specC_interpretation_of_mathematics:


Interpretation of ``math`` elements
-----------------------------------

#. The following :code:`component` elements SHALL, for the purposes of this specification, be "pertinent component elements":

   #. All :code:`component` elements in the top-level :ref:`CellML infoset<specA_cellml_infoset>` for the :ref:`CellML model<specA_cellml_model>`;

   #. All :code:`component` elements referenced by :code:`import component` elements (see :ref:`The import component element <specC_component_reference>`) in the top-level :ref:`CellML infoset<specA_cellml_infoset>`; and

   #. All :code:`component` elements which are descendants in the encapsulation digraph (see :ref:`Interpretation of encapsulation <specC_interpretation_of_encapsulation>`) of a pertinent :code:`component` element.

#. Every MathML element in the :ref:`CellML model<specA_cellml_model>` which appears as a direct child information item of a MathML :code:`math` element information item, which in turn appears as a child information item of a pertinent :code:`component` element, SHALL be treated, in terms of the semantics of the mathematical model, as a statement which holds true unconditionally.

#. Units referenced by a :code:`units` attribute information item SHALL NOT affect the mathematical interpretation of the :ref:`CellML model<specA_cellml_model>`.

.. marker_interpretation_of_mathematics_end
.. marker_interpretation_of_encapsulation_start

.. _specC_interpretation_of_encapsulation:


Interpretation of ``encapsulation`` elements
--------------------------------------------

1. For the purposes of this specification, there SHALL be a "conceptual encapsulation digraph" in which there is EXACTLY one node for every component in the :ref:`CellML model<specA_cellml_model>`.
   Therefore the encapsulation digraph will not contain any loops.

2. Where a :code:`component_ref` element appears as a child of another :code:`component_ref` element, there SHALL be an arc in the encapsulation digraph, and that arc SHALL be from the node corresponding to the component referenced by the parent :code:`component_ref` element, and to the node corresponding to the component referenced by the child :code:`component_ref` element.

.. marker_interpretation_of_encapsulation_1
.. _specC_encapsulation_set:

3. The encapsulated set for a component *A* SHALL be the set of all components *B* such that there exists an arc in the encapsulation digraph from the node corresponding to *A* to the node corresponding to *B*.

4. The encapsulation parent for a component *A* SHALL be the component corresponding to the node which is the parent node in the encapsulation digraph of the node corresponding to *A*.
   A component SHALL NOT appear as child of more than one encapsulation parent.

5. The sibling set for a component *A* SHALL be the set of all components which have the same encapsulation parent as *A*, or in the case that *A* has no encapsulation parent, SHALL be the set of all components which do not have an encapsulation parent.

6. The hidden set for a component *A* SHALL be the set of all components *B* where component *B* is not in the encapsulated set for component *A*, and component *B* is not the encapsulation parent of component *A*, and component *B* is not in the sibling set for component *A*.

.. marker_interpretation_of_encapsulation_2

7. For the avoidance of doubt, there MUST NOT be a :code:`connection` element such that the component referenced by the :code:`component_1` attribute is in the hidden set of the component referenced by the :code:`component_2` attribute, nor vice versa.

.. marker_interpretation_of_encapsulation_end
.. marker_interpretation_of_map_variables_start

.. _specC_interpretation_of_map_variables:

Interpretation of ``map_variables`` elements
--------------------------------------------

1.  For the purposes of this specification, the variable equivalence (conceptual) network SHALL be an undirected graph with one node for every :code:`variable` element in the :ref:`CellML model<specA_cellml_model>`.
    The arcs of this graph SHALL be equivalences defined in the CellML model.

.. marker_interpretation_of_map_variables_1

2.  For each :code:`map_variables` element present in the CellML model, we define variables *A* and *B* for use in the rules in this section as follows.

    #. Variable *A* SHALL be the variable referenced by the encompassing :code:`connection` element’s :code:`component_1` and this :code:`map_variables` element’s :code:`variable_1` attribute.

    #. Variable *B* SHALL be the variable referenced by the encompassing :code:`connection` element’s :code:`component_2` and this :code:`map_variables` element’s :code:`variable_2` attribute.

3.  For every :code:`map_variables` element present in the CellML model, there SHALL be an arc in the variable equivalence network.

    #. One endpoint of the arc in the variable equivalence network SHALL be the node corresponding to variable *A*.

    #. One endpoint of the arc in the variable equivalence network SHALL be the node corresponding to variable *B*.

.. marker_interpretation_of_map_variables_2

4.  CellML models MUST NOT contain any pair of :code:`map_variables` elements which duplicates an existing arc in the variable equivalence network.

5.  The variable equivalence network MUST NOT contain any cycles.

.. marker_interpretation_of_map_variables_3

#.  For a given variable, the available interfaces SHALL be determined by the :code:`interface` attribute information item on the corresponding :code:`variable` element as follows.

    #. A value of :code:`public` specifies that the variable has a public interface.

    #. A value of :code:`private` specifies that the variable has a private interface.

    #. A value of :code:`public_and_private` specifies that the variable has both a public and a private interface.

    #. A value of :code:`none` specifies that the variable has no interface.

    #. If the :code:`interface` attribute information item is absent, then the variable has no interface.

#.  The applicable interfaces for variables *A* and *B* in components *AA* and *BB* respectively SHALL be defined as follows.

    #. When component *AA* is in the sibling set of component *BB* (and vice versa), the applicable interface for both variables *A* and *B* SHALL be the public interface.

    #. When component *AA* is in the encapsulated set of component *BB* the applicable interface for variable *A* SHALL be the public interface, and the applicable interface for variable *B* SHALL be the private interface.

    #. When component *BB* is in the encapsulated set of component *AA* the applicable interface for variable *B* SHALL be the public interface, and the applicable interface for variable *A* SHALL be the private interface.

    #. It is noted, for the avoidance of doubt, that any other encapsulation relationship between components *AA* and *BB* will not permit connections, meaning that no interface is available between the variables *A* and *B*.

3.  CellML models MUST only contain :code:`map_variables` elements where the interface of variable *A* and the interface of variable *B* are applicable interfaces.

.. marker_interpretation_of_map_variables_4

#.  For each :code:`map_variables` element present in the CellML model, the variable unit reduction (see :ref:`Effect of units on variables <specC_effect_of_units_on_variables>` ) of variable *A* MUST have an identical set of tuples to the variable unit reduction of variable *B*.
    Two sets of tuples SHALL be considered identical if all of the tuples from each set are present in the other, or if both sets are empty.
    Two tuples are considered identical if and only if both the name and exponent value of each tuple are equivalent.

#.  Tuples differing by a multiplying factor in their unit reduction MUST be taken into account when interpreting the numerical values of the variables (see :ref:`Interpretation of units<specC_interpretation_of_units>`).

.. marker_interpretation_of_map_variables_5

#.  The :code:`variable` elements in a CellML model SHALL be treated as belonging to a single "equivalent variable set".
    Each set of equivalent variables is the set of all :code:`variable` elements for which the corresponding nodes in the variable equivalence network form a connected subgraph.
    Each set of equivalent variables represents one variable in the underlying mathematical model.

.. marker_interpretation_of_map_variables_end
.. marker_interpretation_of_variable_resets_start

.. _specC_interpretation_of_variable_resets:


Interpretation of ``reset`` elements
------------------------------------

#. For the purposes of this section, we define the "reset variable" to be the variable referenced by a :code:`reset` element's :code:`variable` attribute, and the "test variable" to be the variable referenced by its :code:`test_variable` attribute.

#. Each :code:`reset` element describes a change to be applied to the reset variable when specified conditions are met during the simulation of the model.

#. All :code:`reset` elements SHALL be considered sequentially for the equivalent variable set (see :ref:`Interpretation of map_variables<specC_interpretation_of_map_variables>`) to which the reset variable belongs.
   The sequence SHALL be determined by the value of the reset element’s :code:`order` attribute, lowest (least positive / most negative) having priority.

#. The condition under which a reset occurs SHALL be defined by the equality of evaluation of the test variable and the evaluation of the MathML expression encoded in the :code:`test_value`.

#. When a reset occurs, the variable referenced by the reset element’s :code:`variable` attribute SHALL be set to the result of evaluating the MathML expression encoded in the :code:`reset_value`.

.. marker_interpretation_of_variable_resets_end
