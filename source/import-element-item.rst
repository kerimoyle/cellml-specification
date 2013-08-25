The ``import`` element information item
=======================================

``import`` element information items (referred to in this specification as
``import`` elements) are element information items in the CellML namespace
with local name equal to ``import``.

Specific information items
--------------------------

1. Every ``import`` element MUST contain an attribute information item in
   the namespace ``http://www.w3.org/1999/xlink``, and with local name ``href``.
   The value of this attribute SHALL be a valid locator ``href``, as defined
   in `section 5.4 <http://www.w3.org/TR/2001/REC-xlink-20010627/#link-locators>`_
   of the `XLink specification <http://www.w3.org/TR/2001/REC-xlink-20010627/>`_.
   The ``href`` attribute SHALL be treated according to the XLink specification, by applying
   the rules for simple-type elements. When describing an ``import`` element
   or one of its children, the phrase "imported CellML infoset" SHALL
   refer to the CellML infoset obtained by parsing the XML document
   referenced by the ``href`` attribute.

2. Every ``import`` element MAY contain zero or more specific information
   children, each of which MUST be of one of the following types:

   a. An ``import units`` element; or

   b. An ``import component`` element.

3. The imported CellML infoset SHALL NOT be equivalent to this CellML
   infoset. Any CellML infoset imported, directly or indirectly, by the
   imported CellML infoset SHALL NOT be equivalent to this CellML infoset.
