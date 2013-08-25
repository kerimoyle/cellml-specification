The ``import component`` element information item
=================================================

``import component`` element information items (referred to in this
specification as ``import component`` elements) are element information
items in the CellML namespace with local name equal to ``component``,
which appear as children of ``import`` elements.

Specific information items
--------------------------

1. Every ``import component`` element MUST contain a ``name`` attribute
   in the empty namespace. The value of the ``name`` attribute MUST be
   a valid CellML identifier. The value of the ``name`` attribute MUST
   NOT be identical to the ``name`` attribute of any other ``component``
   element or ``import component`` element in the CellML infoset.

2. Every ``import component`` element MUST contain a ``component_ref``
   attribute in the empty namespace. The value of the ``component_ref``
   attribute MUST be a valid CellML identifier. The value of the
   ``component_ref`` attribute MUST match the value of the ``name`` attribute
   on a ``component`` element or ``import component`` element in the
   imported CellML infoset. The value of the ``component_ref`` attribute
   MUST NOT match the value of the ``component_ref`` attribute on any
   sibling ``import component`` element.
