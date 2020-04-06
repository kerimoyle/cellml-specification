.. _informB15_5:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    The point of creating a :code:`connection` item is in order to connect :code:`variables` between eligible :code:`components`.
    You are allowed to have an empty :code:`connection`, but it is meaningless.

    .. code-block:: xml

        <model>
            <component name="house_of_capulet">
                <variable name="juliet" interface_type="public">
            </component>
            <component name="house_of_montague">
                <variable name="romeo" interface_type="public">
            </component>

            <!-- Valid but redundant: an empty connection is meaningless. -->
            <connection component_1="montague" component_2="capulet">
            </connection>
        </model>
