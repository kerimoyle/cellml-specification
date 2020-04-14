.. _inform2_6:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding element IDs

    In order to understand how the XML :code:`id` attribute is used in CellML models, we need to remember three things.
    Firstly, in CellML the elements are identified by uniqueness over the *model* scope of their :code:`name` attribute, their type (eg: :code:`variable`), and in some cases, by their parent element too.
    Secondly, the CellML :code:`model` might exist over several different *documents*, and make use of :code:`import` functionality to connect these documents into one *model*.
    Finally, the uniqueness of the XML :code:`id` attribute value extends only to the *document* scope, not the CellML *model* scope.
    Consider the example below.

    .. code::

      # In the document "BreakfastMenu.cellml".
      # All id attributes are unique within this document.
      model: name = "BreakfastOfChampions", id = "b"
        ├─ component: name = "Protien", id = "p"
        ├─ component: name = "Carbohydrates", id = "c" <╴╴╴╴╴╴╴╴╴┐
        └─ component: name = "FunStuff", id = "f"                ╷
             └─ variable: name = "FunStuff", id = "fs"           ╷
                                                                 ╷
                                              Valid: Component named "Porridge" is
                                              imported, but its id attribute "p" is not.
                                                                 ╵
      # In the document "CarbohydrateIdeas.cellml".              ╵
      # All id attributes should be unique within this document. ╵
      model: name = "Carbs" id = none specified                  ╵
        ├─ component: name = "Chocolate", id = "c"               ╵
        ├─ component: name = "Porridge", id = "p" ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘
        └─ component: name = "Toast", id = "t"
            └─ variable: name = "Peanutbutter", id = "p" 

            # Invalid: The variable Peanutbutter is not allowed to have an id of "p"
            # as this conflicts with the component Porridge id in the same document.


    .. container:: toggle

      .. container:: header

        See CellML syntax

      .. code-block:: XML

        <!-- In the file BreakfastMenu.cellml: -->
        <model name="BreakfastOfChampions" id="b">
          <component name="Protien" id="p" />

          <import href="CarbohydrateIdeas.cellml">
            <!-- Valid: The id attribute value is set here to be "c" 
                 rather than that of the import, "p" -->
            <component name="Carbohydrates" id="c" component_ref="Porridge" />
          </import>

          <!-- Valid: The name attributes are repeated, but in different element types. 
               The id attributes are distinct. -->
          <component name="FunStuff" id="f" />
            <variable name="FunStuff" id="fs" units="sprinkles" />
          </component>
        </model>

        <!-- In the file CarbohydrateIdeas.cellml: -->
        <model name="Carbs">
          <!-- The id attribute "c" here does not clash with the Carbohydrates 
               component above as they are unknown to each other,
               and in different documents. -->
          <component name="Chocolate" id="c" />
          
          <!-- Valid: The id attribute "p" here does not clash with the Protien 
               component id above because even though they are in the same model,
               they are in different documents. -->
          <component name="Porridge" id="p" />

          <component name="Toast" id="t">
            <!-- Invalid: The id attribute "p" here does clash with the component 
                 Porridge above because they are in the same document. -->
            <variable name="Peanutbutter" id="p" units="smooth" />
          </component>
        </model>

    Some points to note:
    - Here we have two separate *documents* which are partially combined to make one *model*.
    - There is **no** repetition of :code:`id` attribute values within the BreakfastMenu.cellml *document*.
    - There **is** repetition of the :code:`name` attribute "FunStuff", but the elements have different types (:code:`component` and :code:`variable`), so this remains valid.
    - There **is** repetition of the :code:`id` attribute "p" in the CarbohydrateIdeas.cellml *document*, between the :code:`variable` named "Peanutbutter" and the :code:`component` named "Porridge".
      This is not valid.

