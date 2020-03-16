.. _informC03_interpretation_of_units_3:

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

    .. code-block:: xml

      <!-- 
           Unit reduction: [ (metre, 1), (second, -1) ] 
      -->
      <units name="metres_per_second">
        <unit units="metre">
        <unit units="second" exponent="-1>
      </units>

      <!-- 
           Unit reduction: [ (kilogram, 1), (metre, 2), (second, -3) ]
           This is because Joules are equivalent to kg⋅m2⋅s−2, and the extra
           "per second" takes the effective exponent for "second" to -3.
      -->
      <units name="joules_per_second">
        <unit units="joule" />
        <unit units="second" exponent="-1" />
      </units>

      <!-- 
           Unit reduction: [ (apple, 1), (metre, -3) ]
           The concentration of apples per litre of cider is expressed using
           the custom base units "apple" and the built-in convenience units of 
           "litre", the latter being equivalent to cubic metres.  Note that 
           scaling does not affect the unit reduction tuples.
      -->
      <units name="apple" />
      <units name="cider_concentration">
        <unit units="apple" multiplier="1000" />
        <unit units="litre" exponent="-1" />
      </units>