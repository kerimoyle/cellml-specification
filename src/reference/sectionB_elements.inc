.. _sectionB:

.. marker_model_start

.. _model:

The ``model`` element
---------------------

The top-level element information item in a :ref:`CellML infoset<specA_cellml_infoset>` MUST be an element in the :ref:`CellML namespace<specA_cellml_namespace>` with a local name equal to :code:`model`.
In this specification, the top-level element is referred to as the :code:`model` element.


.. container:: issue-2-1-1

   1. Every :code:`model` element MUST contain a :code:`name` attribute.

      The value of the :code:`name` attribute MUST be a :ref:`CellML identifier<specA_cellml_identifier>`.

.. marker_model_1

.. container:: issue-2-1-2

   2. A :code:`model` element MAY contain one or more additional specific element children, each of which MUST be of one of the following types:

      #. A :code:`component` element;

      #. A :code:`connection` element;

      #. An :code:`encapsulation` element;

      #. An :code:`import` element; or

      #. A :code:`units` element.


.. marker_model_2

.. container:: issue-2-1-3

   3. A :code:`model` element MUST NOT contain more than one :code:`encapsulation` elements.

.. marker_model_end
.. marker_import_start

.. _import:

The ``import`` element
----------------------

An :code:`import` element information item (referred to in this specification as an :code:`import` element) is an element in the :ref:`CellML namespace<specA_cellml_namespace>` with a local name equal to :code:`import`, which appears as a child of a :code:`model` element.

.. container:: issue-2-2-1

   1. Every :code:`import` element MUST contain an attribute in the namespace :code:`http://www.w3.org/1999/xlink`, with a local name equal to :code:`href`.

      The value of this attribute SHALL be a valid locator :code:`href`, as defined in :xlink:`Section 5.4 <#link-locators>` of the :xlink:`XLink specification <>` [:ref:`6<ref_xlink>`].

      The :code:`href` attribute SHALL be treated according to the :xlink:`XLink specification <>` [:ref:`6<ref_xlink>`], by applying the rules for simple-type elements.

      When describing an :code:`import` element or one of its children, the phrase "imported CellML infoset" SHALL refer to the :ref:`CellML infoset<specA_cellml_infoset>` obtained by parsing the document referenced by the :code:`href` attribute.

.. marker_import_1

.. container:: issue-2-2-2

   2. Every :code:`import` element MAY contain one or more specific element children, each of which MUST be of one of the following types:

      #. An :code:`import component` element; or

      #. An :code:`import units` element.

.. marker_import_2

.. container:: issue-2-2-3

   3. Any :ref:`CellML infoset<specA_cellml_infoset>` imported, directly or indirectly, by the imported CellML infoset MUST NOT be semantically equivalent to the importing CellML infoset (see :ref:`1.2.3.3<specA_semantic_equivalence>` regarding semantic equivalence).

.. hardcodedref above: 1.2.3.3

.. marker_import_end
.. marker_import_units_start

.. _import_units:

The ``import units`` element
----------------------------

An :code:`import units` element information item (referred to in this specification as an :code:`import units` element) is an element in the :ref:`CellML namespace<specA_cellml_namespace>` with a local name equal to :code:`units`, which appears as a child of an :code:`import` element.

.. container:: issue-2-3-1

   1. Every :code:`import units` element MUST contain a :code:`name` attribute.

      The value of the :code:`name` attribute MUST be a :ref:`CellML identifier<specA_cellml_identifier>`.

      The value of the :code:`name` attribute MUST NOT be identical to the value of the :code:`name` attribute of any other :code:`units` or :code:`import units` element in the :ref:`CellML infoset<specA_cellml_infoset>`.

.. marker_import_units_1

.. container:: issue-2-3-2

   2. Every :code:`import units` element MUST contain a :code:`units_ref` attribute.

      The value of the :code:`units_ref` attribute MUST be a :ref:`CellML identifier<specA_cellml_identifier>`.

      The value of the :code:`units_ref` attribute MUST be identical to the value of the :code:`name` attribute on a :code:`units` or :code:`import units` element in the imported :ref:`CellML infoset<specA_cellml_infoset>`.

.. marker_import_units_end
.. marker_import_component_start

.. _import_component:

The ``import component`` element
--------------------------------

An :code:`import component` element information item (referred to in this specification as an :code:`import component` element) is an element in the :ref:`CellML namespace<specA_cellml_namespace>` with a local name equal to :code:`component`, which appears as a child of an :code:`import` element.

