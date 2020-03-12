.. _informB12_2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    The :mathml2spec:`MathML <>` syntax uses similar ideas to the CellML syntax
    in that it uses blocks which open and close, and has a hierarchical
    structure of parent blocks with nested child blocks within them.

    Probably the biggest aspect of CellML's restrictions of MathML is that it is
    confined to using **only MathML2** content markup.  No form of presentation
    markup is permitted, and only the version MathML2 is allowed (ie: not MathML3
    or greater).

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
          their units are taken from the units of the variable (in this case, E has units kJ) -->
          <ci cellml:units="kilojoules">E</ci>   
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







