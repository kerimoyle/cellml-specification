.. _inform2_6:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding element IDs

    In order to understand how the XML :code:`id` attribute is used in CellML models, we need to understand four things.
    Firstly, in CellML the elements are identified by uniqueness over the *model* scope of their :code:`name` attribute, their type (eg: :code:`variable`), and in some cases, by their parent element too.
    Secondly, the CellML :code:`model` might exist over several different *documents*, and make use of :code:`import` functionality to connect these documents into one *model*.
    Thirdly, the uniqueness of the XML :code:`id` attribute value extends only to the *document* scope, not the CellML *model* scope.
    Finally, there are aspects of the *written* XML which do not contribute to the *conceptual* model as represented by the CellML; simple examples are things like whitespace between elements, comments, quotation and angle bracket markers.
    These are all parts of the written language which guide interpretation into the conceptual model.
    The :code:`id` attribute is likewise an XML attribute which falls into the same category: it may be read when a document is parsed, but as it doesn't form a part of any CellML element, it doesn't exist in the constructed conceptual representation.
    Having said this, the syntax of CellML is a subset of XML (as specified in :numref:`{number} {name}<specA_cellml_information_sets>`), so the rules of XML :code:`id` attributes must be followed, where present.

    Consider the example below.

    .. code::

      # In the document "BreakfastMenu.cellml".
      # All id attributes are unique within this document.
      model: name = "BreakfastOfChampions", id = "b"
        ├─ component: name = "Protein", id = "p"
        ├─ component: name = "Carbohydrates", id = "c" <╴╴╴╴╴╴╴╴╴┐
        └─ component: name = "FunStuff", id = "f"                ╷
             └─ variable: name = "FunStuff", id = "fs"           ╷
                                                                 ╷
                                              Valid: A CellML component named "Porridge" is
                                              imported, but its XML id attribute "p" is not
                                              a part of that import.
                                                                 ╵
      # In the document "CarbohydrateIdeas.cellml".              ╵
      # All id attributes should be unique within this document. ╵
      model: name = "Carbs" id = none specified                  ╵
        ├─ component: name = "Chocolate", id = "c"               ╵
        ├─ component: name = "Porridge", id = "p" ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘
        └─ component: name = "Toast", id = "t"
            └─ variable: name = "Peanutbutter", id = "p" 

            # Invalid: The variable Peanutbutter is not allowed to have an id of "p"
            # as this conflicts with the component Porridge id "p" in the same document.


    .. container:: toggle

      .. container:: header

        See CellML syntax

      .. code-block:: XML

        <!-- In the file BreakfastMenu.cellml: -->
        <model name="BreakfastOfChampions" id="b">
          <component name="Protein" id="p" />

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
          
          <!-- Valid: The id attribute "p" here does not clash with the Protein 
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

