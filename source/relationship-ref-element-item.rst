The ``relationship_ref`` element information item
==================================================

``relationship_ref`` element information items (referred to in this
specification as ``relationship_ref`` elements) are element information
items in the CellML namespace with local name equal to ``relationship_ref``.

Specific information items
--------------------------

1. Every ``relationship_ref`` element MUST contain exactly one attribute
   information item with local name ``relationship``. This limit of one
   attribute information item SHALL apply without regard to the
   namespace in which the attribute information item is, and SHALL, to the
   extent that it conflicts, override the ordinary rules for extension
   information items.

2. In the event that the ``relationship`` attribute is in the empty
   namespace, it MUST either take the value ``encapsulation`` or ``containment``.

3. There MUST NOT exist a sibling ``relationship_ref`` element such that
   the namespace of the ``relationship`` attribute on the sibling element
   is identical to the namespace of the ``relationship`` attribute on this
   element, and the value of the ``relationship`` attribute on the sibling
   element is identical to the value of the ``relationship`` attribute on
   this element.

4. A ``relationship_ref`` element MAY contain an attribute in the empty
   namespace with local name ``name``. In this case, it MUST NOT have a
   ``relationship`` attribute in the empty namespace with value ``encapsulation``.
   The value of the ``name`` attribute MUST be a valid CellML identifier.
