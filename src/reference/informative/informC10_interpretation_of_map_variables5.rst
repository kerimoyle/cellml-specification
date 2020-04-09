.. _informC10_interpretation_of_map_variables5:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding interfaces

    There are two hurdles to get past before variables can be mapped to one another.
    The first is the relative position within the encapsulation hierarchy of the :code:`variable` elements' parent :code:`component` elements (as discussed in :ref:`Interpretation of encapsulation<specC_interpretation_of_encapsulation>`, and the second is the value of the :code:`interface_type` attribute given to each :code:`variable` itself.
    This means that even if two components are sufficiently close relatives that they *can* be connected, the modeller still has control at the individual variable level as to which of those relatives can have access.

    The :code:`interface_type` attribute value choices are: 
    - :code:`public` (used by child components to reference their parent, or between siblings),
    - :code:`private` (used by parent components to reference their children), 
    - :code:`public_and_private` (used by all near relatives), or
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
        │   ├─ variable: my_mood (interface: none)
        │   ├─ variable: average_mood_of_everyone (interface: public)
        │   ├─ variable: roos_mood (interface: public) <╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┐
        │   ├─ variable: kangas_mood (interface: public) <╴╴╴╴╴╴┐       ╷
        │   ├─ variable: eeyores_mood (interface: none) <╴╴╴╴╴╴┐╷       ╷
        │   └─ variable: poohs_mood (interface: public) <╴╴╴╴╴┐╷╷       ╷
        │                                                     ╷╷╷  utility variable added so  
        ├─ component: WinnieThePooh                           ╷╷╷  that Roo's mood can be passed
        │   └─ variable: mood (interface: private)  ╴╴╴╴╴╴╴╴╴╴┘╷╷  down to Christopher Robin
        ├─ component: Eeyore                                   ╷╷       ╵
        │   └─ variable: mood ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴xx╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘╷       ╵
        └─ component: Kanga                                     ╷       ╵
            │  ├─ variable: mood (interface: private) ╴╴╴╴╴╴╴╴╴╴┘       ╵
            │  └─ variable: roos_mood (interface: public_and_private) ╴╴┤
            └─ component: Roo                                           ╷
                └─ variable: mood (interface: public) ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘

    

