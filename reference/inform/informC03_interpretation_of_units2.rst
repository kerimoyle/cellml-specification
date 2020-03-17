.. _informC03_interpretation_of_units_2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    The terms "irreducible units" and "unit reduction" really need to be understood together, but before either make sense we need to explain the concept of "base units".
    In the physical world there are seven base units defined in the SI (Système International d'Unités) system.
    These are:

    +--------+------------+---------------------------+
    | Symbol | Name       | Base quantity             |
    +--------+------------+---------------------------+
    | s      | second     | time                      |
    +--------+------------+---------------------------+
    | m      | metre      | length                    |
    +--------+------------+---------------------------+
    | kg     | kilogram   | mass                      |
    +--------+------------+---------------------------+
    | A      | ampere     | electric current          |
    +--------+------------+---------------------------+
    | K      | kelvin     | thermodynamic temperature |
    +--------+------------+---------------------------+
    | mol    | mole       | amount of substance       |
    +--------+------------+---------------------------+
    | cd     | candela    | luminous intensity        |
    +--------+------------+---------------------------+

    Some of the units listed in the :ref:`Built-in Units<table_built_in_units>` are these base units, but others are combinations of them included for convenience.
    Only those rows in the table which have no entries in the "Unit reduction" column are "irreducible" or base units.

    In the CellML2.0 world you are able to also define your own base units.
    These are :code:`units` items which you create which do not reference any child :code:`unit` items, so are therefore "irreducible".
    For example:

    .. code-block:: xml

      <!-- Define a new base unit called "egg".
           It's a base unit because it has no child unit items -->
      <units name="egg">
      </units>

      <!-- Define other units which use this new base unit -->
      <units name="dozen_eggs">
        <unit units="egg" multiplier="12" />
      </units>

      <!-- Combine the new base unit with existing built-in units: eggs/m^2 -->
      <units name="eggs_per_square_metre">
        <unit units="egg" />
        <unit units="metre" exponent="-2" />
      </units>

    The terms "irreducible units" and "unit reduction" are used when discussing situations where the units of two variables must be equivalent.
    It makes no sense to equate a variable with units of seconds to another with units of kilograms, for example.
    The same is true for more complicated versions of units, as outlined in the next section.

