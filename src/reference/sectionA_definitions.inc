.. _sectionA:

.. marker_terminology_start

.. _specA_terminology:

Terminology
-----------

The keywords "MUST", "MUST NOT", "REQUIRED", "SHALL", "SHALL NOT", "SHOULD", "SHOULD NOT", "RECOMMENDED", "MAY", and "OPTIONAL" in this document are to be interpreted as described in :rfc2119:`RFC 2119 <>`.

The key phrase "information item", as well as any specific type of information item such as an "element information item", are to be interpreted as described in :xml_infoset2004:`XML Information Set <>`.

.. _specA_cellml_infoset:

**CellML infoset:**
An XML information set containing a hierarchy of information items conforming to the rules described in this document.
In this specification such infosets are assumed to be CellML 2.0 infosets.

.. _specA_cellml_model:

**CellML model:**
A mathematical model represented by a hierarchy of one or more CellML infosets, according to the rules described in this document.
In this specification, the topmost CellML infoset in a hierarchy is referred to as the top-level CellML infoset.

.. _specA_namespace:

**Namespace:**
An XML namespace, as defined in :xml_namespace_1_1:`Namespaces in XML 1.1 <>`.

.. _specA_cellml_namespace:

**CellML namespace:** The CellML 2.0 namespace.

.. _specA_cellml2_namespace:

**CellML 2.0 namespace:**
The namespace :cellml2:`http://www.cellml.org/cellml/2.0# <cellml/2.0#>`\.

.. _specA_mathml_namespace:

**MathML namespace:**
The namespace http://www.w3.org/1998/Math/MathML.

.. _specA_cellml_information_item:

**CellML information item:**
Any information item in the :ref:`CellML namespace<specA_cellml_namespace>`.

.. _specA_basic_latin_alphabetic_character:

**Basic Latin alphabetic character:**
A Unicode character in the range :unicode:`0041` to :unicode:`005A` or in the range :unicode:`0061` to :unicode:`007A`.

.. _specA_digit:

**Digit:**
A Unicode character in the range :unicode:`0030` to :unicode:`0039`.

.. _specA_basic_latin_alphanumeric_character:

**Basic Latin alphanumeric character:**
A Unicode character which is either a :ref:`Basic Latin alphabetic character<specA_basic_latin_alphabetic_character>` or a :ref:`digit<specA_digit>`.

.. _specA_basic_latin_underscore:

**Basic Latin underscore:**
The Unicode character :unicode:`005F`.

.. _specA_basic_latin_plus:

**Basic Latin plus:**
The Unicode character :unicode:`002B`.

.. _specA_basic_latin_minus:

**Basic Latin minus:**
The Unicode character :unicode:`002D`.

.. _specA_basic_latin_full_stop:

**Basic Latin full stop:**
The Unicode character :unicode:`002E`.

.. _specA_whitespace_character:

**Whitespace character:**
Any one of the Unicode characters :unicode:`0020`, :unicode:`0009`, :unicode:`000D`, or :unicode:`000A`.

.. marker_terminology_end
.. marker_cellml_information_sets_start

.. _specA_cellml_information_sets:

CellML information sets
-----------------------

CellML and XML
~~~~~~~~~~~~~~

#. Every CellML infoset SHALL be represented in an XML information set which conforms with the well-formedness requirements of :xml_1_1:`XML 1.1 <>`.

#. In this document, the remaining provisions relating to CellML infosets SHALL be interpreted as additional constraints on the XML information set represented by a CellML infoset.

Specific information items
~~~~~~~~~~~~~~~~~~~~~~~~~~

#. For the purposes of this specification, a specific information item is one of the following (see :xml_infoset:` ` for definitions):

   #. A document information item;

   #. An element information item;

   #. An attribute information item;

   #. A processing instruction information item;

   #. An unexpanded entity reference information item;

   #. A document type declaration information item;

   #. An unparsed entity information item;

   #. A notational information item.

#. Specific information items MUST NOT appear in a CellML infoset except where explicitly allowed by this specification, or where allowed by a normative specification referenced by this specification.

#. The order in which specific information items appear, as children of an element information item defined in this specification, SHALL NOT affect the semantic interpretation of the :ref:`CellML model<specA_cellml_model>`.

.. marker_cellml_information_sets_2

.. _specA_semantic_equivalence:

Non-specific information items
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

1. For the purposes of this specification, a non-specific information item is one of the following (see :xml_infoset:`https://www.w3.org/TR/xml-infoset/ <>` for definitions):

   #. A comment information item;

   #. A namespace information item;

   #. A character information item.

2. An element information item in the :ref:`CellML namespace<specA_cellml_namespace>` MUST NOT contain any character information items, except for character information items which consist entirely of whitespace characters.

.. marker_cellml_information_sets_3

