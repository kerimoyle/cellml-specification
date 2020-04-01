.. _inform1:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Namespaces

    Namespaces are a way of making sure that names and definitions are interpreted within the right frame of reference.  In CellML, two namespaces are used.  These are the CellML namespace itself (which helps to define the :code:`units` elements as distinct from the XML default units system) and the MathML namespace used to interpret the :code:`<math>` elements.  For more information on namespaces in general, please refer to the :namespace_help:`W3 schools namespace page <>`.  For more information on the MathML namespace please refer to the :mathml2help:`W3 MathML namespace <#inferf.namespace>` page.
    
    .. container:: heading3

      Unicode, Basic Latin, and European numerals

    The Unicode project is an attempt to codify all of the symbols - alphabets, writings, even emojis - of all the languages of the world so that they can be interchangeable and interpreted by computers.  Since computers understand numbers rather than symbols, each character in each language is given an unique numerical code.  The codes themselves are arranged into blocks representing sets or alphabets of characters, and the Basic Latin alphabet is one of these.  It contains the upper and lowercase alphabet without decoration:

      :code:`abcdefghijklmnopqrstuvwxyz` (symbols between U+0061 and U+007A)
      :code:`ABCDEFGHIJKLMNOPQRSTUVWXYZ` (symbols between U+0041 and U+005A)

    The European numerals are the Unicode set:

      :code:`0123456789` (symbols between U+0030 and U+0039)

    In addition, CellML recognises four special characters:

      :code:`+` the plus sign (U+002B)
      :code:`-` the minus sign (U+002D)
      :code:`_` the underscore (U+005F)
      :code:`.` the fullstop (U+002E)

    and the following whitespace characters: the space (U+0020), the tab (U+0009), the carriage return (U+000D), or the line feed (U+000A).  

    Together these seventy symbols define the only characters which can be interpreted into values for CellML element attributes and content. 

