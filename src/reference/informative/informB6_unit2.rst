.. _informB6_2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    There are two items related to units in CellML, and their naming can be confusing!
    The plural form, :code:`units`, represents the units to be used in the model by being assigned to :code:`variable` and :code:`cn` elements.
    A :code:`units` item is a collection of smaller :code:`unit` items which transform the base dimensionality into the form required by the final units by way of prefixes, multipliers, and exponents.

    In the example, we'll need to use two of the *built-in* base units, :code:`metre` and :code:`second`, and manipulate them to form cm\ :sup:`3`\ /s.
    This is done by including child :code:`unit` items.
    First, we need to change the base units of :code:`metre` into cm\ :sup:`3`\ /s:

    .. code-block:: xml

      <units name="cm3_per_second">
         <unit units="metre" prefix="centi" exponent="3">  <!-- The default multiplier is 1. -->
         ...
      </units>

    Next, we include the time dependency, changing the built-in units :code:`second` into s\ :sup:`-1`\ .
    Note that sibling :code:`unit` items within a parent :code:`units` item are simply multplied together to form the final representation:

    .. code-block:: xml

      <units name="cm3_per_second">
        <unit units="metre" prefix="centi" exponent="3">  <!-- Note default multiplier of 1. -->
        <unit units="second" exponent="-1"> <!-- Note default prefix of 0, default multiplier of 1. -->
      </units>

    This is exactly equivalent to the alterantives below:

    .. code-block:: xml

      <units name="cm3_per_second">
        <unit units="metre" prefix="-2" exponent="3">  <!-- A prefix can be specified as a power of 10. -->
        <unit units="second" exponent="-1">
      </units>

      <!-- or ... -->

      <units name="cm3_per_second">
        <unit units="metre" exponent="3" multiplier="0.01">  <!-- A multiplier is specified instead of a prefix. -->
        <unit units="second" exponent="-1">
      </units>

      <!-- or ... -->

      <units name="cm3_per_second">
        <unit units="metre" prefix="centi">     <!-- Note default exponent of 1 ... -->
        <unit units="metre" prefix="-1">        <!-- ... is repeated ... -->
        <unit units="metre" multiplier="0.01">  <!-- ... to give the equivalent power of 3. -->
        <unit units="second" exponent="-1">
      </units>

    For more information on :code:`units` items please refer to :numref:`{number} {name}<units>`.