3. Two :ref:`CellML infosets<specA_cellml_infoset>` SHALL be deemed semantically equivalent if one can be transformed into the other by making any or none of the following changes:

   #. Adding, removing, and/or modifying comment information items.

   #. Changing (inserting, removing, and/or modifying) one or more namespace information items, and/or modifying the prefix of one or more information items, without changing the namespace that any information item is in.

   #. The following paragraph applies to character information items which are the direct child of an element information item in the :ref:`CellML namespace<specA_cellml_namespace>`, or in the :ref:`MathML namespace<specA_mathml_namespace>`:

      Inserting or removing character information items that consist entirely of :ref:`whitespace characters<specA_whitespace_character>`,
      changing the number of whitespace characters in such an information item,
      or changing the number of whitespace characters at the beginning or end of any character information item.

.. marker_cellml_information_sets_4

Use of namespaces
~~~~~~~~~~~~~~~~~

#. Element information items in a :ref:`CellML infoset<specA_cellml_infoset>` MUST belong to one of the following namespaces, unless explicitly indicated otherwise:

   #. The :ref:`CellML namespace<specA_cellml_namespace>`

   #. The :ref:`MathML namespace<specA_mathml_namespace>`

#. Attribute information items in a CellML element MUST NOT be prefixed with a namespace, unless explicitly indicated otherwise.

XML ID Attributes
~~~~~~~~~~~~~~~~~

#. Any element information item in the :ref:`CellML namespace<specA_cellml_namespace>` MAY contain an attribute with local name :code:`id.`
   This attribute SHALL be treated as having attribute type ID, as defined in `section 3.3.1 <http://www.w3.org/TR/xml11/#sec-attribute-types>`__ of `XML 1.1 <http://www.w3.org/TR/xml11/>`__.

.. marker_cellml_information_sets_end
.. marker_data_formats_start

.. _specA_data_representation_formats:

Data representation formats in CellML
-------------------------------------

The following data representation formats are defined for use in this specification:

.. _specA_cellml_identifier:

1. A CellML identifier:

   .. container:: issue-data-repr-identifier-unicode

      1. SHALL consist of a single :ref:`Basic Latin alphabetic character<specA_basic_latin_alphabetic_character>`, which MAY be followed by any combination of :ref:`Basic Latin alphanumeric characters<specA_basic_latin_alphanumeric_character>` and/or :ref:`Basic Latin underscores<specA_basic_latin_underscore>`.

   .. container:: issue-data-repr-identifier-identical

      2. SHALL, when comparing two identifiers, be considered identical to another identifier if and only if both identifiers are identical sequences of characters.

.. marker_data_formats_1

.. _specA_integer:

2. An integer string:

   .. container:: issue-data-repr-int-base10

      1. SHALL be a base 10 representation of an integer.

   .. container:: issue-data-repr-int-sign

      2. MAY begin with a single Basic Latin plus character :unicode:`002B` or a Basic Latin hyphen-minus character :unicode:`002D` as the sign indicator.

   .. container:: issue-data-repr-int-euro-num

      3. SHALL, other than the sign indicator, consist of one or more :ref:`digits<specA_digit>`.

.. marker_data_formats_2

.. _specA_basic_real_number:

3. A basic real number string:

   .. container:: issue-data-repr-basic-real-base10

      1. SHALL be a base 10 representation of a real number.

   .. container:: issue-data-repr-basic-real-sign

      2. MAY begin with a single Basic Latin plus character :unicode:`002B` or a Basic Latin hyphen-minus character :unicode:`002D` as the sign indicator.

   .. container:: issue-data-repr-basic-real-decimal

      3. MAY contain a single decimal point separator, which SHALL be the Basic Latin full stop character :unicode:`002E`.

   .. container:: issue-data-repr-basic-real-euro-num

      4. SHALL, other than the sign indicator and the decimal point separator, consist of one or more :ref:`digits<specA_digit>`.

.. marker_data_formats_3

.. _specA_real_number:

4. A real number string:

   .. container:: issue-data-repr-real-base10

      1. SHALL be a base 10 representation of a real number :math:`r=s \times 10^e` where :math:`s` is the significand, a real number, and :math:`e` is the exponent, an integer.

   .. container:: issue-data-repr-real-repr

      2. The representation of the number SHALL be the representation of the significand, optionally followed by a representation of the exponent.

   .. container:: issue-data-repr-real-significand

      3. The significand SHALL be represented as a :ref:`basic real number string<specA_basic_real_number>`.

   .. container:: issue-data-repr-real-exponent

      4. An exponent SHALL be represented by an exponent separator character, followed by the :ref:`integer string representation<specA_integer>` of the value of the exponent.
         The exponent separator character SHALL be either the Basic Latin "E" character :unicode:`0045` or the Basic Latin "e" character :unicode:`0065`.

   .. container:: issue-data-repr-real-no-exponent

      5. If the exponent representation is omitted, the exponent shall be zero.

.. marker_data_formats_end
