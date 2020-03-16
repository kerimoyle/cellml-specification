.. _informC03_interpretation_of_units_3_3:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    As discussed in the previous "See more" block, "irreducible" or "base"
    units are those fundamental quantities which cannot be expressed in
    any other way.  This includes user-defined base units too.

    The "unit reduction" of any :code:`units` item is simply a recipe for how
    any units are constructed, from these "base unit" ingredients.  

    For example, the units "metres per second" could be written :math:`m/s` or
    :code:`product[ (metre)^1 , (second)^-1 ]`, or
    :code:`product[ power(metre, 1) , power(second, -2) ]`.  This final list of
    tuples, representing the base unit and its exponent, is referred to as the
    unit reduction tuples for the :code:`units` element.  Some other examples
    are given below.

    Related to C03.3.2.1:

    .. code-block:: xml

        <!-- Unit reduction: [ (metre, 1), (second, -1) ] -->
        <units name="metres_per_second">
          <unit units="metre">
          <unit units="second" exponent="-1>
        </units>

    Related to C03.3.2.2:

    .. code-block:: xml

        <!-- Unit reduction: [ (kilogram, 1), (metre, 2), (second, -3) ]
             This is because Joules are equivalent to kg⋅m2⋅s−2, and the extra
             "per second" takes the effective exponent for "second" to -3. -->
        <units name="joules_per_second">
          <unit units="joule" />
          <unit units="second" exponent="-1" />
        </units>

    Related to C03.3.2.3:

    .. code-block:: xml

        <!-- Unit reduction: [ (apple, 1), (metre, -3) ]
             The concentration of apples per litre of cider is expressed using
             the custom base units "apple", the custom derived units
             "bushell_of_apples" and the built-in convenience units of 
             "litre", the last being equivalent to cubic metres.
             Note that: 
             - scaling does not affect the unit reduction tuples, and
             - the custom units "bushell_of_apples" does not appear, as it is not an irreducible unit 
        -->

        <units name="apple" />

        <units name="bushell_of_apples">
          <unit units="apple" multiplier="1000" />
        </units>

        <units name="cider_concentration">
          <unit units="bushell_of_apples" multiplier="0.5" />
          <unit units="litre" exponent="-1" />
        </units>

