.. _informC04_component_reference:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding component references

    As with references to units and variables, the term "component reference" refers to both sides of the naming and calling transaction.
    Its use includes both the item which *possesses* the reference (i.e.: a :code:`component` or :code:`import component` with a :code:`name` attribute) as well as the item which is *calling* the reference (i.e.: an item requesting the named component via its own :code:`component_ref` attribute).

    The complicated part to understand is the *scope* of a component's reference, or the appropriate name by which to call it depending on who is doing the calling.

    Consider the following example.  
    Here, two families live next door to one another, and within each family unit use the terms "husband" and "wife" to refer to one another.
    In the wider neighbourhood, however, they must be referred to by their names: "BarbaraGood", "TomGood", "JerryLeadbetter", and "MargotLeadbetter".

    .. code-block:: xml

      <model name="SurbitonNeighbourhood">

        <!-- Importing two families into the neighbourhood. -->
        <import xlink:href="GoodFamily.cellml">
          <!-- Within the family, the members are called "wife" and "husband", but after 
              importing into the neighbourhood, these same components are now referred
              to by the names "BarbaraGood" and "TomGood". -->
          <component name="BarbaraGood" component_ref="wife" />
          <component name="TomGood" component_ref="husband" />
        </import>

        <import xlink:href="LeadbetterFamily.cellml">
          <!-- Even though the component_ref attributes here are the same as above
              (i.e.: "wife" and "husband") they are interpreted within the context
              of the imported model (i.e.: the "TheLeadbetterFamilyUnit" model imported
              from the "LeadbetterFamily.cellml" file), and so refer to separate things.
          -->
          <component name="MargotLeadbetter" component_ref="wife" />
          <component name="JerryLeadbetter" component_ref="husband" />
        </import>

      </model>

      <!-- Inside the GoodFamily.cellml file: -->
      <model name="TheGoodFamilyUnit">
        <component name="husband" />
        <component name="wife" />
      </model>

      <!-- Inside the LeadbetterFamily.cellml file: -->
      <model name="TheLeadbetterFamilyUnit">
        <component name="husband" />
        <component name="wife" />
      </model>

    Now let's make things more interesting by adding an encapsulation hierarchy:

    .. code-block:: xml

      <model name="SurbitonNeighbourhood">

        ...  

        <component name="WomenInTheNeighbourhood" />
        <component name="MenInTheNeighbourhood" />

        <!-- Throughout the importing model (i.e.: this model), the imported
            items are referred to by their local name attribute ("BarbaraGood" etc), 
            not the name they are called within their imported family units ("wife"). -->
        <encapsulation>
          <component_ref component="WomenInTheNeighbourhood">
            <component_ref component="BarbaraGood" />
            <component_ref component="MargotLeadbetter" />
          </component_ref>
          <component_ref component="MenInTheNeighbourhood">
            <component_ref component="TomGood" />
            <component_ref component="JerryLeadbetter" />
          </component_ref>
        </encapsulation>
      </model>

    This particular encapsulation structure means that the women (Barbara and Margot) are essentially unable to have any contact with the men (Tom and Jerry) even though their original components in the imported models were able to access one another.

    Note also that these locality naming-calling rules are be applied through multiple generations of importing.
    Since The Good Life is a TV show, there are actors who play the roles of each of the characters. 
    This could be reflected by using another generation of imports within the two family files like this:

    .. code-block:: xml

      <!-- Inside the GoodFamily.cellml file: -->
      <model name="TheGoodFamilyUnit">
        <import xlink:href="cast_of_characters.cellml">
          <component name="husband" component_ref="RichardBriers" />
          <component name="wife" component_ref="FelicityKendal" />
        </import>
      </model>

      <!-- Inside the LeadbetterFamily.cellml file: -->
      <model name="TheLeadbetterFamilyUnit">
        <import xlink:href="cast_of_characters.cellml">
          <component name="husband" component_ref="PaulEddington" />
          <component name="wife" component_ref="PenelopeKeith" />
        </import>
      </model>

    Note that in this situation, the original :code:`SurbitonNeighbourhood` model does not need to change at all.
    Each of the component references remains correct, as each is isolated in its own scope.