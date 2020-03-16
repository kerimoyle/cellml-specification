.. _informC03_interpretation_of_units_3_3:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    You may have noticed in the :ref:`Built-in Units<table_built_in_units>`
    that there are three rows which are effectively dimensionless.  These are:
    
    - the :code:`dimensionless` units themselves,
    - the :code:`radian` units, and
    - the :code:`steradian` units.

    These are provided for convenience, and don't take part in determining the
    unit reduction for any :code:`units` items.  This, together with the next
    point, means that the unit reduction tuples represent the
    *minimum possible* description of a :code:`units` item.  For example, all
    of these :code:`units` items have the same unit reduction of
    :code:`(metre, 1)`:

    .. code-block:: xml

        <!-- The "dimensionless" base units do not appear in the unit reduction -->
        <units name="metres_by_dimensionless">
          <unit units="metre">
          <unit units="dimensionless" exponent="3">
        </units>

        <!-- The "radian" and "steradian" convenience units inherit from the 
            base "dimensionless" unit, which does not appear in the unit reduction -->
        <units name="metre_times_radian">
          <unit units="metre">
          <unit units="radian">
          <unit units="steradian">
        </units>





