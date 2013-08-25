The ``import units`` element information item
=============================================

``import units`` element information items (referred to in this
specification as ``import units`` elements) are element information items in
the CellML namespace with local name equal to ``units``, which appear as
children of ``import`` elements.

Specific information items
--------------------------

1. Every ``import units`` element MUST contain a ``name`` attribute in the
   empty namespace. The value of the ``name`` attribute MUST be a valid CellML
   identifier. The value of the ``name`` attribute MUST NOT be identical to
   the ``name`` attribute of any other ``units`` element or ``import units``
   element in the CellML infoset.

2. Every ``import units`` element MUST contain a ``units_ref`` attribute in
   the empty namespace. The value of the ``units_ref`` attribute MUST be a
   valid CellML identifier. The value of the ``units_ref`` attribute MUST
   match the value of the ``name`` attribute on a ``units`` element or
   ``import units`` element in the imported CellML infoset. The value of the
   ``units_ref`` attribute MUST NOT match the value of the ``units_ref``
   attribute on any sibling ``import units`` element.
