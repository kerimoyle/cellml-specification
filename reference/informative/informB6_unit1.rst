.. _informB6_1:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    A :code:`Units` item is simply a collection of :code:`Unit` items, each with a :code:`prefix`, :code:`multiplier`, and :code:`exponent`.
    They can be nested and contain multiple generations of inheritance, which means that there's always a possibility of circular definitions: these are not permitted.

    For example, the first definition is valid:

    .. code-block:: xml

      <!-- Defining new base units called A: -->
      <units name="A"/>

      <!-- Defining new units called B, equivalent to 1000.A^2 -->
      <units name="B">
        <unit units="A" prefix="kilo" exponent="2"/>
      </units>

      <!-- Defining new units called C, equivalent to B^3/ms or (1000)^3.A^6/ms  -->
      <units name="C">
        <unit units="B" exponent="3"/>
        <unit units="second" prefix="milli" exponent="-1"/>
      </units>

    The second definition creates a circular dependency, and is not valid:

    .. code-block:: xml

      <!-- Defining units called A which depend on units B: -->
      <units name="A">
        <unit units="B" exponent="2"/>
      </units>

      <!-- Defining units called B which depend on units C: -->
      <units name="B">
        <unit units="C" prefix="kilo" exponent="-2"/>
      </units>

      <!-- Defining units called C which depend on A: -->
      <units name="C">
        <unit units="A" prefix="mega"/>
        <unit units="second" prefix="milli" exponent="-1"/>
      </units>
