The ``map_variables`` element information item
==============================================

``map_variables`` element information items (referred to in this
specification as ``map_variables`` elements) are element information items
in the CellML namespace with local name equal to ``map_variables``, and
which appear as a child of a ``connection`` element.

Specific information items
--------------------------

1. Each ``map_variables`` element MUST contain a ``variable_1`` attribute in
   the empty namespace. The value of the ``variable_1`` attribute MUST be a
   valid CellML identifier. The value of this attribute MUST be equal to the
   ``name`` attribute on a ``variable`` element child of the ``component``
   element referenced by the ``component_1`` attribute on the ``map_components``
   element which is a sibling of this element.

2. Each ``map_variables`` element MUST contain a ``variable_2`` attribute in
   the empty namespace. The value of the ``variable_2`` attribute MUST be a
   valid CellML identifier. The value of this attribute MUST be equal to the
   ``name`` attribute on a ``variable`` element child of the ``component``
   element referenced by the ``component_2`` attribute on the ``map_components``
   element which is a sibling of this element.
