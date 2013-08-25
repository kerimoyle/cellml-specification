Definitions
===========

The key words "MUST", "MUST NOT", "REQUIRED", "SHALL", "SHALL NOT",
"SHOULD", "SHOULD NOT", "RECOMMENDED", "MAY", and "OPTIONAL" in this
document are to be interpreted as described in `RFC 2119 <http://www.ietf.org/rfc/rfc2119.txt>`_.

The key phrase "information item", as well as any specific type of
information item such as an "element information item", are to be
interpreted as described in `XML Information Set <http://www.w3.org/TR/2004/REC-xml-infoset-20040204/>`_.

CellML infoset
    An XML information set containing a hierarchy of information items
    conforming to the rules described in this document.

CellML model
    A mathematical model represented by a hierarchy of one or more
    CellML infosets, according to the rules described in this document.

CellML processing software
    Software which processes CellML in accordance with the rules of this
    document.

Namespace
    An XML namespace, as defined in `Namespaces in XML <http://www.w3.org/TR/2006/REC-xml-names-20060816/>`_.

CellML namespace
    Any namespace starting with ``http://www.cellml.org/cellml/``.

CellML 1.0 namespace
    The namespace ``http://www.cellml.org/cellml/1.0#``.

CellML 1.1 namespace
    The namespace ``http://www.cellml.org/cellml/1.1#``.

CellML 1.2 namespace
    The namespace ``http://www.cellml.org/cellml/1.2#``.

MathML namespace
    The namespace ``http://www.w3.org/1998/Math/MathML``.

RDF namespace
    The namespace ``http://www.w3.org/1999/02/22-rdf-syntax-ns#``.

CellML metadata namespace
    The namespace ``http://www.cellml.org/metadata/1.0#``.

Extension namespace
    Any namespace which is not a CellML namespace, and is not the RDF
    namespace, the MathML namespace, ``http://www.w3.org/XML/1998/namespace``,
    ``http://www.w3.org/2000/xmlns/``, ``http://www.w3.org/1999/xlink``,
    or the empty namespace.

CellML information item
    Any information item in a CellML namespace.

Basic Latin alphabetic character
    A Unicode character in the range `U+0041 <http://www.fileformat.info/info/unicode/char/0041/index.htm>`_
    to `U+005A <http://www.fileformat.info/info/unicode/char/005A/index.htm>`_ or in the range
    `U+0061 <http://www.fileformat.info/info/unicode/char/0061/index.htm>`_ to
    `U+007A <http://www.fileformat.info/info/unicode/char/007A/index.htm>`_.

European numeric character
    A Unicode character in the range `U+0030 <http://www.fileformat.info/info/unicode/char/0030/index.htm>`_
    to `U+0039 <http://www.fileformat.info/info/unicode/char/0039/index.htm>`_.

Basic Latin alphanumeric character
    A Unicode character which is either a basic Latin alphabetic
    character or a European numeric character.

Basic Latin underscore
    The Unicode character `U+005F <http://www.fileformat.info/info/unicode/char/005F/index.htm>`_.

Whitespace character
    Any one of the Unicode characters `U+0020 <http://www.fileformat.info/info/unicode/char/0020/index.htm>`_,
    `U+0009 <http://www.fileformat.info/info/unicode/char/0009/index.htm>`_,
    `U+000D <http://www.fileformat.info/info/unicode/char/000D/index.htm>`_ or
    `U+000A <http://www.fileformat.info/info/unicode/char/000A/index.htm>`_.

RDF triple
    As defined in `RDF Concepts and Abstract Syntax <http://www.w3.org/TR/2004/REC-rdf-concepts-20040210/>`_.
