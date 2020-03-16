.. _informC03_interpretation_of_units_1_4:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    Once you've read the section in the previous "See more" box on how single
    :code:`unit` items can be combined to form a :code:`units` item, we also
    need to define how :code:`units` items can be used to form generations
    of units.  Using the same example of the 330mL beer bottle as before, here
    are alternative, but equivalent, definitions.

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

    But we can also use child :code:`units` in conjunction with
    :code:`exponents` too.  In this situation you'll need to understand the
    equation above.  Let's start by defining a centimeter:

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

    This is equivalent to creating the units of (1e-6)(metre)^3, because the
    effect of the :code:`exponent` is applied to the combination of
    :code:`units` and :code:`prefix`, but not to the :code:`multiplier`:

    .. code-block:: xml

        <!-- So this ... >
        <units name="millilitre">
            <unit units="metre" exponent="3.0" multiplier="1e-6" />
        </units>

        <!-- ... is equivalent to this ...-->
        <units name="millilitre">
            <units units="metre" exponent="3.0" prefix="-2" />
        </units>
    
    It's good to get your head around the difference between how the
    :code:`multiplier` and :code:`prefix` terms work, or your scaling might
    not be what you expect (and your beer quite disappointing).