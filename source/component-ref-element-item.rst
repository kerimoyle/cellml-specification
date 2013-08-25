The ``component_ref`` element information item
===============================================

``component_ref`` element information items (referred to in this
specification as ``component_ref`` elements) are element information items
in the CellML namespace with local name equal to ``component_ref``.

Specific information items
--------------------------

1. Every ``component_ref`` element MUST contain an attribute information
   item in the empty namespace and with local name ``component``. The value
   of this attribute MUST be a valid CellML identifier, and MUST match
   the ``name`` attribute on a ``component`` element or an ``import
   component`` element in the CellML infoset.

2. Every ``component_ref`` element MAY in turn contain zero or more
   ``component_ref`` element children.

3. In addition, ``component_ref`` elements which are children of ``group``
   elements MUST contain at least one ``component_ref`` element child.
