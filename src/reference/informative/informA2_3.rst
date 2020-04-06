.. _inform2_3:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Semantic equivalence

    The example below is identical to that in the previous "See more" block because:

      - newlines, tabs, whitespace do not affect equivalence (except as part of text or attribute content),
      - the order of element definition does not affect equivalence,
      - the order of attribute definition does not affect equivalence, and
      - comments do not affect equivalence.

    .. code-block:: xml

      <model name="recipes">
        <component name="Three_ingredient_scones">
          <!-- 
             Comments are ignored ...
             so here's a really long one about how much I now 
             feel like yummy scones and jam and cream and tea ...
          -->
          
          <!-- The order of child elements is ignored -->
          <math>
            <apply><eq/>
              <ci>mixture</ci>
              <apply><plus/>
                <ci>cream</ci>
                <ci>lemonade</ci>
                <ci>selfraising_flour</ci>
              </apply>
            </apply>
          </math>
          
          <!-- Whitespace (including tab, new line, and space) between attributes is ignored. -->
          <variable 
            name="selfraising_flour" 
            cellml:units="cup" 
          />
           <variable         name="cream"           cellml:units="cup"          />

          <!-- Whitespace (including tab, new line, and space) between elements is ignored. -->



          <variable cellml:units="dimensionless"  name="mixture" /><variable name="lemonade" cellml:units="cup" />
        </component>
        <units name="cup">
          <!-- The order of attributes within an element is ignored. -->
          <unit multiplier="250.0" prefix="milli"  units="litre" />
        </units>
      </model>
