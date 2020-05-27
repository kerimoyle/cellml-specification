.. _informC09_interpretation_of_encapsulation3:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    Before two :code:`variable` elements can be connected or mapped to one another, two set of rules must be followed.
    The first rule is that the variables' parent :code:`component` elements must not be hidden from one another (as stated in :hardcodedref:`3.9.7`), and the second (found in :hardcodedref:`3.10.9-10`) is that the :code:`interface_type` attributes of the variables must not exclude their connection either.

    .. container:: heading3

      Understanding hidden sets and connections

    It's easier to define *hidden* components by defining those which are not hidden first. 
    Basically, one degree of separation is all that is "seen" by any component.
    This means that *parent* components can see their children, and children their parents.
    Sibling components (including those who are top-level children of the :code:`model` element) are visible to one another as well.
    Components in any other relationships are too distant to be visible, and are therefore *hidden* from each other.

    Reusing the same example as earlier, we can see that:

    - :code:`LukeClampett` is hidden from :code:`EllyMayClampett` (grandfather/grandchild)
    - :code:`AmosClampett` is hidden from :code:`MyrtleClampett` (uncle/niece)
    - :code:`PearlBodine` is hidden from :code:`JedClampett` (cousins) 
    - :code:`GrannyMoses` is hidden from :code:`LukeClampett` (great-aunt/great-nephew) 

    .. code::

      model: TheBeverlyHillbillies
        ├─ component: GrannyMoses
        ├─ component: MissJane
        └─ component: ClampettFamily
            ├─ component: LukeClampett
            │   ├─ component: MyrtleClampett
            │   └─ component: JedClampett
            │       └─ component: EllyMayClampett
            └─ component: AmosClampett
                └─ component: PearlBodine
                    ├─ component: JethroBodine
                    └─ component: JethrineBodine

    .. code-block:: xml

      <!-- None of the following connections are possible as their 
            components are hidden from one another. -->

      <!-- Grandfather and grandchild. -->
      <connection component_1="LukeClampett" component_2="EllyMayClampett" />

      <!-- Uncle and niece. -->
      <connection component_1="AmosClampett" component_2="MyrtleClampett" />
      
      <!-- Cousin and cousin. -->
      <connection component_1="PearlBodine" component_2="JedClampett" />

      <!-- Great-aunt and great-nephew. -->
      <connection component_1="GrannyMoses" component_2="LukeClampett" />
    
    The second rule above addresses the restrictions around which :code:`variable` elements are able to access one another.
    This is a little more complicated, and explained in more detail in the informative block in :numref:`{number} {name}<specC_interpretation_of_map_variables>`.
