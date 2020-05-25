.. _informC03_interpretation_of_units_3_2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3
    
      Unit reduction

    As discussed in the previous "See more" block, "irreducible" or "base" units are those fundamental quantities which cannot be expressed in any other way.
    This includes user-defined base units too.
    The "unit reduction" of any :code:`units` item is simply a recipe for how any units item is constructed from these "base unit" ingredients.

    For example, the units "metres per second" could be written:

      - m/s,
      - m⋅s\ :sup:`-1`,
      - :code:`product[ (metre)^1 , (second)^-1 ]`, or 
      - :code:`product[ power(metre, 1) , power(second, -2) ]`.

    This final list of tuples - representing the base unit and its exponent - is referred to as the *unit reduction tuples* for the :code:`units` element.
    Some other examples are given below.

    **Related to :hardcodedref:`3.3.3.2.1`:**

    .. code-block:: xml

        <!-- Unit reduction: [ (metre, 1), (second, -1) ] -->
        <units name="metres_per_second">
          <unit units="metre">
          <unit units="second" exponent="-1>
        </units>

    **Related to :hardcodedref:`3.3.3.2.2`:** :code:`joule`\ s are equivalent to kg⋅m\ :sup:`2`\ ⋅s:sup:`−2`\ , and the extra "per second" takes the effective exponent for :code:`second` to -3.

    .. code-block:: xml

        <!-- Unit reduction: [ (kilogram, 1), (metre, 2), (second, -3) ] -->
        <units name="joules_per_second">
          <unit units="joule" />
          <unit units="second" exponent="-1" />
        </units>

    **Related to :hardcodedref:`3.3.3.2.3 and 4`:** The concentration of apples per litre of cider is expressed using the custom base units :code:`apple`, the custom derived units :code:`bushell_of_apples` and the built-in convenience units of :code:`litre`, the last being equivalent to 0.001m\ :sup:`3`\ .
    Note that:

    - scaling does not affect the unit reduction tuples,
    - the custom derived units :code:`bushell_of_apples` do not appear because it can be further reduced to :code:`apple`, and
    - the final exponent of the :code:`metre` base unit comes from applying 3.3.3.2.4 and multiplying the exponent of the litre reduction tuple (metre, 3) with the exponent given in the :code:`cider_concentration` tuple (litre, -1) to give a (metre, -3) in the final unit reduction tuple set.

    .. code-block:: xml

        <!-- Unit reduction: [ (apple, 1), (metre, -3) ] -->

        <units name="apple" />

        <units name="bushell_of_apples">
          <unit units="apple" multiplier="1000" />
        </units>

        <units name="cider_concentration">
          <unit units="bushell_of_apples" multiplier="0.5" />
          <unit units="litre" exponent="-1" />
        </units>

    .. container:: heading3

      Dimensionless base units

    You may have noticed in the :ref:`Built-in Units<table_built_in_units>` that there is an entry labelled :code:`dimensionless`.

    This is provided for convenience, and doesn't take part in determining the unit reduction for any :code:`units` items.
    Together with the next point, this means that the all unit reduction tuples represent the *minimum possible* description of a :code:`units` item.
    For example, this :code:`units` item has the unit reduction of :code:`(metre, 1)`:

    .. code-block:: xml

        <!-- The "dimensionless" base units do not appear in the unit reduction. -->
        <units name="metres_by_dimensionless">
          <unit units="metre">
          <unit units="dimensionless" exponent="3">
        </units>

    .. container:: heading3

      Combining unit reductions

    As outlined above, the built-in base units :code:`dimensionless` do not contribute to the unit reduction tuple set.
    This holds for built-in units which are effectively dimensionless (like :code:`radian` and :code:`steradian`) but also for situations in which base units' exponents could be simplified or cancelled.
    For example, all of the :code:`units` items below have identical unit reduction tuples of :code:`(metre, 1), (second, -1)`:

    .. code-block:: xml

        <units name="metres_per_second">
            <unit units="metre">
            <unit units="second" exponent="-1">
        </units>

    Here the :code:`metre` exponents of 3 and -4 reduce to 1:

    .. code-block:: xml

        <units name="metres_per_second_too">
            <unit units="metre" exponent="4">
            <unit units="second" exponent="-1">
            <unit units="metre" exponent="-3">
        </units>

    Here the :code:`steradian` inclusion has no effect on the final unit reduction as its own units cancel out:

    .. code-block:: xml

        <units name="metres_per_second_too">
            <unit units="metre" exponent="1">
            <unit units="second" exponent="-1">
            <unit units="steradian" exponent="-3">
        </units>

    Finally a complicated one with the same outcome.
    Note that even though there are some irreducible units used, they end up with an exponent of 0 in the tuple, and are therefore removed from the final unit reduction.
    Note that a :code:`volt` V is equivalent to m\ :sup:`2`·kg·s\ :sup:`-3`·A\ :sup:`-1`\ .

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
