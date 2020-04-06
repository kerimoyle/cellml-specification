.. _informC08_interpretation_of_mathematics1:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      What is a "pertinent component"?

    Pertinent components are those which together form the entirety of the model.
    They could be locally defined within the :code:`model` itself, imported from a separate file, or a dependency within the encapsulated set of an imported component.
    The example below describes a game of cricket in the backyard of a boy called Tom (defined locally).  
    He imports a boy called Harry from next door, but Harry's dog Dick comes along too as an implicit import because the component :code:`Dick` is encapsulated as a child of the component :code:`Harry` in the :code:`Neighbours.cellml` file.
    All three components :code:`Tom`, :code:`Dick`, and :code:`Harry` are "pertinent component items" to the :code:`BackyardCricket` model.
    The component :code:`George`, also in the :code:`Neighbours.cellml` file is not pertinent, as it is not within the encapsulated set of the imported component :code:`Harry`.

    .. code-block:: xml

      <!-- In file: MyHouse.cellml -->
      <model name="BackyardCricket" >

        <!-- Pertinent: A locally defined component. -->
        <component name="Tom" />
         
        <!-- Pertinent: An explicitly imported component. -->
        <import href="Neighbours.cellml">
          <component component_ref="Harry" name="Harry"  />
        </import>

        <!-- Pertinent: Another locally-defined component. -->
        <component name="FirstGame" />

        <!-- The local encapsulation structure does not affect which components are pertinent. -->
        <encapsulation>
          <component_ref component="FirstGame" >
            <component_ref component="Tom" />
            <component_ref component="Harry" />
          </component_ref>
        </encapsulation>
      </model>

      <!-- In file: Neighbours.cellml -->
      <model name="HarrysHouse" >
        <component name="Harry" />

        <!-- Pertinent: An implicitly imported component, pertinent because of its presence 
             in the encapsulated set of an imported component. -->
        <component name="DickTheDog" />

        <!-- Not pertinent: George the monkey is not a pertinent component item to the
             BackyardCricket model as it is neither explicitly nor implicitly imported. -->
        <component name="GeorgeTheMonkey" />

        <!-- The encapsulation set means that DickTheDog is a pertinent component item, 
             as it is imported at the same time as the component Harry is imported. -->
        <encapsulation>
          <component_ref component="Harry" >
            <component_ref component="DickTheDog" />
          </component_ref>
        </encapsulation>
      </model>

    After we know which components are pertinent, we can collect their mathematical grandchildren (i.e.: the top-level children of the pertinent components' :code:`math` elements) and use these to define the mathematics of our mathematical model.
   
