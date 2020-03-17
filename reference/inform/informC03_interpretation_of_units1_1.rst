.. _informC03_interpretation_of_units_1_1:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

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
    Please see the next "See more" block for a full explanation of its role.

