.. _informB12_2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    Probably the biggest aspect of CellML's restrictions of MathML is that it is
    confined to using **only MathML2** content markup.  No form of presentation
    markup is permitted, and only the version MathML2 is allowed (ie: not MathML3
    or greater).

    .. container:: heading3

      The basics

    The types of block can be divided into two broad categories: operation
    items and information items. For example, the calculation of Einstein's
    :math:`E=mc^2` could be represented by:

    .. code-block:: xml

      <math>
        <apply><eq/>
          <ci>E</ci>
          <apply><times/>
            <ci>m</ci>
            <apply><power/>
              <ci>c</ci>
              <cn cellml:units="dimensionless">2</cn>
            </apply>
          </apply>
        </apply>
      </math>

    The code below is similar, but with the mistakes as listed:

    .. code-block:: xml

      <math>
        <apply><eq/>
          <!-- The line below is not valid because <ci> elements cannot specify units;
          their units are taken from the units of the variable (in this case, E really does have units Joules) -->
          <ci cellml:units="joule">E</ci>   
          <!-- The <apply> operation below is missing an operation argument (it should be <times/>) -->
          <apply>
            <ci>m</ci>
            <apply><power/>
              <ci>c</ci>
              <!-- The contents of a <cn> block below must be a real number, not a variable-->
              <!-- It must also define units in the cellml namespace, ie: units:cellml="myUnits"-->
              <cn>variable_with_value_of_two</cn>            
            </apply>
          </apply>
        </apply>
      </math>

    .. container:: heading3

      Dimensional consistency (or, how to write nonsense maths)

    For a model to have a valid CellML syntax, it needs to follow the MathML
    rules outlined above.  But it's still possible to create nonsense (should
    you so desire ... ), and one great way to create nonsense is to have MathML
    statements which have inconsistent units.  Consider again Einstein's
    equation :math:`E=mc^2`.  Now imagine that encode it into CellML like this:

    .. code-block:: xml

      <variable name="E" units="joule"/>
      <variable name="c" units="lumen"/>
      <variable name="m" units="weber"/>
      <math>
        <apply><eq/>
          <!-- Nonsense alert!  Left hand side units of joules ... -->
          <ci>E</ci>
          <!-- ... but right hand side units of (weber).(lumen)^(volt) -->
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

    Believe it or not, this is valid! It's clearly nonsense, but it doesn't
    actually violate any syntax rules.  The only instance where you will create
    an invalid model by assigning :code:`units` to :code:`variables` is when
    you need to form a :code:`map_variables` pair with a :code:`variable` in
    another :code:`component`.  In this case, each :code:`variable` must have
    an equivalent unit reduction (see :ref:`Section C.5.3<specC_units>`) or it
    won't be valid CellML.











