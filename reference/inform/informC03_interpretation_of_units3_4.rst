.. _informC03_interpretation_of_units_3_4:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    As outlined in the previous "See more" block, the built-in base units
    :code:`dimensionless` do not contribute to the unit reduction tuple set.
    This holds for built-in units which inherit it (like :code:`radian` and
    :code:`steradian`) but also for situations in which base units' exponents
    could be simplified or cancelled.  
    For example, all three of the :code:`units` items below have identical
    unit reduction tuples of :code:`(metre, 1), (second, -1)`:

    .. code-block:: xml

        <units name="metres_per_second">
            <unit units="metre">
            <unit units="second" exponent="-1">
        </units>

    Here the "metre" exponents of 3 and -4 reduce to 1:

    .. code-block:: xml

        <units name="metres_per_second_too">
            <unit units="metre" exponent="4">
            <unit units="second" exponent="-1">
            <unit units="metre" exponent="-3">
        </units>

    Finally a complicated one with the same outcome.  Note that even though
    there are some irreducible units used, they end up with an exponent of 0
    in the tuple, and are therefore removed from the final unit reduction.
    Note that a Volt is equivalent to :math:`m^2.kg.s^{-3}.A^{-1}`

    .. code-block:: xml
    
        <units name="orange" />

        <units name="cubed_oranges">
            <unit units="orange" exponent="3" />
        </units>

        <units name="mega_amps_per_gram">
            <unit units="ampere" prefix="mega" exponent="1" />
            <unit units="gram" exponent="-1" />
        </units>

        <units name="acceleration_units">
            <unit units="metre" prefix="milli" />
            <unit units="second" exponent="-2" />
        </units>

        <!-- Finally, combining these gives a units item with the same reduction as above -->
        <units name="believe_it_or_not">
            <unit units="orange" exponent="-3" />
            <unit units="cubed_oranges" prefix="mega" />
            <unit units="volt" prefix="zepto" />
            <unit units="acceleration_units" exponent="-1" />
            <unit units="mega_amps_per_gram" multiplier="3.14159" />
        </units>
