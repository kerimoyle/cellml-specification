.. _informB15_3:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    All this means is that mapped/connected variables (ie: those specified by
    :code:`connection` and :code:`map_variables` items) must be in different
    components. Since the only reason you'd need to use these connections is
    in order to access a variable in another component, this restriction does
    make sense!

    .. code-block:: xml

        <model>
            <component name="happily_ever_after">
                <variable name="juliet" interface_type="public">
                <variable name="romeo" interface_type="public">
            </component>

            <!-- This is a not valid because component_1 and component_2 are the same -->
            <connection component_1="happily_ever_after" component_2="happily_ever_after">
                <map_variables variable_1="romeo" variable_2="juliet">
            </connection>
        </model> 
