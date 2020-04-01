.. _informB13:


.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    Encapsulation is the way that CellML manages the hierarchy of components and keeps their modularity.
    This is why there can be only one :code:`encapsulation` element within a :code:`model`: you can think of it as a table of contents for components in the whole model.

    Encapsulations don't have to include all of the model's components - only the ones which need to sit within another component.
    Components which are not listed within the encapsulation are top-level children of the :code:`model`.

    .. code-block:: xml

        <!--  Valid encapsulation structure.  This will give the arrangement of:
                - grandad
                    - father
                        - child
                    - aunt
                - orphan
          Because the component named "orphan" is not included in the encapsulation
          it will stay at the top level of the model. -->
        <model name="I_am_a_valid_model">
          <component name="grandad"/>
          <component name="aunt"/>
          <component name="father"/>
          <component name="child"/>
          <component name="orphan">
          <encapsulation>
            <component_ref component="grandad">
              <component_ref component="aunt"/>
              <component_ref component="father">
                <component_ref component="child"/>
              </component_ref>
            </component_ref>
          </encapsulation>
        </model>

        <!-- Invalid: More than one encapsulation is not permitted -->
        <model name="too_many_encapsulations">
          <component name="parent1"/>
          <component name="child1"/>
          <component name="parent2"/>
          <component name="child2"/>
          <encapsulation>
            <component_ref component="parent1">
              <component_ref component="child2"/>
            </component_ref>
          </encapsulation>
          <encapsulation>
            <component_ref component="parent2">
              <component_ref component="child2"/>
            </component_ref>
          </encapsulation>
        </model>

        <!-- Invalid: A component cannot appear more than once in an encapsulation -->
        <model name="duplicated_component_ref">
          <component name="parent"/>
          <component name="child"/>
          <encapsulation>
            <component_ref component="parent">
              <component_ref component="child">
                <component_ref component="parent"/>
              </component_ref>
            </component_ref>
          </encapsulation>
        </model>

        <!-- Valid, but redundant: An encapsulation can be empty, but this is the default 
             condition so its inclusion alters nothing. -->
        <model name="empty_encapsulation">
          <component name="parent"/>
          <component name="child"/>
          <encapsulation>
          </encapsulation>
        </model>

        <!-- Valid, but redundant: An encapsulation must have a minimum of two levels of children
             to affect the model's structure.  This still represents the default condition. --> 
        <model name="duplicated_component_ref">
          <component name="parent"/>
          <component name="child"/>
          <encapsulation>
            <component_ref component="parent">
              <!-- There has to be a child here or the parent is not a parent ... -->
            </component_ref>
          </encapsulation>
        </model>

