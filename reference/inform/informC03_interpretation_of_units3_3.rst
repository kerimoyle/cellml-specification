.. _informC03_interpretation_of_units_3_3:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    You may have noticed in the :ref:`Built-in Units<table_built_in_units>`
    that there is an entry labelled :code:`dimensionless`.

    This is provided for convenience, and doesn't take part in determining the
    unit reduction for any :code:`units` items.  Together with the next
    point, this means that the all unit reduction tuples represent the
    *minimum possible* description of a :code:`units` item.  For example, this
    :code:`units` item has the unit reduction of :code:`(metre, 1)`:

    .. code-block:: xml

        <!-- The "dimensionless" base units do not appear in the unit reduction -->
        <units name="metres_by_dimensionless">
          <unit units="metre">
          <unit units="dimensionless" exponent="3">
        </units>






