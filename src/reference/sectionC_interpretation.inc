.. _sectionC:

.. marker_interpretation_of_imports_start

.. _specC_interpretation_of_imports:

Interpretation of ``import`` elements
-------------------------------------

#. Each :code:`import units` or :code:`import component` element present in a :ref:`CellML infoset<specA_cellml_infoset>` (the importing infoset) SHALL define a new and distinct instance of the CellML infoset (the imported infoset) that is specified by the parent :code:`import` element's :code:`href` attribute.

#. A :ref:`units reference<specC_units_reference>` occurring within an imported element, SHALL be resolved with respect to the imported infoset.

#. When determining the :ref:`equivalent variable set<specC_equivalent_variable_set>` of a variable in an imported component:

   #. Connections defined in the importing infoset SHALL be handled as described in :numref:`{number} {name}<specC_interpretation_of_map_variables>`.

   #. Connections defined in the imported infoset SHALL be handled as follows:

      #. Connections to components in the :ref:`encapsulated set<specC_encapsulation_set>` of the imported component SHALL be maintained, and this rule SHALL be applied recursively; and

      #. Connections to components in the :ref:`sibling set<specC_sibling_set>`, or to the :ref:`encapsulation parent<specC_encapsulation_parent>` of the imported component SHALL NOT be maintained.

.. marker_interpretation_of_imports_end
.. marker_units_reference_start

.. _specC_units_reference:

Units references
----------------

A "units reference" is an attribute value that specifies the physical units a variable or number is in.

#. A units reference SHALL be a :ref:`CellML identifier<specA_cellml_identifier>`.

#. The units identified by a units reference SHALL be determined as follows:

   #. If the units reference is identical to a value in the "Name" column of :numref:`Table {number}: {name}<table_built_in_units>`, then it SHALL refer to the built-in units from the same row of the table.

   #. If the units reference is identical to the value of the :code:`name` attribute of a :code:`units` element in the same infoset, then it SHALL refer to the units specified by that element.

   #. If the units reference is identical to the value of the :code:`name` attribute of an :code:`import units` element in the same infoset, then it SHALL refer to units from the infoset defined by the :code:`import units` element (see :numref:`{number} {name}`<specC_interpretation_of_imports>`).
      The units specified SHALL then be determined by treating the value of the :code:`units_ref` attribute on the :code:`import units` element as a units reference within the imported infoset.
      If necessary, this rule SHALL be applied recursively.

#. If no units can be identified using the rules above, the attribute value SHALL NOT be a valid units reference.

.. marker_units_reference1

.. _table_built_in_units:

