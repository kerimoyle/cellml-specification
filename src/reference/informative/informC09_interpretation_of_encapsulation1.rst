.. _informC09_interpretation_of_encapsulation1:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    You can think of an encapsulation structure as a tree.
    The model is the tree's trunk, and each component at the top-level of the model is a branch.
    Subsequent generations of branches can stem from any component, but no two branches can recombine or belong to more than one parent, as this would create a loop. 
    Any component not listed inside the encapsulation is a top-level component (a branch off the trunk).

    An encapsulation hierarchy is specified using a single :code:`encapsulation` element, and any number of generations of :code:`component_ref` children.
    Where no :code:`encapsulation` element is present, all :code:`component` elements have the same level; they branch off the :code:`model`\-trunk.

    Some examples of valid and invalid encapsulation structures are shown below.

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

      <!-- Invalid: More than one encapsulation is not permitted. -->
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

      <!-- Invalid: A component cannot appear more than once in an encapsulation. -->
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
            <!-- There has to be a child here or the parent is not a parent. -->
          </component_ref>
        </encapsulation>
      </model>
