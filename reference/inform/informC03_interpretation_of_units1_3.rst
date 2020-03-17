.. _informC03_interpretation_of_units_1_3:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

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

