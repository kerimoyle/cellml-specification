.. _informC03_interpretation_of_units_1_1:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Prefixes

    The :code:`prefix` term is different from the other attributes of a :code:`unit` element in that it can accept both a string (the name of the prefix from the :ref:`Prefix table<table_prefix_values>`) or an integer (the base 10 log equivalent to the prefix).
    It's also different because **it will become invalid if a real number is used**.

    For example, these are equivalent:

    .. code-block:: xml

        <!-- This is valid ... -- >
        <unit units="myOtherUnits" prefix="3">

        <!-- ... is the same as ... -->
        <unit units="myOtherUnits" prefix="kilo">

        <!-- ... and the same as this. -->
        <unit units="myOtherUnits" multiplier="1000.0">

        <!-- BUT this is not valid, the prefix MUST be an integer or prefix name only! -->
        <unit units="myOtherUnits" prefix="3.0">

    **Note** that these examples are *only* equivalent because the :code:`exponent` in each case is 1.
    
    .. container:: heading3

      Multipliers and exponents

    As you might expect, both the :code:`exponent` and :code:`multiplier` attributes must be :ref:`valid real numbers<specA_real_number>`, which could include an :ref:`integers<specA_integer>`.
    (This is in contrast to the :code:`prefix` which *must* be an integer or a :ref:`named prefix<table_prefix_values>`.)

    All three attributes can be combined in different ways to give the same effective outcome.
    The examples below all define a :code:`units` item equivalent to a 330 mL bottle of beer.

    .. code-block:: xml

        <!-- The prefix can be an integer or a named prefix -->
        <units name="bottle_of_beer">
            <unit units="metre" prefix="-2" exponent="3.0" multiplier="330"/>
        </units>
        <units name="bottle_of_beer">
            <unit units="metre" prefix="centi" exponent="3.0" multiplier="330"/>
        </units>

        <!--
            Note that exponents are added to the combination of prefix and units terms
            only, not to the muptiplier:
                ie: this is (0.33)*((deci)(metre))^3
        -->
        <units name="bottle_of_beer">
            <unit units="metre" prefix="deci" exponent="3.0" multiplier="0.33"/>
        </units>

        <!-- Missing prefix has no effect -->
        <units name="bottle_of_beer">
            <unit units="metre" exponent="3.0" multiplier="3.3e-4"/
        </units>

        <!--
            Repeated unit items can be included:
                the three centimetres together give 1 mL
                the dimensionless multiplier makes them 330 mL
        -->
        <units name="bottle_of_beer">
            <unit units="metre" prefix="centi"/>
            <unit units="metre" prefix="centi"/>
            <unit units="metre" prefix="centi"/>
            <unit units="dimensionless" multiplier="330.0"/>
        </units>


    **Note** that all spellings of built in units and prefixes must be UK (not US) English, ie: :code:`metre` (not meter), :code:`litre` (not liter), and :code:`deca` (not deka).

    .. container:: heading3

      Combinations
    
    Once you've read the section in the previoussection on how single :code:`unit` items can be combined to form a :code:`units` item, we also need to define how :code:`units` items can be used to form generations of units.
    Using the same example of the 330mL beer bottle as before, here are alternative, but equivalent, definitions.

    .. code-block:: xml

        <units name="bottle_of_beer">
            <unit units="millilitre" multiplier="330">
        </units>

        <!-- Of course, we need to define the "millilitre" unit before the above is valid -->
        <units name="millilitre">
            <unit units="litre" prefix="milli" />   <!-- Note UK spelling! -->
        </units>
        <!-- ... or ... -->
        <units name="millilitre">
            <unit units="metre" prefix="centi" exponent="3.0" />   <!-- Note UK spelling! -->
        </units>

    But we can also use child :code:`units` in conjunction with :code:`exponents` too.
    In this situation you'll need to understand the equation above.  Let's start by defining a centimeter:

    .. code-block:: xml

        <units name="centimeter">
            <unit units="metre" multiplier="0.01"/>
        </units>
        <!-- ... or ... -->
        <units name="centimeter">
            <unit units="metre" prefix="centi"/>
        </units>
        <!-- ... or ... -->
        <units name="centimeter">
            <unit units="metre" prefix="-2"/>
        </units>

    Then cube it to get the units of millilitres:

    .. code-block:: xml

        <units name="millilitre">
            <unit units="centimetre" exponent="3.0"/>
        </units>


    This is equivalent to creating the units of :math:`(10^{-6})(metre)^3`, because the effect of the :code:`exponent` is applied to the combination of :code:`units` and :code:`prefix`, but not to the :code:`multiplier`:

    .. code-block:: xml

        <!-- So this ... -->
        <units name="millilitre">
            <unit units="metre" exponent="3.0" multiplier="1e-6" />
        </units>

        <!-- ... is equivalent to this ...-->
        <units name="millilitre">
            <units units="metre" exponent="3.0" prefix="-2" />
        </units>


    It's good to get your head around the difference between how the :code:`multiplier` and :code:`prefix` terms work, or your scaling might not be quite what you expect (and your beer disappointing).



