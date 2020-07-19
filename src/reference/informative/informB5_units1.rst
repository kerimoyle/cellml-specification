.. _informB5:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    The best way to understand how :code:`units` work is to read the informative sections within the :numref:`{number} {name}<unit>` in the next section, which defines their child :code:`unit` items.

    The following examples show examples of what is not permitted when defining :code:`units` items.

    .. code-block:: xml

        <!-- The units name attribute is not a valid CellML identifier. -->
        <units name="I'm not valid!"> ... </units>

        <!-- Duplicted local units names are not allowed. -->
        <units name="duplicatedName"> ... </units>
        <units name="duplicatedName"> ... </units>

        <!-- Duplicated name of an imported units item is not allowed. -->
        <import xlink:href="handyUnitsForImport.cellml">
            <units units_ref="myCustomUnits" name="duplicatedName">
        </import>

        <!-- Duplicating the name of built-in units is not allowed. -->
        <units name="metre"> ... </units>