.. container:: issue-2-4-1

   1. Every :code:`import component` element MUST contain a :code:`name` attribute.

      The value of the :code:`name` attribute MUST be a :ref:`CellML identifier<specA_cellml_identifier>`.

      The value of the :code:`name` attribute MUST NOT be identical to the value of the :code:`name` attribute of any other :code:`component` or :code:`import component` element in the :ref:`CellML infoset<specA_cellml_infoset>`.

.. container:: issue-2-4-2

   2. Every :code:`import component` element MUST contain a :code:`component_ref` attribute.

      The value of the :code:`component_ref` attribute MUST be a :ref:`CellML identifier<specA_cellml_identifier>`.

      The value of the :code:`component_ref` attribute MUST be identical to the value of the :code:`name` attribute on a :code:`component` or :code:`import component` element in the imported :ref:`CellML infoset<specA_cellml_infoset>`.

.. marker_import_component_end
.. marker_units_start

.. _units:

The ``units`` element
---------------------

A :code:`units` element information item (referred to in this specification as a :code:`units` element) is an element in the :ref:`CellML namespace<specA_cellml_namespace>` with a local name equal to :code:`units`, which appears as a child of a :code:`model` element.

.. _issue_units_name:
.. container:: issue-2-5-1

   1. Every :code:`units` element MUST contain a :code:`name` attribute.

      The value of the :code:`name` attribute MUST be a :ref:`CellML identifier<specA_cellml_identifier>`.

      The value of the :code:`name` attribute MUST NOT be identical to the value of the :code:`name` attribute of any other :code:`units` element or :code:`import units` element in the :ref:`CellML infoset<specA_cellml_infoset>`.

.. container:: issue-2-5-2

   2. The value of the :code:`name` attribute MUST NOT be identical to the name of any of the units listed in :numref:`Table {number}: {name}<table_built_in_units>` (see :numref:`{number} {name}<specC_units_reference>`).

.. container:: issue-2-5-3

   3. A :code:`units` element MAY contain one or more :code:`unit` element children.

.. marker_units_end
.. marker_unit_start

.. _unit:

The ``unit`` element
--------------------

A :code:`unit` element information item (referred to in this specification as a :code:`unit` element) is an element in the :ref:`CellML namespace<specA_cellml_namespace>` with a local name equal to :code:`unit`, which appears as a child of a :code:`units` element.

.. container:: issue-2-6-1

   1. Every :code:`unit` element MUST contain a :code:`units` attribute.

      The value of the :code:`units` attribute MUST be a valid units reference, as defined in :numref:`{number} {name}<specC_units_reference>`.

      .. container:: issue-2-6-1-1

         1. For the purpose of the constraint in the next paragraph, the :code:`units` element inclusion digraph SHALL be defined as a conceptual digraph which SHALL contain one node for every :code:`units` element in the :ref:`CellML model<specA_cellml_model>`.

            The :code:`units` element inclusion digraph SHALL contain an arc from :code:`units` element *A* to :code:`units` element *B* if and only if :code:`units` element *A* contains a :code:`unit` element with a :code:`units` attribute value that is identical to the :code:`name` attribute value of :code:`units` element *B*.

      .. container:: issue-2-6-1-2

         2. The element inclusion digraph MUST NOT contain any cycles.

.. marker_unit_1

.. container:: issue-2-6-2

   2. A :code:`unit` element MAY contain any of the following attributes:

      .. container:: issue-2-6-2-1

         1. The :code:`prefix` attribute. If present, the value of the attribute MUST meet the constraints specified in :numref:`{number} {name}<specC_interpretation_of_units>`.

      .. container:: issue-2-6-2-2

         2. The :code:`multiplier` attribute. If present, the value of the attribute MUST be a :ref:`real number string<specA_real_number>`.

      .. container:: issue-2-6-2-3

         3. The :code:`exponent` attribute. If present, the value of the attribute MUST be a :ref:`real number string<specA_real_number>`.

.. marker_unit_end
.. marker_component_start

.. _component:

The ``component`` element
-------------------------

A :code:`component` element information item (referred to in this specification as a :code:`component` element) is an element in the :ref:`CellML namespace<specA_cellml_namespace>` with a local name equal to :code:`component`, which appears as a child of a :code:`model` element.

.. marker_component_1

.. _issue-component-name:

.. container:: issue-2-7-1

   1. Every :code:`component` element MUST contain a :code:`name` attribute.

      The value of the :code:`name` attribute MUST be a :ref:`CellML identifier<specA_cellml_identifier>`.

      The value of the :code:`name` attribute MUST NOT be identical to the value of the :code:`name` attribute on any other :code:`component` element or :code:`import component` element in the :ref:`CellML infoset<specA_cellml_infoset>`.

.. marker_component_2

.. container:: issue-2-7-2

   2. A :code:`component` element MAY contain one or more specific element children, each of which MUST be of one of the following types:

      #. A :code:`math` element;

      #. A :code:`reset` element; or

      #. A :code:`variable` element.

.. marker_component_end
.. marker_variable_start

.. _variable:

The ``variable`` element
------------------------

A :code:`variable` element information item (referred to in this specification as a :code:`variable` element) is an element in the :ref:`CellML namespace<specA_cellml_namespace>` with a local name equal to :code:`variable`, which appears as a child of a :code:`component` element.

1. Every :code:`variable` element MUST have exactly one of each of the following attributes:

   .. container:: issue-2-8-1-1

      1. The :code:`name` attribute.
         The value of the :code:`name` attribute MUST be a :ref:`CellML identifier<specA_cellml_identifier>`.

         The value of the :code:`name` attribute MUST NOT be identical to the value of the :code:`name` attribute on any sibling :code:`variable` element.

   .. container:: issue-2-8-1-2

      2. The :code:`units` attribute.
         The value of the :code:`units` attribute MUST be a valid units reference, as defined in :numref:`{number} {name}<specC_units_reference>`.

2. Every :code:`variable` element MAY contain one or more of the following attributes:

   .. container:: issue-2-8-2-1

      1. The :code:`interface` attribute.
         If the attribute is present, it MUST have value of :code:`public`, :code:`private`, :code:`public_and_private`, or :code:`none`.

   .. container:: issue-2-8-2-2

      2. The :code:`initial_value` attribute.
         If the attribute is present, it MUST meet the requirements described by :numref:`{number} {name}<specC_interpretation_of_initial_values>`.

.. marker_variable_end
.. marker_reset_start

.. _reset:

The ``reset`` element
---------------------

A :code:`reset` element information item (referred to in this specification as a :code:`reset` element) is an element in the :ref:`CellML namespace<specA_cellml_namespace>` with a local name equal to :code:`reset`, which appears as a child of a :code:`component` element.

.. marker_reset_1

1. Every :code:`reset` element MUST have exactly one of each of the following attributes:

   .. container:: issue-2-9-1-1

      1. The :code:`variable` attribute.
         The value of the :code:`variable` attribute MUST be a valid variable reference, as defined in :numref:`{number} {name}<specC_variable_reference>`.

   .. container:: issue-2-9-1-2

      2. The :code:`test_variable` attribute.
         The value of the :code:`test_variable` attribute MUST be a valid variable reference, as defined in :numref:`{number} {name}<specC_variable_reference>`.

.. marker_reset_2

   .. container:: issue-2-9-1-3

      3. The :code:`order` attribute.
         The value of the :code:`order` attribute MUST be an :ref:`integer string<specA_integer>`.

         The value of the :code:`order` attribute MUST be unique for all :code:`reset` elements with :code:`variable` attributes that reference variables in the same equivalent variable set (see :numref:`{number} {name}<specC_interpretation_of_map_variables>`).

.. marker_reset_3

.. container:: issue-2-9-2

   2. A :code:`reset` element MUST contain exactly two element children, which MUST be one of each of the following types:

      .. container:: issue-2-9-2-1

         1. A :code:`reset_value` element; and

      .. container:: issue-2-9-2-2

         2. A :code:`test_value` element.

.. marker_reset_end
.. marker_test_value_start

.. _test_value:

The ``test_value`` element
--------------------------

A :code:`test_value` element information item (referred to in this specification as a :code:`test_value` element) is an element in the :ref:`CellML namespace<specA_cellml_namespace>` with a local name equal to :code:`test_value`, which appears as a child of a :code:`reset` element.

.. container:: issue-2-10

   1. A :code:`test_value` element MUST contain exactly one :code:`math` element child.

.. marker_test_value_end
.. marker_reset_value_start

.. _reset_value:

The ``reset_value`` element
---------------------------

