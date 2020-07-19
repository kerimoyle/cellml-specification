.. _informC10_interpretation_of_map_variables5:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding interfaces

    There are two hurdles to get past before variables can be mapped to one another.
    The first is the relative position within the encapsulation hierarchy of the :code:`variable` elements' parent :code:`component` elements (as discussed in :numref:`{number} {name}<specC_interpretation_of_encapsulation>`, and the second is the value of the :code:`interface_type` attribute given to each :code:`variable` itself.
    This means that even if two components are sufficiently close relatives that they *can* be connected, the modeller still has control at the individual variable level as to which of those relatives can have access.

    The :code:`interface_type` attribute value choices are: 
    - :code:`public` (used by child components to reference their parent, or between siblings),
    - :code:`private` (used by parent components to reference their children), 
    - :code:`public_and_private` (used when both the :code:`public` and :code:`private` interfaces are required), or
    - :code:`none`, which is the default.

    Which one(s) of these are deemed *applicable* for any :code:`variable` mapping is determined by the relationship between the their parent :code:`component` elements.  

    In the example below, Christopher Robin must assemble an average score of the mood of all of his friends in the Hundred Acre Wood.
    He does not have access to all of their :code:`mood` scores directly, so must use mapped variables in order to create the average.

    .. code::

      model: TheHouseAtPoohCorner
        ├─ component: ChristopherRobin
        │   ├─ variable: my_mood 
        │   ├─ variable: average_mood_of_everyone
        │   ├─ variable: roos_mood 
        │   ├─ variable: kangas_mood <╴╴╴╴╴┐
        │   ├─ variable: eeyores_mood <╴╴╴┐╷
        │   └─ variable: poohs_mood <╴╴╴╴┐╷╷
        │                                ╷╷╷
        │                     connections between these
        │            components are possible, depending
        │                  on the variables' interfaces
        │                                ╵╵╵
        ├─ component: WinnieThePooh      ╵╵╵
        │   └─ variable: mood ╴╴╴╴╴╴╴╴╴╴╴┘╵╵
        ├─ component: Eeyore              ╵╵
        │   └─ variable: mood ╴╴╴╴╴╴╴╴╴╴╴╴┘╵
        └─ component: Kanga                ╵
            │  ├─ variable: mood ╴╴╴╴╴╴╴╴╴╴┘
            └─ component: Roo
                └─ variable: mood ╴╴╴╴╴╴╴╴╴╴> This variable cannot be connected to 
                                              anything within the ChristopherRobin 
                                              component as its component is too distant.

    At present, the connections above in dashed lines are *possible*, as long as the variables have interface types which support them. 
    One connection is *not* possible (yet): Christopher Robin doesn't know Roo's mood, because their components are too distant (grandparent/grandchild) to be directly connected.
    We can add a utility variable :code:`roos_mood` to the :code:`Kanga` component in order to pass along its value to the :code:`ChristopherRobin` component.
    We'll also add interface types to the variables, and discuss their effects below.

    .. code::

      model: TheHouseAtPoohCorner
        ├─ component: ChristopherRobin
        │   ├─ variable: my_mood 
        │   ├─ variable: average_mood_of_everyone 
        │   ├─ variable: roos_mood (interface: public) <╴╴╴╴╴ D ╴╴╴╴╴╴╴╴╴╴╴╴┐
        │   ├─ variable: kangas_mood (interface: none) <╴╴╴╴╴ C ╴╴╴╴┐       ╷
        │   ├─ variable: eeyores_mood (interface: public) <╴╴ B ╴╴╴┐╷       ╷
        │   └─ variable: poohs_mood (interface: public) <╴╴╴╴ A ╴╴┐╷╷       ╷
        │                                                         ╷╷╷  utility variable added so  
        ├─ component: WinnieThePooh                               ╷╷╷  that Roo's mood can be passed
        │   └─ variable: mood (interface: public)  ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘╷╷  down to Christopher Robin
        ├─ component: Eeyore                                       ╷╷       ╵
        │   └─ variable: mood ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘╷       ╵
        └─ component: Kanga                                         ╷       ╵
            │  ├─ variable: mood (interface: public) ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘       ╵
            │  └─ variable: roos_mood (interface: private) <╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┤
            └─ component: Roo                                               ╷
                └─ variable: mood (interface: public) ╴╴╴╴╴╴ E ╴╴╴╴╴╴╴╴╴╴╴╴╴┘


    .. container:: toggle

      .. container:: header

        See CellML syntax

      .. code-block:: xml

        <model name="TheHouseAtPoohCorner">

          <!-- Defining the components and local variables. -->
          <component name="ChristopherRobin">
            <variable name="my_mood" interface_type="none" units="mood_score" />
            <variable name="average_mood_of_everyone" interface_type="none" units="mood_score" />
            <variable name="roos_mood" interface_type="public" units="mood_score" />
            <variable name="kangas_mood" interface_type="none" units="mood_score" />
            <variable name="eeyores_mood" interface_type="public" units="mood_score" />
            <variable name="poohs_mood" interface_type="public" units="mood_score" />
          </component>

          <component name="WinnieThePooh">
            <variable name="mood" interface_type="public" units="mood_score" />
          </component>

          <component name="Eeyore">
            <variable name="mood" units="mood_score" />
          </component>

          <component name="Kanga">
            <variable name="mood" interface_type="public" units="mood_score" />
            <!-- The utility variable roos_mood is included here so that it can pass
                 the value of mood in component Roo to roos_mood in component ChristopherRobin. -->
            <variable name="roos_mood" interface_type="private" units="mood_score" />
          </component>

          <component name="Roo">
            <variable name="mood" interface_type="public" units="mood_score" />
          </component>

          <!-- Defining connections and mapped variables. -->
          <connection component_1="ChristopherRobin" component_2="WinnieThePooh">
            <!-- Mapping A -->
            <map_variables variable_1="poohs_mood" variable_2="mood" />
          </connection>

          <connection component_1="ChristopherRobin" component_2="Eeyore">
            <!-- Mapping B -->
            <map_variables variable_1="eeyores_mood" variable_2="mood" />
          </connection>

          <connection component_1="ChristopherRobin" component_2="Kanga">
            <!-- Mapping C -->
            <map_variables variable_1="kangas_mood" variable_2="mood" />
            <!-- Mapping D -->
            <map_variables variable_1="roos_mood" variable_2="roos_mood" />
          </connection>

          <connection component_1="Kanga" component_2="Roo">
            <!-- Mapping E -->
            <map_variables variable_1="roos_mood" variable_2="mood" />
          </connection>

        </model>

    - Mapping A is valid.
      The sibling components :code:`WinnieThePooh` and :code:`ChristopherRobin` have :code:`public` interfaces between their :code:`mood` and :code:`poohs_mood` variables respectively.
      This follows point :hardcodedref:`3.10.9.1` and is valid.
    
    - Mapping B is not valid.
      By default an interface type is :code:`none`, and since the :code:`mood` variable in component :code:`Eeyore` does not specify one, no mappings are permitted.
      For that connection to exist, the :code:`mood` variable must have an interface type :code:`public`.
    
    - Mapping C is not valid.
      The variable :code:`kangas_mood` has explicitly specified that no mappings are possible by using the :code:`none` interface type.
      For this mapping to be valid, the type needs to be :code:`public`.

    - Mapping D is not valid.
      Because they are sibling components, the variables in :code:`ChristopherRobin` and :code:`Kanga` must both have the interface type of :code:`public` in order to be valid ... but there's a twist.

    - Mapping E is currently valid, because variables in component :code:`Kanga` can only access variables in its child component :code:`Roo` with a :code:`private` interface.
      But if Mapping D is to be made valid, that same variable must maintain a :code:`public` interface in order to access variables in its sibling component :code:`ChristopherRobin`.
      It is for this reason that the :code:`public_and_private` interface type exists.
      For Mappings D and E to be valid, the variable :code:`roos_mood` in component :code:`Kanga` must have an interface type of :code:`public_and_private`.
    
    The corrected model is shown below.

    .. code::

      model: TheHouseAtPoohCorner
        ├─ component: ChristopherRobin
        │   ├─ variable: my_mood (interface: none)
        │   ├─ variable: average_mood_of_everyone (interface: none)
        │   ├─ variable: roos_mood (interface: public) <╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┐
        │   ├─ variable: kangas_mood (interface: public) <╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┐╷
        │   ├─ variable: eeyores_mood (interface: public) <╴╴╴╴╴╴╴╴╴╴╴╴╴┐╷╷
        │   └─ variable: poohs_mood (interface: public) <╴╴╴╴╴╴╴╴╴╴╴╴╴╴┐╷╷╷
        │                                                              ╷╷╷╷
        ├─ component: WinnieThePooh                                    ╷╷╷╷
        │   └─ variable: mood (interface: public) ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘╷╷╷
        ├─ component: Eeyore                                            ╷╷╷
        │   └─ variable: mood (interface: public) ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘╷╷
        └─ component: Kanga                                              ╷╷
            │  ├─ variable: mood (interface: public) ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴ ╴╴╴╴┘╷
            │  └─ variable: roos_mood (interface: public_and_private) <╴╴╴┤
            └─ component: Roo                                             ╷
                └─ variable: mood (interface: public) ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘
      
    .. container:: toggle

      .. container:: header

        See CellML syntax

      .. code-block:: xml

        <model name="TheHouseAtPoohCorner">

          <!-- Defining the components and local variables. -->
          <component name="ChristopherRobin">
            <variable name="my_mood" interface_type="none" units="mood_score" />
            <variable name="average_mood_of_everyone" interface_type="none" units="mood_score" />
            <variable name="roos_mood" interface_type="public" units="mood_score" />
            <variable name="kangas_mood" interface_type="public" units="mood_score" />
            <variable name="eeyores_mood" interface_type="public" units="mood_score" />
            <variable name="poohs_mood" interface_type="public" units="mood_score" />
          </component>

          <component name="WinnieThePooh">
            <variable name="mood" interface_type="public" units="mood_score" />
          </component>

          <component name="Eeyore">
            <variable name="mood" interface_type="public" units="mood_score" />
          </component>

          <component name="Kanga">
            <variable name="mood" interface_type="public" units="mood_score" />
            <!-- The utility variable roos_mood is included here so that it can pass
                 the value of mood in component Roo to roos_mood in component ChristopherRobin. -->
            <variable name="roos_mood" interface_type="public_and_private" units="mood_score" />
          </component>

          <component name="Roo">
            <variable name="mood" interface_type="public" units="mood_score" />
          </component>

          <!-- Defining connections and mapped variables. -->
          <connection component_1="ChristopherRobin" component_2="WinnieThePooh">
            <map_variables variable_1="poohs_mood" variable_2="mood" />
          </connection>

          <connection component_1="ChristopherRobin" component_2="Kanga">
            <map_variables variable_1="kangas_mood" variable_2="mood" />
            <map_variables variable_1="roos_mood" variable_2="roos_mood" />
          </connection>

          <connection component_1="ChristopherRobin" component_2="Eeyore">
            <map_variables variable_1="eeyores_mood" variable_2="mood" />
          </connection>

          <connection component_1="Kanga" component_2="Roo">
            <map_variables variable_1="roos_mood" variable_2="mood" />
          </connection>
          
        </model>
