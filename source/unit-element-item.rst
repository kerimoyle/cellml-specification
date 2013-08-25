The ``unit`` element information item
=====================================

``unit`` element information items (referred to in this specification as
``unit`` elements) are element information items in the CellML namespace
with local name equal to ``unit``, and with a ``units`` element as their parent.

Specific information items
--------------------------

1. Every ``unit`` element MUST contain a ``units`` attribute information item in
   the empty namespace. The value of the ``units`` attribute MUST be a valid
   units reference, as defined in the :ref:`units-reference` section.

   a. The ``units`` element inclusion digraph SHALL be a conceptual digraph
      defined for the purpose of the constraint in the next paragraph,
      and SHALL contain one node for every ``units`` element in the CellML
      model. The ``units`` element inclusion digraph SHALL contain an arc
      from ``units`` element *A* to ``units`` element *B* if and only if ``units``
      element *A* contains a ``unit`` element with ``units`` attribute value that
      is a units reference to ``units`` element *B*.

   b. The value of the ``units`` attribute MUST NOT be such that the ``units``
      element inclusion digraph contains one or more cycles.

2. A ``unit`` element MAY contain any of the following attribute information
   items in the empty namespace:

   a. The ``prefix`` attribute. If present, the value of the attribute MUST
      meet the constraints specified in the :ref:`interpretation-of-units` section.

   b. The ``offset`` attribute. If present, the value of the attribute MUST
      be a real number string. If the attribute is present and has value
      other than a real number string representing ``0``, then this ``unit``
      element MUST NOT have any sibling ``unit`` elements, and the value of
      the ``exponent`` attribute, if present, MUST be a real number string
      representing ``1``.

   c. The ``multiplier`` attribute. If present, the value of the attribute
      MUST be a real number string.

   d. The ``exponent`` attribute. If present, the value of the attribute
      MUST be a real number string.