A :code:`reset_value` element information item (referred to in this specification as a :code:`reset_value` element) is an element in the :ref:`CellML namespace<specA_cellml_namespace>` with a local name equal to :code:`reset_value`, which appears as a child of a :code:`reset` element.

.. container:: issue-2-11

   1. A :code:`reset_value` element MUST contain exactly one :code:`math` element child.

.. marker_reset_value_end
.. marker_math_start

.. _math:

The ``math`` element
--------------------

A :code:`math` element information item (referred to in this specification as a :code:`math` element) is an element in the MathML namespace, which appears as a child of a :code:`component` element, a :code:`test_value` element, or a :code:`reset_value` element.

.. container:: issue-2-12-1

   1. A :code:`math` element MUST be the top-level element of a Content MathML tree, as described in :mathml2:`MathML 2.0 <>` [:ref:`7<ref_mathml2>`].

.. marker_math_1

.. container:: issue-2-12-2

   2. Each element child of a :code:`math` element MUST have an element-type name that is listed in :numref:`Table {number}: {name}<table_supported_mathml_elements>`.

.. marker_math_2

.. container:: issue-2-12-3

   3. The contents of a MathML :code:`ci` element MUST be a valid variable reference, as defined in :numref:`{number} {name}<specC_variable_reference>`.

.. marker_math_3

.. container:: issue-2-12-4

   4. A MathML :code:`cn` element MUST have an attribute in the :ref:`CellML namespace<specA_cellml_namespace>`, with a local name equal to :code:`units`.

      The value of the :code:`units` attribute MUST be a valid units reference, as defined in :numref:`{number} {name}<specC_units_reference>`.

.. container:: issue-2-12-5

   5. A :code:`cn` element MUST be base 10, and MUST be of the following :mathml2help:`types<#contm.typeattrib>`\: real or e-notation.


.. marker_math_4

.. _table_supported_mathml_elements:
.. table:: Supported MathML elements
  :widths: auto

  +----------------------------------+------------------------------------------------------------------+
  | **Element Category**             | **Element List**                                                 |
  +----------------------------------+------------------------------------------------------------------+
  | Simple Operands                  | :code:`ci`, :code:`cn`, :code:`sep`                              |
  +----------------------------------+------------------------------------------------------------------+
  | Basic Structural                 | :code:`apply`, :code:`piecewise`, :code:`piece`,                 |
  |                                  | :code:`otherwise`                                                |
  +----------------------------------+------------------------------------------------------------------+
  | Relational and Logical Operators | | :code:`eq`, :code:`neq`, :code:`gt`, :code:`lt`, :code:`geq`,  |
  |                                  | | :code:`leq`, :code:`and`, :code:`or`, :code:`xor`, :code:`not` |
  +----------------------------------+------------------------------------------------------------------+
  | Arithmetic Operators             | | :code:`plus`, :code:`minus`, :code:`times`, :code:`divide`,    |
  |                                  | | :code:`power`, :code:`root`, :code:`abs`,                      |
  |                                  | | :code:`exp`, :code:`ln`, :code:`log`,                          |
  |                                  | | :code:`floor`, :code:`ceiling`,                                |
  |                                  | | :code:`min`, :code:`max`, :code:`rem`                          |
  +----------------------------------+------------------------------------------------------------------+
  | Calculus Elements                | :code:`diff`                                                     |
  +----------------------------------+------------------------------------------------------------------+
  | Qualifier Elements               | :code:`bvar`, :code:`logbase`, :code:`degree` \*                 |
  +----------------------------------+------------------------------------------------------------------+
  | Trigonometric Operators          | | :code:`sin`, :code:`cos`, :code:`tan`, :code:`sec`,            |
  |                                  |   :code:`csc`, :code:`cot`,                                      |
  |                                  | | :code:`sinh`, :code:`cosh`, :code:`tanh`, :code:`sech`,        |
  |                                  |   :code:`csch`, :code:`coth`,                                    |
  |                                  | | :code:`arcsin`, :code:`arccos`, :code:`arctan`,                |
  |                                  | | :code:`arcsec`, :code:`arccsc`, :code:`arccot`,                |
  |                                  | | :code:`arcsinh`, :code:`arccosh`, :code:`arctanh`,             |
  |                                  | | :code:`arcsech`, :code:`arccsch`, :code:`arccoth`              |
  +----------------------------------+------------------------------------------------------------------+
  | Mathematical and Logical         | | :code:`pi`, :code:`exponentiale`,                              |
  | Constants                        |   :code:`notanumber`,                                            |
  |                                  | | :code:`infinity`, :code:`true`, :code:`false`                  |
  +----------------------------------+------------------------------------------------------------------+