.. table:: Built-in units
  :widths: 30 70

  +-----------------------+----------------------------------------------+
  | | **Name**            | | **Unit reduction tuple**                   |
  | |                     | | multiplier⋅(base, exponent)                |
  +-----------------------+----------------------------------------------+
  | :code:`ampere`        | \-                                           |
  +-----------------------+----------------------------------------------+
  | :code:`becquerel`     | (:code:`second`, -1)                         |
  +-----------------------+----------------------------------------------+
  | :code:`candela`       | \-                                           |
  +-----------------------+----------------------------------------------+
  | :code:`coulomb`       | (:code:`second`, 1), (:code:`ampere`, 1)     |
  +-----------------------+----------------------------------------------+
  | :code:`dimensionless` | \-                                           |
  +-----------------------+----------------------------------------------+
  | :code:`farad`         | (:code:`kilogram`, -1), (:code:`metre`, -2), |
  |                       | (:code:`second`, 4), (:code:`ampere`, 2)     |
  +-----------------------+----------------------------------------------+
  | :code:`gram`          | 0.001⋅(:code:`kilogram`, 1)                  |
  +-----------------------+----------------------------------------------+
  | :code:`gray`          | (:code:`metre`, 2), (:code:`second`, -2)     |
  +-----------------------+----------------------------------------------+
  | :code:`henry`         | (:code:`kilogram`, 1), (:code:`metre`, 2),   |
  |                       | (:code:`second`, -2), (:code:`ampere`, -2)   |
  +-----------------------+----------------------------------------------+
  | :code:`hertz`         | (:code:`second`, -1)                         |
  +-----------------------+----------------------------------------------+
  | :code:`joule`         | (:code:`kilogram`, 1), (:code:`metre`, 2),   |
  |                       | (:code:`second`, -2)                         |
  +-----------------------+----------------------------------------------+
  | :code:`katal`         | (:code:`second`, -1), (:code:`mole`, 1)      |
  +-----------------------+----------------------------------------------+
  | :code:`kelvin`        | \-                                           |
  +-----------------------+----------------------------------------------+
  | :code:`kilogram`      | \-                                           |
  +-----------------------+----------------------------------------------+
  | :code:`litre`         | 0.001⋅(:code:`metre`, 3)                     |
  +-----------------------+----------------------------------------------+
  | :code:`lumen`         | (:code:`candela`, 1)                         |
  +-----------------------+----------------------------------------------+
  | :code:`lux`           | (:code:`metre`, -2), (:code:`candela`, 1)    |
  +-----------------------+----------------------------------------------+
  | :code:`metre`         | \-                                           |
  +-----------------------+----------------------------------------------+
  | :code:`mole`          | \-                                           |
  +-----------------------+----------------------------------------------+
  | :code:`newton`        | (:code:`kilogram`, 1), (:code:`metre`, 1),   |
  |                       | (:code:`second`, -2)                         |
  +-----------------------+----------------------------------------------+
  | :code:`ohm`           | (:code:`kilogram`, 1), (:code:`metre`, 2),   |
  |                       | (:code:`second`, -3), (:code:`ampere`, -2)   |
  +-----------------------+----------------------------------------------+
  | :code:`pascal`        | (:code:`kilogram`, 1), (:code:`metre`, -1),  |
  |                       | (:code:`second`, -2)                         |
  +-----------------------+----------------------------------------------+
  | :code:`radian`        | (:code:`dimensionless`, 1)                   |
  +-----------------------+----------------------------------------------+
  | :code:`second`        | \-                                           |
  +-----------------------+----------------------------------------------+
  | :code:`siemens`       | (:code:`kilogram`, -1), (:code:`metre`, -2), |
  |                       | (:code:`second`, 3), (:code:`ampere`, 2)     |
  +-----------------------+----------------------------------------------+
  | :code:`sievert`       | (:code:`metre`, 2), (:code:`second`, -2)     |
  +-----------------------+----------------------------------------------+
  | :code:`steradian`     | (:code:`dimensionless`, 1)                   |
  +-----------------------+----------------------------------------------+
  | :code:`tesla`         | (:code:`kilogram`, 1), (:code:`second`, -2), |
  |                       | (:code:`ampere`, -1)                         |
  +-----------------------+----------------------------------------------+
  | :code:`volt`          | (:code:`kilogram`, 1), (:code:`metre`, 2),   |
  |                       | (:code:`second`, -3), (:code:`ampere`, -1)   |
  +-----------------------+----------------------------------------------+
  | :code:`watt`          | (:code:`kilogram`, 1), (:code:`metre`, 2),   |
  |                       | (:code:`second`, -3)                         |
  +-----------------------+----------------------------------------------+
  | :code:`weber`         | (:code:`kilogram`, 1), (:code:`metre`, 2),   |
  |                       | (:code:`second`, -2), (:code:`ampere`, -1)   |
  +-----------------------+----------------------------------------------+


.. marker_units_reference_end
.. marker_interpretation_of_units_start

.. _specC_interpretation_of_units:

Interpretation of ``units`` elements
------------------------------------

