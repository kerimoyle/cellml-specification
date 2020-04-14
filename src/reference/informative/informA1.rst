.. _inform1:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Namespaces

    Namespaces are a way of making sure that names and definitions are interpreted within the right frame of reference.
    In CellML, two namespaces are used.
    These are the CellML namespace itself (which helps to define the :code:`units` elements as distinct from the XML default units system) and the MathML namespace used to interpret the :code:`math` elements.
    For more information on namespaces in general, please refer to the :namespace_help:`W3 schools namespace page <>`, or for the MathML namespace please refer to the :mathml2help:`W3 MathML namespace <#inferf.namespace>` page.

    .. container:: heading3

      Unicode, Basic Latin alphabetical characters, and Digits

    The Unicode project is an attempt to codify all of the symbols - alphabets, writings, even emojis - of all the languages of the world so that they can be interchangeable and interpreted by computers.
    Since computers understand numbers rather than symbols, each character in each language is given a unique numerical code.
    The codes themselves are arranged into blocks representing sets of characters, and the Basic Latin block is one of these.
    It contains, amongst other things, the upper and lowercase alphabet without decoration:

      :code:`abcdefghijklmnopqrstuvwxyz` (symbols between :unicode:`0061` and :unicode:`007A`)
      :code:`ABCDEFGHIJKLMNOPQRSTUVWXYZ` (symbols between :unicode:`0041` and :unicode:`005A`)

    These 2*26 characters are refferd to in CellML as the Basic Latin alphabetic characters.

    The Digits are the Unicode set:

      :code:`0123456789` (symbols between :unicode:`0030` and :unicode:`0039`)

    In addition, CellML recognises four special characters:

    - :code:`+` the plus sign (:unicode:`002B`),
    - :code:`-` the minus sign (:unicode:`002D`),
    - :code:`.` the fullstop or decimal point (:unicode:`002E`),
    - :code:`_` the underscore (:unicode:`005F`),

    and the following whitespace characters:

    - the space (:unicode:`0020`),
    - the tab (:unicode:`0009`),
    - the carriage return (:unicode:`000D`), and
    - the line feed (:unicode:`000A`).

    Together these symbols define the only characters which can be interpreted into values for CellML names and numbers.
