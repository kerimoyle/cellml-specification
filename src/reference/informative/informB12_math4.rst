.. _informB12_4:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Constants using the ``<cn>`` tags

    When specifying a constant with :code:`<cn>`, its :ref:`real number value<specA_real_number>` is given between the tags, and its units are specified as an attribute.

    .. code-block:: xml

      <!-- These are valid: Note the cellml namespace for the units. -->
      <cn cellml:units="customUnitsDefinedInTheModel">35.3</cn> <!-- Units which exist in the model are permitted. -->
      <cn cellml:units="litre">10</cn> <!-- Built-in units (with UK spelling) are permitted. -->
      <cn cellml:units="dimensionless">3.14159e+03</cn> <!-- Scientific or e-notation is permitted. -->


    Please note that the units name specified must refer to a :code:`units` element that exists in the :code:`model` element, or be one from the :ref:`Built-in Units<table_built_in_units>` table.


    .. code-block:: xml

      <!-- These are not valid: -->
      <cn cellml:units="unitsThatDontExist">35.3</cn> <!-- The units reference must exist in the model. -->
      <cn>42</cn> <!-- Units must be specified. -->
      <cn some_other_namespace:units="some_units">502.642</cn> <!-- Units must be in the cellml namespace. -->
      <cn cellml:units="meter">26.6</cn> <!-- Built-in unit names must be in UK spelling, i.e.: metre, litre. -->
      <cn cellml:units="dimensionless">3,000</cn> <!-- Must be a valid real number string, the comma separator is not permitted. -->
      <cn cellml:units="dimensionless">+4.0</cn> <!-- The plus sign indicator is not permitted except in e-notation exponents. -->
      <cn cellml:units="dimensionless">0x235abc</cn> <!-- The value must be in base 10. -->
      <cn cellml:units="dimensionless">i_am_a_variable</cn> <!-- Only real number values are permitted in <cn> blocks. -->

    .. container:: heading3

      Dimensional consistency (or, how to write nonsense maths)

    For a model to have a valid CellML syntax, it needs to follow the MathML rules outlined above.
    But it's still possible to create nonsense (should you so desire ... ), and one great way to create nonsense is to have MathML statements which have inconsistent units.
    Consider again Einstein's equation :math:`E=mc^2`.  Now imagine that encode it into CellML like this:

    .. code-block:: xml

      <variable name="E" units="joule"/>
      <variable name="c" units="lumen"/>
      <variable name="m" units="weber"/>
      <math>
        <apply><eq/>
          <!-- Nonsense alert!  Left hand side units of joules ... -->
          <ci>E</ci>
          <!-- ... but right hand side units of (weber).(lumen)^(volt)! -->
          <apply><times/>
            <ci>m</ci>
            <apply><power/>
              <ci>c</ci>
              <!-- Nonesense alert!  Units in an exponent? -->
              <cn cellml:units="volt">2</cn>
            </apply>
          </apply>
        </apply>
      </math>

    Believe it or not, this is valid! (Perhaps it's better to say it's not invalid).
    It's clearly nonsense, but it doesn't actually violate any syntax rules.
    The only instance where you will create an invalid model by assigning :code:`units` to :code:`variables` is when you need to form a :code:`map_variables` pair with a :code:`variable` in another :code:`component`.
    In this case, each :code:`variable` must have an :ref:`equivalent unit reduction<specC_interpretation_of_units>` or it won't be valid CellML.
