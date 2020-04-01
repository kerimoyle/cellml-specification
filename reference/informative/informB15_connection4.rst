.. _informB15_4:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    You may only have one :code:`connection` any two :code:`components`, regardless of which is specified as :code:`component_1` and which is specified as :code:`component_2`.
    If you have found duplicate :code:`connection` elements, simply merge their contents - a :code:`connection` can contain any number of :code:`map_variables` children.
    Make sure that the order in which you specify the :code:`component` attributes matches the order in which you specify their child :code:`variable` items too: ie, all :code:`variable_1` items must be within the :code:`component_1` component and vice versa.

    .. code-block:: xml

        <!-- This is not valid CellML -->
        <model>
            <component name="house_of_capulet">
                <variable name="juliet" interface_type="public">
                <variable name="rosaline" interface_type="public">
            </component>
            <component name="house_of_montague">
                <variable name="romeo" interface_type="public">
            </component>

            <connection component_1="montague" component_2="capulet">
                <map_variables variable_1="romeo" variable_2="juliet">
            </connection>

            <!-- This connection duplicates the one above, even though -->
            <!-- component_1 and component_2 are swapped -->
            <connection component_1="capulet" component_2="montague">
                <map_variables variable_1="rosaline" variable_2="romeo">
            </connection>
        </model>

        <!-- This is now valid: The contents were merged to create a valid model -->
        <model>
            <component name="house_of_capulet">
                <variable name="juliet" interface_type="public">
                <variable name="rosaline" interface_type="public">
            </component>
            <component name="house_of_montague">
                <variable name="romeo" interface_type="public">
            </component>

            <!-- The contents have been merged. Note that the order of variables -->
            <!-- must match the order of the parent component, i.e.: all variable_1s
            <!-- must be within component_1 etc. -->
            <connection component_1="montague" component_2="capulet">
                <map_variables variable_1="romeo" variable_2="juliet">
                <map_variables variable_1="romeo" variable_2="rosaline">
            </connection>
        </model>

