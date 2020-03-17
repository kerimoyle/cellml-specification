.. _informB16_2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    Points 16.1.1 and 16.1.2 are both saying the same thing for their
    :code:`variable_1` and :code:`variable_2` attributes respectively:

    .. code-block:: xml

        <model>
            <component name="house_of_capulet">
                <variable name="juliet" interface_type="public">
            </component>
            <component name="house_of_montague">
                <variable name="romeo" interface_type="public">
            </component>

            <!-- This is a valid CellML2.0 connection -->
            <connection component_1="montague" component_2="capulet">
                <map_variables variable_1="romeo" variable_2="juliet">
            </connection>

            <!-- Invalid: the variable_1 value is not a valid CellML identifier (special characters and spaces) -->
            <connection component_1="montague" component_2="capulet">
                <map_variables variable_1="Romeo, Romeo ..." variable_2="juliet">
            </connection>

            <!-- Invalid: the variable_2 value does not exist in component_2 -->
            <connection component_1="montague" component_2="capulet">
                <map_variables variable_1="romeo" variable_2="juliet_is_the_sun">
            </connection>
        </model>

    

