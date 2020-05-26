.. _informB7_2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    A :code:`component` item, as with every other part of CellML, must use a name unique to its scope, and obey the format definitions outlined in :numref:`{number} {name}<specA_data_representation_formats>`.
    For example:

    .. code-block:: xml

      <!-- This is valid: -->
      <component name="myValidName"> ... </component>

      <!-- Not valid: the units name attribute is not a valid CellML identifier. -->
      <component name="I'm not valid!"> ... </component>

      <!-- Not valid: duplicted component names are not allowed. -->
      <component name="duplicatedName"> ... </component>
      <component name="duplicatedName"> ... </component>

      <!-- Not valid: duplicating the name of an imported component item is not allowed. -->
      <import xlink:href="handyComponentsForImport.cellml">
        <component component_ref="myComponentRef" name="duplicatedName">
      </import>
