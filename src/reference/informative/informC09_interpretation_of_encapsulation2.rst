.. _informC09_interpretation_of_encapsulation1:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    In the informative block above we used the analogy of a tree to describe the encapsulation structure, but the language around it is closer to a family tree in which there are only single parents allowed.
    With this in mind, the points above become clear.

    - :hardcodedref:`3.9.3` defines the "encapsulation set" of a component as its direct component children.
    - :hardcodedref:`3.9.4` makes clear that there can only be single parents in this family tree.
    - :hardcodedref:`3.9.5` defines siblings as those :code:`component` elements which share a parent, be that parent a :code:`component` element or the :code:`model` element itself.
    - :hardcodedref:`3.9.6` defines the "hidden set" of any :code:`component` as those other :code:`component` elements which are neither the parent, the children, nor the siblings of that current :code:`component` element.

    These distinctions become important when considering the kind of :code:`connection` elements which may be formed, and in determining the available :code:`interface_type` attribute values which are available to a component's :code:`variable` children.

    Some examples are shown below.

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

    .. container:: toggle

      .. container:: header

        See CellML syntax

      .. code-block:: xml

        <model name="TheBeverlyHillbillies">
          <!-- Note that the first two components here are not listed inside the 
               encapsulation. They are, by default, siblings of each other,
               as well as of the root component (ClampettFamily) of the
               encapsulation structure. -->
          <component name="GrannyMoses" />
          <component name="MissJane" />
          <component name="ClampettFamily" />

          <component name="LukeClampett" />
          <component name="AmosClampett" />
          <component name="MyrtleClampett" />
          <component name="JedClampett" />
          <component name="EllyMayClampett" />
          <component name="PearlBodine" />
          <component name="JethroBodine" />
          <component name="JethrineBodine" />

          <encapsulation>
            <component_ref component="ClampettFamily">
              <component_ref component="LukeClampett">
                <component_ref component="MyrtleClampett">
                </component_ref>
                <component_ref component="JedClampett">
                  <component_ref component="EllyMayClampett"/>
                </component_ref>
              </component_ref>
              <component_ref component="AmosClampett">
                <component_ref component="PearlBodine">
                  <component_ref component="JethroBodine"/>
                  <component_ref component="JethrineBodine"/>
                </component_ref>
              </component_ref>
          </encapsulation>
        </model>

    In this example, we can see that the *encapsulation set* (or direct children) of component :code:`PearlBodine` are the twins :code:`JethroBodine` and :code:`JethrineBodine`.
    Similarly, :code:`LukeClampett` is the *parent* of :code:`MyrtleClampett` and :code:`JedClampett`.
    Several sets of *siblings* are fairly easy to spot: 

    - :code:`JethroBodine` and :code:`JethrineBodine`,
    - :code:`LukeClampett` and :code:`AmosClampett`, and
    - :code:`MyrtleClampett` and :code:`JedClampett`.

    Other *siblings* that are not as clear at first glance are :code:`GrannyMoses`, :code:`MissJane`, and the placeholder :code:`ClampettFamily`, by virtue of their common *parent*, :code:`TheBeverlyHillbillies` model itself.
