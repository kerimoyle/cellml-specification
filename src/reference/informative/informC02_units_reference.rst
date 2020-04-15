.. _informC02_units_reference:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding units references

    Units references are different from other reference types in that their value could refer either to other units which you've imported or created in your model, or to one of the list of :ref:`built-in units<table_built_in_units>`.  

    The trickier part is understanding them is during an import process, where the *scope* or *domain* in which named units exist becomes important, as alluded to in points :hardcodedref:`3.2.1 and 3.2.2.2`.

    Consider the example below.
    The first model :code:`BlueberryPieRecipe` simply combines two pre-made component ingredients; one for the crust and one for the filling.

    .. code::

      model: BlueberryPieRecipe
        ├─ component: crust <╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┐
        └─ component: filling <╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┐ ╷
                                                ╷ ╷
                                  imported components
                                                ╵ ╵
      # In filling_recipes.cellml:              ╵ ╵
      model: PieFillingRecipes                  ╵ ╵
        ├─ component: BlueberryCinnamonFilling ╶┘ ╵
        └─ component: AppleAndPearFilling         ╵
                                                  ╵
      # In crust_recipes.cellml:                  ╵
      model: PieCrustRecipes                      ╵
        ├─ component: HazelnutLavenderCrust ╴╴╴╴╴╴┘
        └─ component: CheeseAndAlmondCrust

    .. container:: toggle

      .. container:: header

        See CellML syntax

      .. code-block:: xml

        <!-- Inside the file "how_to_make_blueberry_pie.cellml": -->
        <model name="BlueberryPieRecipe">
            <import xlink:href="path/to/my/crust_recipes.cellml">
                <component name="crust" component_ref="HazelnutLavenderCrust" />
            </import>
            <import xlink:href="path/to/my/filling_recipe.cellml">
              <component name="filling" component_ref="BlueberryCinnamonFilling" />
            </import>
        </model>

    The components are imported from separate files, each of which defines and uses its own local definitions of the custom measurement units :code:`spoon`, :code:`dash`, and :code:`smidgen`.

    .. code::

        model: BlueberryPieRecipe
          ├─ component: crust <╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┐
          └─ component: filling <╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┐ ╷
                                                        ╷ ╷
                                          imported components and
                                              the units they need
                                                        ╵ ╵
          # In filling_recipes.cellml:                  ╵ ╵
          model: PieFillingRecipes                      ╵ ╵
            ├─ component: BlueberryCinnamonFilling ╴╴╴┬┬┘ ╵
            │    ├─ variable: blueberries (gram)      ╷╷  ╵
            │    ├─ variable: sugar (dimensionless)  units are implicitly
            │    ├─ variable: cornflour (gram)       imported by the component
            │    ├─ variable: cinnamon                ╵╵  ╵
        ┌╴╴╴╴╴╴╴╴╴> └─ units: smidgen ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘╵  ╵
        ╷   |   └─ variable: water                     ╵  ╵
        ╷┌╴╴╴╴╴╴╴╴╴> └─ units: spoonful ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘  ╵
        ╷╷  |                                             ╵
        ╷╷  ├─ component: AppleAndPearFilling             ╵
        ╷╷  |                                             ╵
      local custom units                                  ╵
        ╵╵  |                                             ╵
        ╵└╴╴├─ units: spoonful                            ╵
        └╴╴╴└─ units: smidgen                             ╵
                                                          ╵
          # In crust_recipes.cellml:                      ╵
          model: PieCrustRecipes                          ╵
            ├─ component: HazelnutLavenderCrust ╴╴╴╴╴╴╴┬┬┬┘
            │     ├─ variable: ground_hazelnut (gram)  ╷╷╷
            │     ├─ variable: egg (dimensionless)     ╷╷╷
            │     ├─ variable: flour (gram)         units are implicitly
            │     ├─ variable: sugar (gram)         imported by the component
            │     ├─ variable: water                   ╵╵╵
        ┌╴╴╴╴╴╴╴╴╴╴> └─ units: spoonful ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘╵╵
        ╷   │     ├─ variable: salt                     ╵╵
        ╷┌╴╴╴╴╴╴╴╴╴> └─ units: dash ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘╵
        ╷╷  │     └─ variable: lavender_flowers          ╵
        ╷╷┌╴╴╴╴╴╴╴╴> └─ units: smidgen ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘
        ╷╷╷ │
      local custom units
        ╵╵╵ │
        ╵╵╵ ├─ component: CheeseAndAlmondCrust
        ╵╵╵ │
        ╵╵└╴├─ units: smidgen
        ╵└╴╴├─ units: dash
        └╴╴╴├─ units: spoonful
            └─ units: dollop   


    .. container:: toggle

      .. container:: header

        See CellML syntax

      .. code-block:: xml

        <!-- Inside the file "crust_recipes.cellml": -->
        <model name="PieCrustRecipes">

          <component name="HazelnutLavenderCrust">

            <!-- These units are built-in so do not change. -->
            <variables name="ground_hazelnut" units="gram" />
            <variables name="egg" units="dimensionless" />
            <variables name="flour" units="gram" />
            <variables name="sugar" units="gram" />

            <!-- These units are defined for this, their local scope, below. -->
            <variables name="water" units="spoonful" />
            <variables name="salt" units="dash" />
            <variables name="lavender_flowers" units="smidgen" />
            ...
          </component>

          <component name="CheeseAndAlmondCrust">
            ...
          </component>

          <!-- Local units definitions for spoonful, dash, and smidgen. -->
          <units name="spoonful">
            <unit units="litre" prefix="milli" multiplier="15" />
          </units>
          <units name="dash">
            <unit units="gram" multiplier="5" />
          </units>
          <units name="smidgen">
            <unit units="gram" multiplier="1" />
          </units>
          <units name="dollop">
            <unit units="litre" prefix="milli" multiplier="20" />
          </units>
        </model>

        <!-- Inside the file "filling_recipes.cellml": -->
        <model name="PieFillingRecipes">

          <component name="BlueberryCinnamonFilling">
            <!-- These units are built-in, so do not change.  -->
            <variables name="blueberries" units="gram" />
            <variables name="sugar" units="dimensionless" />
            <variables name="cornflour" units="gram" />

            <!-- These units are defined for use in this, their local scope, below. -->
            <variables name="cinnamon" units="smidgen" />
            <variables name="water" units="spoonful" />

            <math>
                ...
            </math>
          </component>

          <component name="AppleAndPearFilling">
            ...
          </component>

          <!-- Local units definitions for spoonful and smidgen. -->
          <units name="spoonful">
            <unit units="litre" prefix="milli" multiplier="5" />
          </units>
          <units name="smidgen">
            <unit units="gram" multiplier="20" />
          </units>

        </model>

    This is where the idea of *scope* becomes important.  
    As it stands, there is no conflict between the two different definitions of :code:`spoonful` and :code:`dash`, because each of the components refers to *its own definition* of these units.
    The components do not "know" that there is any other definition out there, because they cannot "see" up into the importing model.

    Now let's consider that the cook wants to alter the recipe a little after these two main ingredients have been imported, by adding a spoonful of brandy to some custard.
    The top-level model becomes:

    .. code::

      model: BlueberryPieRecipe
        ├─ component: BrandyCustard
        │    ├─ variable: custard (litre)
        │    └─ variable: brandy           
        │         └─ units: spoonful  # These units are not defined in a scope
        │                               which this component can access: 
        │                               the model is invalid.
        ├─ component: crust <╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┐
        └─ component: filling <╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┐ ╷
                                                ╷ ╷
                                  imported components
                                                ╵ ╵
      # In filling_recipes.cellml:              ╵ ╵
      model: PieFillingRecipes                  ╵ ╵
        ├─ component: BlueberryCinnamonFilling ╶┘ ╵
        └─ component: AppleAndPearFilling         ╵
                                                  ╵
      # In crust_recipes.cellml:                  ╵
      model: PieCrustRecipes                      ╵
        ├─ component: HazelnutLavenderCrust ╴╴╴╴╴╴┘
        └─ component: CheeseAndAlmondCrust

    .. container:: toggle

      .. container:: header

        See CellML syntax

      .. code-block:: xml

        <!-- Inside the file "how_to_make_blueberry_pie.cellml": -->
        <model name="BlueberryPieRecipe">
          <import xlink:href="path/to/my/crust_recipes.cellml">
            <component name="premade_crust" component_ref="HazelnutLavenderCrust" />
          </import>
          <import xlink:href="path/to/my/filling_recipe.cellml">
            <component name="yummy_filling" component_ref="BlueberryCinnamonFilling" />
          </import>

          <!-- Defining a new component, brandy custard -->
          <component name="BrandyCustard">
            <variable name="custard" units="litre" />
            <variable name="brandy" units="spoonful" />
            ...
          </component>
        </model>

    At this stage the model is invalid because the units :code:`spoonful` in the top-level model are not defined.  Just as the imported models cannot "see" up into the importing model, neither can the importing model "see" down into the imported models beyond those items which it has explicitly imported.  

    In order to reuse the :code:`spoonful` units from either of the imported models, they must be explicitly imported.  The top-level model becomes:

    .. code::

        model: BlueberryPieRecipe
          ├─ component: BrandyCustard
          │    ├─ variable: custard (litre)
          │    └─ variable: brandy           
      ┌╴╴╴╴╴╴╴╴> └─ units: spoonful
      ╷   ├─ component: crust <╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┐
      ╷   ├─ component: filling <╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┐ ╷
      ╷   │                                     ╷ ╷
      └╴╴╴└─ units: spoonful <╴╴╴╴╴╴╴┐     imported components and
                                     ╷     the units they need
                  explicitly imported units     ╵ ╵
            are available to all components     ╵ ╵
                                     ╵          ╵ ╵
      # In filling_recipes.cellml:   ╵          ╵ ╵
      model: FillingRecipeCollection ╵          ╵ ╵
        ├─ units: spoonful ╴╴╴╴╴╴╴╴╴╴┘          ╵ ╵
        ├─ component: BlueberryCinnamonFilling ╶┘ ╵
        └─ component: AppleAndPearFilling         ╵ 
                                                  ╵
      # In crust_recipes.cellml:                  ╵
      model: PieCrustRecipes                      ╵
        ├─ component: HazelnutLavenderCrust ╴╴╴╴╴╴┘
        └─ component: CheeseAndAlmondCrust

    .. container:: toggle

      .. container:: header

        See CellML syntax

      .. code-block:: xml

        <!-- Inside the file "how_to_make_blueberry_pie.cellml": -->
        <model name="BlueberryPieRecipe">
          <import xlink:href="path/to/my/crust_recipes.cellml">
            <component name="premade_crust" component_ref="HazelnutLavenderCrust" />
          </import>
          <import xlink:href="path/to/my/filling_recipe.cellml">
            <component name="yummy_filling" component_ref="BlueberryCinnamonFilling" />
          </import>

          <!-- Defining a new component, brandy custard -->
          <component name="BrandyCustard">
            <variable name="custard" units="litre" />
            <variable name="brandy" units="spoonful" />
            ...
          </component>

          <!-- Explicitly importing the "spoonful" units from the "filling_recipes.cellml" file: -->
          <import xlink:href="path/to/my/filling_recipe.cellml">
            <!-- The units are also called "spoonful" in this top-level scope. -->
            <units name="spoonful" component_ref="spoonful" />
          </import>
        </model>
              
    At this stage we have three sets of units all named "spoonful".
    Since each is only accessible to its local components there is no conflict of definition or interpretation.
    Now that the units required in the new :code:`BrandyCustard` component are defined within the same infoset, the model becomes valid, and our dessert needs are satisfied once more.
