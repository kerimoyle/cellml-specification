General matters
===============

CellML and XML
--------------

1. Every CellML infoset SHALL be represented in an XML document which
   conforms with the well-formedness requirements of the `XML 1.0
   <http://www.w3.org/TR/REC-xml/>`_.

2. In this document, the remaining provisions relating to CellML
   infosets shall be interpreted as being constraints on the XML
   information set represented by that CellML infoset.

Equivalent CellML infosets
--------------------------

1. Two CellML infosets shall be equivalent if one can be transformed to
   another by making zero or more of the following changes:

   a. Changing the representation of the XML file in ways which do not
      change the XML information set represented.

   b. Adding, removing, and/or modifying comment information items.

   c. Changing (inserting, removing, and/or modifying) one or more
      namespace information items, and/or modifying the prefix of one or
      more information items, without changing the namespace that any
      information item is in.

   d. The following paragraph applies only to character information
      items which are the direct child of an element information item in
      a CellML namespace, or in the MathML or RDF namespace.

      Inserting or removing character information items that consist
      entirely of whitespace characters, changing the number of
      whitespace characters in such an information item, or changing the
      number of whitespace characters at the beginning or end of a
      character information item.

2. CellML processing software MUST treat CellML infosets which are
   equivalent according to the above rules in an identical fashion.

Character information items
---------------------------

An element information item in the CellML namespace MUST NOT contain any
character information items, except for character information items
which consist entirely of whitespace characters.

Use of namespaces
-----------------

1. CellML infosets MUST NOT contain any element or attribute information
   items, except as permitted in this specification.

2. CellML infosets MUST NOT contain any character information items
   which are children of element information items in a CellML
   namespace, except as permitted in this specification.

3. CellML processing software SHOULD NOT attempt to process CellML
   infosets which contain information items in a CellML namespace other
   than the CellML 1.0, CellML 1.1 and CellML 1.2 namespaces.

4. CellML infosets MUST NOT contain any element information items in the
   RDF namespace, unless:

   a. The element information item or one of its ancestors is an element
      information item in the RDF namespace, with local name
      ``RDF`` (the RDF element information item); and
   b. The RDF element information item forms the top-level of a valid
      RDF/XML tree, per `production 7.2.9 <http://www.w3.org/TR/2004/REC-rdf-syntax-grammar-20040210/#RDF>`_
      in `RDF/XML Syntax Specification <http://www.w3.org/TR/2004/REC-rdf-syntax-grammar-20040210/>`_.

5. CellML infosets MUST NOT contain any element information items in the
   MathML namespace, unless:

   a. The element information item or one of its ancestors is an element
      information item in the MathML namespace, with local name
      ``math`` (the math element information item); and
   b. The math element information item forms the top-level of a valid
      MathML tree, as described in `MathML 2.0 <http://www.w3.org/TR/2003/REC-MathML2-20031021/>`_.

Extension information items
---------------------------

1. CellML infosets MAY contain zero or more element or attribute
   information items in an extension namespace (extension information
   items), as children of CellML information items.

2. Information items in the empty namespace, which appear as children of
   extension element information items, SHALL also be treated as
   extension information items.

3. Extension information items MAY contain extension information items
   as their children. In addition, extension elements MAY contain
   presentation MathML children. For the avoidance of doubt, it is noted
   that extension information items MAY also contain any other
   information items not disallowed by this specification or a
   referenced normative specification.

4. CellML processing software MUST NOT raise an error solely because it
   encounters an unrecognised extension element.

5. CellML processing software which reads CellML and then writes a
   modified version back out SHOULD preserve unrecognised extension
   information items when the parent information item is not modified.

6. CellML processing software MUST NOT allow the mathematical
   interpretation of a CellML model to be altered by any information
   present in extension information items.

7. For the avoidance of doubt, extension information items MUST NOT
   contain CellML information items as descendents.

Identifiers
-----------

1. Any element information item in the CellML namespace MAY contain an
   attribute information item with local name ``id``, in the CellML metadata
   namespace. This attribute information item SHALL be treated as having
   attribute type ID, as defined in `section 3.3.1 <http://www.w3.org/TR/REC-xml/#sec-attribute-types>`_
   of `XML 1.0 <http://www.w3.org/TR/REC-xml/>`_.

Specific information items
--------------------------

1. A specific information item is an information item which is not:

   a. A comment information item;

   b. A character information item;

   c. An extension information item or a descendant of such an
      information item; or

   d. A namespace information item.

2. Specific information items MUST NOT appear in a CellML infoset except
   where explicitly allowed by this specification, or where allowed by a
   normative specification referenced by this specification.

3. The order in which specific information items appear as children of
   an element information item defined in this specification SHALL NOT
   affect the interpretation of the CellML model.

RDF element information items
-----------------------------

1. Every element information item in the CellML namespace MAY contain
   zero or more RDF element information item children.

2. An RDF element information item SHALL be an element item in the RDF
   namespace, with local name ``RDF`` (the RDF element information
   item), and MUST form the top-level of a valid RDF/XML tree, per
   `production 7.2.9 <http://www.w3.org/TR/2004/REC-rdf-syntax-grammar-20040210/#RDF>`_
   in `RDF/XML Syntax Specification <http://www.w3.org/TR/2004/REC-rdf-syntax-grammar-20040210/>`_.

3. An RDF element information item MUST NOT appear in a CellML infoset
   except as allowed by rule 1 above.

.. todo::

    Find out which rule 1 we are we talking about here. Andre: it is the rule 1 just here (2.8.1 currently) but need to work out how to properly reference other rules. Probably shouldn't rely on section numbers being consistent.

4. CellML processing software MUST NOT allow the mathematical
   interpretation of a CellML model to be altered by any information
   present in RDF data.

5. The set of all RDF triples associated with a CellML infoset SHALL
   refer to the union of all sets of RDF triples produced by parsing all
   the RDF element information items according to the `RDF/XML Syntax
   Specification <http://www.w3.org/TR/2004/REC-rdf-syntax-grammar-20040210/>`_.

6. Two CellML infosets which differ only by the addition, removal, or
   modification of RDF element information items (or information items
   descended from them), but which have the same set of all RDF triples,
   SHALL be termed RDF-equivalent CellML infosets.

7. CellML processing software MUST NOT treat RDF-equivalent CellML
   infosets differently.