1. The :code:`units` element SHALL be interpreted as the product of its
   :code:`unit` element children, according to the following rules:

   1. The prefix term is a conceptual property of :code:`unit` elements.
      If the :code:`unit` element does not have a :code:`prefix` attribute, the prefix term SHALL have value 0.
      If the :code:`prefix` attribute has a value which is an :ref:`integer string<specA_integer>`, then the value of the prefix term SHALL be the numerical value of that string.
      Otherwise, the :code:`prefix` attribute MUST have a value taken from the "Name" column of :numref:`Table {number}: {name}<table_prefix_values>`, and the prefix term SHALL have the value taken from the "Value" column of the same row.

   2. The exponent term is a conceptual property of :code:`unit` elements.
      If a :code:`unit` element has no :code:`exponent` attribute, the exponent term SHALL have value 1.0.
      Otherwise, the value of the :code:`exponent` attribute MUST be a :ref:`real number string<specA_real_number>`, and the value of the exponent term SHALL be the numerical value of that string.

   3. The multiplier term is a conceptual property of :code:`unit` elements.
      If a :code:`unit` element has no :code:`multiplier` attribute, the multiplier term SHALL have value 1.0.
      Otherwise, the value of the :code:`multiplier` attribute MUST be a :ref:`real number string<specA_real_number>`, and the value of the multiplier term SHALL be the numerical value of that string.

   4. The relationship between the product, :math:`P`, of numerical values given in each and every child :code:`unit` element's :code:`units` attribute, to a numerical value, :math:`x`, with units given by the encompassing :code:`units` element, SHALL be

      .. math::

         x[u_x] = {\dfrac {1} {m_1 \dotsm m_n(10^{p_1})^{e_1} \dotsm (10^{p_1})^{e_n}}} { \left[ \dfrac {u_x}{u^{e_1} \dotsm u^{e_n}} \right ] }P \left[ u^{e_1} \dotsm u^{e_n} \right]

      where :math:`u_x` denotes the units of the :code:`units` element; :math:`p_i`, :math:`e_i`, :math:`m_i` and :math:`u_i` refer to the prefix, exponent and multiplier terms and units of the :math:`i^{th}` :code:`unit` child element, respectively.
      Square brackets encompass the units of numerical values.

.. marker_interpretation_of_units_1

.. _specC_irreducible_units:

2. For the purposes of this specification, the "irreducible units" of a model SHALL consist of:

   1. The units defined in a model that are not defined in terms of other units (i.e. the set of :code:`units` elements in the :ref:`CellML model<specA_cellml_model>` which have no :code:`unit` child elements).

   2. The built-in irreducible units (those built-in units with "-" in the "Unit reduction tuple" column of :numref:`Table {number}: {name}<table_built_in_units>`) referenced by variables or other units in the model.

.. marker_interpretation_of_units_2
.. _specC_unit_reduction

3. The "unit reduction" is a conceptual property of :code:`units` elements.
   It consists of a set of tuples where each tuple is composed of a "unit name" and a real-valued "exponent".
   The set of tuples SHALL be determined as follows:

   1. If the :code:`units` element has no :code:`unit` child elements, then the set of tuples SHALL have a single member, which SHALL consist of the name of the :code:`units` element and the exponent 1.0.

   2. If the :code:`units` element has one or more :code:`unit` child elements, then the set of tuples SHALL consist of the entire collection of tuples given by all :code:`unit` child elements.

      Tuples for each :code:`unit` child element SHALL be determined as follows:

      .. _3_3_3_2_1:

      1. If the :ref:`units reference<specC_units_reference>` of the :code:`unit` child element is to a single unit which is an irreducible unit, then the set of tuples SHALL have a single member, which SHALL consist of the name of the irreducible unit being referenced and the exponent 1.0.

      .. _3_3_3_2_2:

      2. If the units reference of the :code:`unit` child element is to built-in units other than an :ref:`irreducible unit<specC_irreducible_units>`, then the tuples SHALL be derived directly from :numref:`Table {number}: {name}<table_built_in_units>`.
         Specifically, the set of tuples SHALL consist of the tuples given in the "Unit reduction tuple" column of the row for which the value in the "Name" column is identical to the name of the units reference.

      .. _3_3_3_2_3:

      3. If the units reference of the :code:`unit` child element is to a unit which is neither built-in, nor an irreducible unit, then the set of tuples SHALL be defined recursively as the set of tuples for the :code:`units` element so referenced.

      4. The exponents of each tuple in the set for the current :code:`unit` element, as derived by following rules :ref:`3.3.3.2.1<3_3_3_2_1>`, :ref:`3.3.3.2.2<3_3_3_2_2>` or :ref:`3.3.3.2.3<3_3_3_2_3>` above, SHALL be multiplied by the exponent term of the current, referencing, :code:`unit` element.

      .. hardcodedref above: 3.3.3.2.1
      .. hardcodedref above: 3.3.3.2.2
      .. hardcodedref above: 3.3.3.2.3

   3. Tuples which have the unit name of "dimensionless" SHALL be removed from the set of tuples.
      Note that this can result in the set of tuples being empty.

   4. If the set of tuples contains tuples which have the same unit name, then those tuples SHALL be combined into a single tuple with that unit name and an exponent being the sum of those tuples’ exponents.
      If the resulting tuple’s exponent is zero, then the tuple SHALL be removed from the set of tuples.
      Note that this can result in the set of tuples being empty.

