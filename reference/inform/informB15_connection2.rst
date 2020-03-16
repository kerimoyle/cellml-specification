.. _informB15_2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    Creating :code:`connection` items allows :code:`variable` values to be
    passed between eligible :code:`components`.  There are both syntactic (ie:
    format) and semantic (ie: meaning) rules about how these must be specified,
    including what "eligible" means.  Syntax will be discussed below and in the
    other "See more" blocks on this page.  For more on the semantic rules,
    please see :ref:`Interpretation of map_variables<specC_interpretation_of_map_variables>.`
    
    Points 15.1.1 and 15.1.2 are both saying the same thing.  The way in which
    you specify the :code:`component_1` and :code:`component_2` items must
    follow the general CellML2.0 format for a valid identifier, and must point
    to a :code:`component` which exists under that name.  Note that this
    could be either an intantiated :code:`component`, or an
    :code:`import component` item.

    .. code-block:: xml

        <!-- This is a valid CellML2.0 connection -->
        <model>
            <component name="house_of_capulet">
                <variable name="juliet" interface_type="public">
            </component>
            <component name="house_of_montague">
                <variable name="romeo" interface_type="public">
            </component>
            <connection component_1="montague" component_2="capulet">
                <map_variables variable_1="romeo" variable_2="juliet">
            </connection>
        </model>
    
        <!-- This is not valid ... -->
        <model>
            <component name="house_of_capulet">
                <variable name="juliet" interface_type="public">
            </component>
            <component name="house_of_montague">
                <variable name="romeo" interface_type="public">
            </component>
            <!-- The component_2 attribute does not exist as a component or import component name -->
            <connection component_1="house_of_montague" component_2="Capulet">
                <!-- The variable_1 name is not a valid CellML identifier -->
                <map_variables variable_1="Romeo, Romeo ..." variable_2="juliet">
            </connection>
        </model>

