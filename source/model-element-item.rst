The ``model`` element information item
======================================

Top-level of CellML infosets
----------------------------

The top-level element information item in a CellML infoset MUST be an
element information item in the CellML namespace, with local name
``model``. This element information item is referred to in this
specification as the ``model`` element.

Specific information items
--------------------------

1. Every ``model`` element MUST contain a ``name`` attribute in the empty
   namespace. The value of the ``name`` attribute MUST be a valid CellML
   identifier, and SHALL be interpreted as a unique identifier for the
   CellML infoset.

2. A ``model`` element MAY contain zero or more additional specific
   information item children, each of which MUST be of one of the
   following types:

   a. A ``component`` element;

   b. A ``connection`` element;

   c. A ``group`` element;

   d. An ``import`` element; or

   e. A ``units`` element.