.. marker_interpretation_of_units_3

.. _table_prefix_values:

.. table:: Prefix values
  :widths: auto

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

Component references
--------------------

A "component reference" is an attribute value that specifies a CellML component.

#. A component reference SHALL be a :ref:`CellML identifier<specA_cellml_identifier>`.

#. The component identified by a component reference SHALL be determined as follows:

   #. If the component reference is identical to the value of the :code:`name` attribute of a :code:`component` element in the same infoset, then it SHALL refer to the component specified by that element.

   #. If the component reference is identical to the value of the :code:`name` attribute of an :code:`import component` element in the same infoset, then it SHALL refer to a component from the infoset defined by the :code:`import component` element (see :numref:`{number} {name}<specC_interpretation_of_imports>`).
      The component specified SHALL then be determined by treating the value of the :code:`component_ref` attribute on the :code:`import component` element as a component reference within the imported infoset.
      If necessary, this rule SHALL be applied recursively.

#. If no component can be identified using the rules above, the attribute value SHALL NOT be a valid component reference.

.. marker_component_reference_end
.. marker_variable_reference_start

.. _specC_variable_reference:

Variable references
-------------------

A "variable reference" is an attribute value that specifies a CellML variable.

#. A variable reference SHALL be a :ref:`CellML identifier<specA_cellml_identifier>`.

#. The variable identified by a variable reference SHALL be determined as follows:

   #. When present in a descendant of a :code:`component` element, it SHALL refer to the variable of the same name within that component.

   #. When present in the :code:`variable_1` attribute of a :code:`map_variables` element, it SHALL refer to the variable of the same name in the component identified by the :code:`component_1` attribute in the same :code:`map_variables` element.

   #. When present in the :code:`variable_2` attribute of a :code:`map_variables` element, it SHALL refer to the variable of the same name in the component identified by the :code:`component_2` attribute in the same :code:`map_variables` element.

#. If no variable can be identified using the rules above, the attribute value SHALL NOT be a valid variable reference.

.. marker_variable_reference_end
.. marker_interpretation_of_initial_values_start

.. _specC_interpretation_of_initial_values:


Interpretation of ``initial_value`` attributes
----------------------------------------------

#. The :code:`initial_value` attribute of a :code:`variable` element MUST either be a :ref:`real number string<specA_real_number>`, or a :ref:`variable reference<specC_variable_reference>`.

#. The conditions under which initial values hold are (by design) not defined in a :ref:`CellML model<specA_cellml_model>`.

#. Where the :code:`initial_value` attribute is a :ref:`real number string<specA_real_number>`, it SHALL be interpreted as a statement that the variable on which the attribute appears is equal to that real number value when the initial values hold.

#. Where the :code:`initial_value` attribute is a :ref:`variable reference<specC_variable_reference>`, it SHALL be interpreted as a statement that the variable on which the attribute appears is equal to the referenced variable when the initial values hold.

.. marker_interpretation_of_initial_values_end
.. marker_effect_of_units_on_variables_start

.. _specC_effect_of_units_on_variables:


Effect of ``units`` on a ``variable``
-------------------------------------

#. The target of the :code:`units` attribute on a variable is referred to as the "variable units", and the corresponding unit reduction (see :numref:`{number} {name}<specC_interpretation_of_units>`) is referred to as the "variable unit reduction".

.. marker_effect_of_units_on_variables_end
.. marker_interpretation_of_mathematics_start

.. _specC_interpretation_of_mathematics:


Interpretation of ``math`` elements
-----------------------------------

