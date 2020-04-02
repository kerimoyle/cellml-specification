.. _inform2_2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Specific information items

    There are different kinds of information stored in XML elements.
    In the example below, the :code:`food_ideas` element has:

    - :code:`title`, :code:`instructions`, :code:`ingredient` have *text* content (note that numbers like 1.0 are treated as text),
    - :code:`ingredients` and :code:`food_ideas` have *element* contents, because they have child elements inside them,
    - :code:`category` is an *attribute* of the :code:`recipe` element, and :code:`name` and :code:`units` are *attributes* of the :code:`ingredient` element, and
    - the note within :code:`<!-- ... -->` comment tags is of an *unparsed* type and is ignored.

    .. code-block:: xml

      <food_ideas>
        <recipe category="easy">
          <title>Three ingredient scones</title>
          <!-- These are so easy ... and if you're clever you'll save a little cream for whipping on the top! -->
          <ingredients>
            <ingredient name="cream" units="cup">1.0</ingredient>
            <ingredient name="lemonade" units="cup">1</ingredient>
            <ingredient name="selfraising_flour" units="cup">4</ingredient>
          </ingredients>
          <instructions>
            Mix them all together using your hands.
            You can use extra flour if you need to.
            Bake at 220C for about 12 minutes or until golden.
          </instructions>
        </recipe>
      </food_ideas>

    Using CellML this could be written:

    .. code-block:: xml

      <model name="recipes">
        <units name="cup">
          <unit units="litre" prefix="milli" multiplier="250.0" />
        </units>
        <component name="Three_ingredient_scones">
          <!-- Sigh ... if only it were possible for my computer to make me tea ... -->
          <variable name="cream" cellml:units="cup" initial_value="1" />
          <variable name="lemonade" cellml:units="cup" initial_value="1"  />
          <variable name="selfraising_flour" cellml:units="cup" initial_value="5" />
          <variable name="mixture" cellml:units="cup" />
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
        </component>
        <!-- BUT THIS IS NOT VALID! -->
        <extra type="Danger_Will_Robinson">
          Even though this looks like a valid XML text block, it's not allowed here.  Only those
          elements which are explicitly specified as types of children are allowed!
        </extra>
      </model>