\* :code:`degree` MUST be a child of :code:`root` or :code:`diff`

.. marker_math_end
.. marker_encapsulation_start

.. _encapsulation:

The ``encapsulation`` element
-----------------------------

An :code:`encapsulation` element information item (referred to in this specification as an :code:`encapsulation` element) is an element in the :ref:`CellML namespace<specA_cellml_namespace>` with a local name equal to :code:`encapsulation`, which appears as a child of a :code:`model` element.

.. container:: issue-2-15-1

   1. An :code:`encapsulation` element MAY contain one or more :code:`component_ref` element children.

.. marker_encapsulation_end
.. marker_component_ref_start

.. _component_ref:

The ``component_ref`` element
-----------------------------

A :code:`component_ref` element information item (referred to in this specification as a :code:`component_ref` element) is an element in the :ref:`CellML namespace<specA_cellml_namespace>` with a local name equal to :code:`component_ref`, which appears as a child of an :code:`encapsulation` element.

.. container:: issue-2-14-1

   1. Every :code:`component_ref` element MUST contain a :code:`component` attribute.

      The value of the :code:`component` attribute MUST be a valid component reference, as defined in :numref:`{number} {name}<specC_component_reference>`.

      The value of the :code:`component` attribute MUST NOT be identical to the value of the :code:`component` attribute on any other :code:`component_ref` element in the :ref:`CellML infoset<specA_cellml_infoset>`.

.. container:: issue-2-14-2

   2. Every :code:`component_ref` element MAY in turn contain one or more :code:`component_ref` element children.

.. marker_component_ref_end
.. marker_connection_start

.. _connection:

The ``connection`` element
--------------------------

A :code:`connection` element information item (referred to in this specification as a :code:`connection` element) is an element in the :ref:`CellML namespace<specA_cellml_namespace>` with a local name equal to :code:`connection`, which appears as a child of a :code:`model` element.

.. container:: issue-2-15-1

   1. Each :code:`connection` element MUST contain a :code:`component_1` attribute.

      The value of the :code:`component_1` attribute MUST be a valid component reference, as defined in :numref:`{number} {name}<specC_component_reference>`.

.. marker_connection_1

.. container:: issue-2-15-2

   2. Each :code:`connection` element MUST contain a :code:`component_2` attribute.

      The value of the :code:`component_2` attribute MUST be a valid component reference, as defined in :numref:`{number} {name}<specC_component_reference>`.

.. marker_connection_2

.. container:: issue-2-15-3

   3. The value of the :code:`component_1` attribute MUST NOT be identical to the value of the :code:`component_2` attribute.

.. marker_connection_3

.. container:: issue-2-15-4

   4. A :ref:`CellML infoset<specA_cellml_infoset>` MUST NOT contain more than one :code:`connection` element with a given pair of components referenced by the :code:`component_1` and :code:`component_2` attribute values, in any order.

.. marker_connection_4

.. container:: issue-2-15-5

   5. A :code:`connection` element MAY contain one or more :code:`map_variables` element children.

.. marker_connection_end
.. marker_map_variables_start

.. _map_variables:

The ``map_variables`` element
-----------------------------

A :code:`map_variables` element information item (referred to in this specification as a :code:`map_variables` element) is an element in the :ref:`CellML namespace<specA_cellml_namespace>` with a local name equal to :code:`map_variables`, which appears as a child of a :code:`connection` element.

.. container:: issue-2-16-1

   1. Each :code:`map_variables` element MUST contain a :code:`variable_1` attribute.

      The value of the :code:`variable_1` attribute MUST be a valid variable reference, as defined in :numref:`{number} {name}<specC_variable_reference>`.

.. marker_map_variables_1

.. container:: issue-2-16-2

   2. Each :code:`map_variables` element MUST contain a :code:`variable_2` attribute.

      The value of the :code:`variable_2` attribute MUST be a valid variable reference, as defined in :numref:`{number} {name}<specC_variable_reference>`.

.. marker_map_variables_2

.. container:: issue-2-16-3

   3. A :code:`connection` element MUST NOT contain more than one :code:`map_variables` element with a given :code:`variable_1` attribute value and :code:`variable_2` attribute value pair.

.. marker_map_variables_end