1. The following :code:`component` elements SHALL, for the purposes of this specification, be "pertinent component elements":

   #. All :code:`component` elements in the top-level :ref:`CellML infoset<specA_cellml_infoset>` for the :ref:`CellML model<specA_cellml_model>`;

   #. All :code:`component` elements referenced by :code:`import component` elements (see :numref:`{number} {name}<specC_interpretation_of_imports>`) in the top-level CellML infoset; and

   #. All :code:`component` elements which are descendants in the encapsulation digraph (see :numref:`{number} {name}<specC_interpretation_of_encapsulation>`) of a pertinent :code:`component` element.

.. marker_interpretation_of_mathematics_1

2. Every MathML element in the CellML model which appears as a direct child of a MathML :code:`math` element, which in turn appears as a child of a pertinent :code:`component` element, SHALL be treated, in terms of the semantics of the mathematical model, as a statement which holds true unconditionally.

.. marker_interpretation_of_mathematics_2
.. _specC_units_and_maths:

3. Units referenced by a :code:`units` attribute SHALL NOT affect the mathematical interpretation of the CellML model.

.. marker_interpretation_of_mathematics_end
.. marker_interpretation_of_encapsulation_start

.. _specC_interpretation_of_encapsulation:


Interpretation of ``encapsulation`` elements
--------------------------------------------

1. For the purposes of this specification, there SHALL be a conceptual "encapsulation digraph" in which there is exactly one node for every component in the :ref:`CellML model<specA_cellml_model>`.

2. Where a :code:`component_ref` element appears as a child of another :code:`component_ref` element, there SHALL be an arc in the encapsulation digraph, and that arc SHALL be from the node corresponding to the component referenced by the parent :code:`component_ref` element, and to the node corresponding to the component referenced by the child :code:`component_ref` element.

.. marker_interpretation_of_encapsulation_1
.. _specC_encapsulation_set:

3. The "encapsulated set" for a component *A* SHALL be the set of all components *B* such that there exists an arc in the encapsulation digraph from the node corresponding to *A* to the node corresponding to *B*.

.. _specC_encapsulation_parent:

4. The "encapsulation parent" for a component *A* SHALL be the component corresponding to the node which is the parent node in the encapsulation digraph of the node corresponding to *A*.
   A component SHALL NOT appear as child of more than one encapsulation parent.

.. _specC_sibling_set:

5. The "sibling set" for a component *A* SHALL be the set of all components which have the same encapsulation parent as *A*, or in the case that *A* has no encapsulation parent, SHALL be the set of all components which do not have an encapsulation parent.

.. _specC_hidden_set:

6. The "hidden set" for a component *A* SHALL be the set of all components *B* where component *B* is not in the encapsulated set for component *A*, and component *B* is not the encapsulation parent of component *A*, and component *B* is not in the sibling set for component *A*.

.. marker_interpretation_of_encapsulation_2

.. marker_interpretation_of_encapsulation_end
.. marker_interpretation_of_map_variables_start

.. _specC_interpretation_of_map_variables:

Interpretation of ``map_variables`` elements
--------------------------------------------

1.  For the purposes of this specification, the conceptual "variable equivalence network" SHALL be an undirected graph with one node for every :code:`variable` element in the :ref:`CellML model<specA_cellml_model>`.
    The arcs of this graph SHALL be equivalences defined in the CellML model.

.. marker_interpretation_of_map_variables_1

2.  For each :code:`map_variables` element present in the CellML model, we define variables *A* and *B* for use in the rules in this section as follows:

    #. Variable *A* SHALL be the variable referenced by the encompassing :code:`connection` element’s :code:`component_1` and this :code:`map_variables` element’s :code:`variable_1` attribute; and

    #. Variable *B* SHALL be the variable referenced by the encompassing :code:`connection` element’s :code:`component_2` and this :code:`map_variables` element’s :code:`variable_2` attribute.

3.  For every :code:`map_variables` element present in the CellML model, there SHALL be an arc in the variable equivalence network.

    #. One endpoint of the arc in the variable equivalence network SHALL be the node corresponding to variable *A*; and

    #. One endpoint of the arc in the variable equivalence network SHALL be the node corresponding to variable *B*.

