.. _informB16_3:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    Just as you can have only one :code:`connection` between any two :code:`components`, within that :code:`connection` you can have only one :code:`map_variables` item between any two :code:`variables`.

    .. code-block:: xml

        <model>
            <component name="house_of_capulet">
                <variable name="juliet" interface_type="public">
            </component>
            <component name="house_of_montague">
                <variable name="romeo" interface_type="public">
            </component>
            <connection component_1="montague" component_2="capulet">
                <map_variables variable_1="romeo" variable_2="juliet">
                <!-- Invalid: You may not duplicate the mapping above -->
                <map_variables variable_1="romeo" variable_2="juliet">
            </connection>
        </model>
