.. _informC04_component_reference:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding component references

    As with references to units and variables, the term "component reference" refers to places where you need to  refer to a component using its name.
    This is done through the :code:`component_ref` attribute found in :code:`import component` and :code:`encapsulation` elements, as well as the :code:`component_1` and :code:`component_2` attributes of :code:`connection` elements.

    The complicated part occurs during imports, and involves understanding the *scope* of a component's reference.
    This is really just the appropriate name by which to call it depending on who is doing the calling.

    Consider the following example.  
    Here, two families live next door to one another, and within each family use the terms "husband" and "wife" to refer to their own component members.
    In the local "LeadbetterFamilyModel" and "GoodFamilyModel" :code:`model` contexts, "husband" and "wife" are the :code:`name` attributes of the local :code:`components`.
    In the wider neighbourhood, however, each person must be referred to by their real-world name: "BarbaraGood", "TomGood", "JerryLeadbetter", and "MargotLeadbetter".
    In the "SurbitonNeighbourhood" :code:`model` context, the real-world names of "BarbaraGood" etc. are treated as :code:`name` attributes of local :code:`component` elements (even though they're imported), but now the "husband" and "wife" terms are :code:`component_ref` elements, as they are not the context providing the name. 

    .. code::

      model: SurbitonNeighbourhood
        ├─ component: TomGood <╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┐
        ├─ component: BarbaraGood <╴╴╴╴╴╴╴╴╴┐ ╷
        ├─ component: MargotLeadbetter <╴╴╷ ╷ ╷
        └─ component: JerryLeadbetter <╴┐ ╷ ╷ ╷
                                        ╷ ╷ ╷ ╷
                                 imported components
                                        ╵ ╵ ╵ ╵
      # In LeadbetterFamily.cellml:     ╵ ╵ ╵ ╵ 
      model: LeadbetterFamilyModel      ╵ ╵ ╵ ╵
        ├─ component: husband ╴╴╴╴╴╴╴╴╴╴┘ ╵ ╵ ╵
        └─ component: wife ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘ ╵ ╵
                                            ╵ ╵
      # In GoodFamily.cellml:               ╵ ╵
      model: GoodFamilyModel                ╵ ╵
        ├─ component: wife ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘ ╵
        └─ component: husband ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘

    .. container:: toggle

      .. container:: header

        See CellML syntax

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

    .. code::

      model: SurbitonNeighbourhood
        ├─ component: WomenInTheNeighbourhood
        │   ├─ component: BarbaraGood <╴╴╴╴╴╴╴╴╴╴╴┐
        │   └─ component: MargotLeadbetter <╴╴╴╴┐ ╷
        └─ component: MenInTheNeighbourhood     ╷ ╷
            ├─ component: TomGood <╴╴╴╴╴╴╴╴╴╴╴┐ ╷ ╷
            └─ component: JerryLeadbetter <╴┐ ╷ ╷ ╷
                                            ╷ ╷ ╷ ╷
                                    imported components
                                            ╵ ╵ ╵ ╵
      # In LeadbetterFamily.cellml:         ╵ ╵ ╵ ╵
      model: LeadbetterFamilyModel          ╵ ╵ ╵ ╵
        ├─ component: husband ╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘ ╵ ╵ ╵
        └─ component: wife ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┼╴┘ ╵
                                              ╵   ╵
      # In GoodFamily.cellml:                 ╵   ╵
      model: GoodFamilyModel                  ╵   ╵
        ├─ component: husband ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘   ╵
        └─ component: wife ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘

    .. container:: toggle

      .. container:: header

        See CellML syntax

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

    This particular encapsulation structure means that the women (Barbara and Margot) are essentially unable to have any contact with the men (Tom and Jerry) even though their original components in the models from which they were imported *were* able to access one another.

    Note also that these locality-based naming-calling rules will be applied through multiple generations of importing.
    Since The Good Life is a TV show, there are actors who play the roles of each of the characters. 
    This could be reflected by using another generation of imports within the two family files like this:

    .. code::

        model: SurbitonNeighbourhood
          ├─ component: WomenInTheNeighbourhood
          │   ├─ component: BarbaraGood <╴╴╴╴╴╴╴╴╴╴╴╴╴┐
          │   └─ component: MargotLeadbetter <╴╴╴╴╴╴┐ ╷
          └─ component: MenInTheNeighbourhood       ╷ ╷
              ├─ component: TomGood <╴╴╴╴╴╴╴╴╴╴╴╴╴┐ ╷ ╷
              └─ component: JerryLeadbetter <╴╴╴┐ ╷ ╷ ╷
                                                ╷ ╷ ╷ ╷
                                      imported components
                                                ╵ ╵ ╵ ╵
                # In LeadbetterFamily.cellml:   ╵ ╵ ╵ ╵
                model: TheLeadbetterFamilyUnit  ╵ ╵ ╵ ╵
        ┌╴╴╴╴╴╴╴╴> ├─ component: husband ╴╴╴╴╴╴╴┘ ╵ ╵ ╵
        ╷ ┌ ╴╴╴╴╴> └─ component: wife ╴╴╴╴╴╴╴╴╴╴╴╴┼╴┘ ╵
        ╷ ╷                                       ╵   ╵
        ╷ ╷     # In GoodFamily.cellml:           ╵   ╵
        ╷ ╷     model: TheGoodFamilyUnit          ╵   ╵
        ╷ ╷ ┌╴╴╴> ├─ component: husband ╴╴╴╴╴╴╴╴╴╴┘   ╵
        ╷ ╷ ╷ ┌╴> └─ component: wife ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘
        ╷ ╷ ╷ ╷
      imported components
        ╵ ╵ ╵ ╵
        ╵ ╵ ╵ ╵  # In CastOfCharacters.cellml:
        ╵ ╵ ╵ ╵  model: 
        ╵ ╵ ╵ └╴╴╴├─ component: FelicityKendal
        ╵ ╵ └╴╴╴╴╴├─ component: RichardBriers
        ╵ └╴╴╴╴╴╴╴├─ component: PenelopeKeith
        └╴╴╴╴╴╴╴╴╴└─ component: PaulEddington

    .. container:: toggle

      .. container:: header

        See CellML syntax

      .. code-block:: xml

        <!-- Inside the GoodFamily.cellml file: -->
        <model name="TheGoodFamilyUnit">
          <import xlink:href="CastOfCharacters.cellml">
            <component name="husband" component_ref="RichardBriers" />
            <component name="wife" component_ref="FelicityKendal" />
          </import>
        </model>

        <!-- Inside the LeadbetterFamily.cellml file: -->
        <model name="TheLeadbetterFamilyUnit">
          <import xlink:href="CastOfCharacters.cellml">
            <component name="husband" component_ref="PaulEddington" />
            <component name="wife" component_ref="PenelopeKeith" />
          </import>
        </model>

    Note that in this situation, the original :code:`SurbitonNeighbourhood` model does not need to change at all.
    Each of the component references remains correct, as each is isolated in its own scope.
