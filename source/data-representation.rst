Data representation formats in CellML
=====================================

The following data representation formats are defined for use in this
specification:

1. A CellML identifier:

   a. SHALL be a sequence of Unicode characters.

   b. SHALL NOT contain any characters except basic Latin alphanumeric
      characters and basic Latin underscores.

   c. SHALL contain one or more basic Latin alphabetic characters.

   d. SHALL NOT begin with a European numeric character.

   e. SHALL, when comparing two identifiers, be considered identical to
      another identifier if and only if both identifiers have identical
      sequences of Unicode character codes.

2. A non-negative integer string:

   a. SHALL be a base 10 representation of a non-negative integer.

   b. SHALL consist entirely of European numeric characters.

3. An integer string:

   a. SHALL be a base 10 representation of an integer.

   b. SHALL, when the integer being represented is negative, consist of
      the basic Latin hyphen-minus character `U+002D
      <http://www.fileformat.info/info/unicode/char/002D/index.htm>`_,
      followed by the non-negative integer string representation of the
      absolute value of the integer.

   c. SHALL, when the integer being represented is non-negative, consist
      of the non-negative integer string representation of the integer.

4. A basic real number string:

   a. SHALL be a base 10 representation of a real number.

   b. SHALL, when the basic real number being represented is negative,
      begin with the basic Latin hyphen-minus character `U+002D
      <http://www.fileformat.info/info/unicode/char/002D/index.htm>`_
      as the sign indicator.

   c. MAY contain a single decimal point separator, which SHALL be the
      basic Latin full stop character `U+002E
      <http://www.fileformat.info/info/unicode/char/002E/index.htm>`_.

   d. SHALL, other than the sign indicator and the decimal point
      separator, consist only of European numeric characters.

5. A real number string:

   a. SHALL be a base 10 representation of a real number
      :math:`r = s \cdot 10^{e}`, where :math:`s` is the significand,
      a real number, and :math:`e` is the exponent, an integer.

   b. The representation of the number SHALL be the representation of
      the significand followed immediately by the representation of the
      exponent.

   c. The significand SHALL be represented as a basic real number
      string.

   d. If the exponent is zero, the exponent MAY be represented by an
      empty string, or MAY be represented according to the following
      rule. If the exponent is non-zero, it MUST be represented
      according to the following rule.

   e. An exponent SHALL be represented by an exponent separator
      character, followed by the integer string representation of the
      value of the exponent. The exponent separator character SHALL be
      either the basic Latin 'E' character `U+0045
      <http://www.fileformat.info/info/unicode/char/0045/index.htm>`_
      or the basic Latin 'e' character `U+0065
      <http://www.fileformat.info/info/unicode/char/0065/index.htm>`_.
