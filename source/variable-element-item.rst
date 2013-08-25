The ``variable`` element information item
=========================================

``variable`` element information items (referred to in this specification as
``variable`` elements) are element information items in the CellML namespace
with local name equal to ``variable``, and which appear as a child of a
``component`` element.

Specific information items
--------------------------

1. Every ``variable`` element MUST have each of the following attribute
   information items in the empty namespace:

   a. The ``name`` attribute. The value of the ``name`` attribute MUST be a
      valid CellML Identifier. The value of the ``name`` attribute MUST NOT
      be identical to the ``name`` attribute on any sibling ``variable``
      element.

   b. The ``units`` attribute. The value of the ``units`` attribute MUST be a
      valid CellML Identifier, and MUST meet the constraints described
      in the :ref:`effect-of-units-on-variables` section.

2. Every ``variable`` element MAY contain one or more of the following
   attribute information items in the empty namespace:

   a. The ``public_interface`` attribute. If the attribute is present, it
      MUST have value ``in``, ``out``, or ``none``.

   b. The ``private_interface`` attribute. If the attribute is present, it
      MUST have value ``in``, ``out``, or ``none``. It MUST NOT have value ``in`` if the
      ``public_interface`` attribute also has the value ``in``.

   c. The ``initial_value`` attribute. If the attribute is present, it MUST
      meet the requirements described **HERE**.

.. todo::

   Need to provide a link to where the requirements for the ``initial_value``
   attribute are.
