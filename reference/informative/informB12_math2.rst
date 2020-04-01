.. _informB12_2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    Probably the biggest aspect of CellML's restrictions of MathML is that it is confined to using **only MathML2** content markup.
    No form of presentation markup is permitted, and only the version MathML2 is allowed (i.e.: not MathML 3 or greater).

    .. container:: heading3

      The basics

    The types of block can be divided into two broad categories: operation items and information items.
    For example, the calculation of Einstein's :math:`E=mc^2` could be represented by:

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
               their units are taken from the units of the variable 
               (even though in this case, E really does have units Joules). -->

          <ci cellml:units="joule">E</ci>

          <!-- The <apply> operation below is missing an operation argument (it should be <times/>) -->
          <apply>
            <ci>m</ci>
            <apply><power/>
              <ci>c</ci>

              <!-- The contents of a <cn> block below must be a real number, not a variable. -->
              <!-- It must also define units in the cellml namespace, i.e.: units:cellml="myUnits". -->
              <cn>variable_with_value_of_two</cn>

            </apply>
          </apply>
        </apply>
      </math>

