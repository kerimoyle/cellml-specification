The ``map_components`` element information item
===============================================

``map_components`` element information items (referred to in this
specification as ``map_components`` elements) are element information items
in the CellML namespace with local name equal to ``map_components``, and
which appear as a child of a ``connection`` element.

Specific information items
--------------------------

1. Each ``map_components`` element MUST contain a ``component_1`` attribute
   in the empty namespace.
   The value of the ``component_1`` attribute MUST be a valid CellML
   identifier. The value of this attribute MUST be equal to the ``name``
   attribute on a ``component`` or ``import component`` element in the CellML
   infoset.

2. Each ``map_components`` element MUST contain a ``component_2`` attribute
   in the empty namespace.
   The value of the ``component_2`` attribute MUST be a valid CellML
   identifier. The value of this attribute MUST be equal to the ``name``
   attribute on a ``component`` or ``import component`` element in the CellML
   infoset. It MUST NOT be equal to the value of the ``component_1``
   attribute.
