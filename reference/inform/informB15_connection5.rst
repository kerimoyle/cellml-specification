.. _informB15_5:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    The point of creating a :code:`connection` item is in order to connect
    :code:`variables` between eligible components.  There is no reason to
    have an empty :code:`connection` - just delete it.

    .. code-block:: xml

        <!-- This is a valid CellML2.0 connection -->
        <model>
            <component name="house_of_capulet">
                <variable name="juliet" interface_type="public">
            </component>
            <component name="house_of_montague">
                <variable name="romeo" interface_type="public">
            </component>
            
            <!-- an empty connection is meaningless, just delete it! -->
            <connection component_1="montague" component_2="capulet">
            </connection>
        </model>  