.. marker_interpretation_of_map_variables_2

4.  CellML models MUST NOT contain any pair of :code:`map_variables` elements which duplicates an existing arc in the variable equivalence network.

5.  The variable equivalence network MUST NOT contain any cycles.

.. _specC_equivalent_variables_units:
.. marker_interpretation_of_map_variables_3

6.  For a given variable, the "available interfaces" SHALL be determined by the value of the :code:`interface` attribute on the corresponding :code:`variable` element as follows:

    #. A value of :code:`public` specifies that the variable has a public interface;

    #. A value of :code:`private` specifies that the variable has a private interface;

    #. A value of :code:`public_and_private` specifies that the variable has both a public and a private interface;

    #. A value of :code:`none` specifies that the variable has no interface; or

    #. If the :code:`interface` attribute is absent, then the variable has no interface.

7.  The "applicable interfaces" for variables *A* and *B* in components *AA* and *BB* respectively SHALL be defined as follows:

    #. When component *AA* is in the :ref:`sibling set<specC_sibling_set>` of component *BB* (and vice versa), the applicable interface for both variables *A* and *B* SHALL be the public interface.

    #. When component *AA* is in the :ref:`encapsulated set<specC_encapsulation_set>` of component *BB*, the applicable interface for variable *A* SHALL be the public interface, and the applicable interface for variable *B* SHALL be the private interface.

    #. When component *BB* is in the :ref:`encapsulated set<specC_encapsulation_set>` of component *AA*, the applicable interface for variable *B* SHALL be the public interface, and the applicable interface for variable *A* SHALL be the private interface.

    It is noted, for the avoidance of doubt, that if components *AA* and *BB* are in each other's :ref:`hidden set<specC_hidden_set>`, there are no applicable interfaces for the variables *A* and *B*.

8.  CellML models MUST only contain :code:`map_variables` elements where the applicable interfaces for both variables are available.

.. marker_interpretation_of_map_variables_4

9.  For each :code:`map_variables` element present in the CellML model, the variable unit reduction (see :numref:`{number} {name}<specC_effect_of_units_on_variables>`) of variable *A* MUST have an identical set of tuples to the variable unit reduction of variable *B*.
    Two sets of tuples SHALL be considered identical if all of the tuples from each set are present in the other, or if both sets are empty.
    Two tuples are considered identical if and only if both the unit name and exponent of each tuple are identical.

10.  Tuples differing by a multiplying factor in their unit reduction MUST be taken into account when interpreting the numerical values of the variables (see :numref:`{number} {name}<specC_interpretation_of_units>`).

.. marker_interpretation_of_map_variables_5
.. _specC_equivalent_variable_set:

11.  The :code:`variable` elements in a CellML model SHALL be treated as belonging to a single "equivalent variable set".
     Each set of equivalent variables is the set of all :code:`variable` elements for which the corresponding nodes in the variable equivalence network form a connected subgraph.
     Each set of equivalent variables represents one variable in the underlying mathematical model.

.. marker_interpretation_of_map_variables_end
.. marker_interpretation_of_resets_start

Interpretation of ``reset`` elements
------------------------------------

1. For the purposes of this section, we define the "reset variable" to be the variable referenced by a :code:`reset` element's :code:`variable` attribute, and the "test variable" to be the variable referenced by its :code:`test_variable` attribute.

2. Each :code:`reset` element describes a change to be applied to the reset variable when specified conditions are met during the simulation of the model.

.. marker_interpretation_of_resets_1

3. All :code:`reset` elements SHALL be considered sequentially for the equivalent variable set (see :numref:`{number} {name}<specC_interpretation_of_map_variables>`) to which the reset variable belongs.
   The sequence SHALL be determined by the value of the reset element’s :code:`order` attribute, lowest (least positive / most negative) having priority.

.. marker_interpretation_of_resets_2

4. The condition under which a reset occurs SHALL be defined by the equality of evaluation of the test variable and the evaluation of the MathML expression encoded in the :code:`test_value`.

5. When a reset occurs, the reset variable SHALL be set to the result of evaluating the MathML expression encoded in the :code:`reset_value`.

.. marker_interpretation_of_resets_end
