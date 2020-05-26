.. _informB3_1:

.. container:: toggle

    .. container:: header

        Read more

    .. container:: infospec

      Importing units means that you're assured of consistency between your models, and allows for a more modular reuse of the components which use them.
      There are three ingredients required in importing any item:

        - A destination item in the importing model (this is the :code:`units` item called :code:`smallPotOfPaint` in the example below).

        - A file to import from, specified using the :code:`xlink:href` attribute of the parent :code:`import` block.
          This is discussed in more detail in :numref:`{number} {name}<specB_import>`.
          In the example below this is the :code:`paint_pot_sizes.cellml` file.

        - The specific item name to retrieve from the imported file.
          In the example below this is the :code:`twoLitrePot` value passed to the :code:`units_ref` attribute.

      Thus we can read the import statement below as: "retrieve the :code:`units` named :code:`twoLitrePot` from the file :code:`paint_pot_sizes.cellml`, and store it here in this model under the name :code:`potOfPaint`".

      .. code-block:: xml

        <import xlink:href="paint_pot_sizes.cellml" xmlns:xlink="http://www.w3.org/1999/xlink">
           <units units_ref="twoLitrePot" name="potOfPaint"/>
        </import>

      Note that if you've already defined the namespace inside the :code:`<model>` tags then you would not need to repeat it here.

      Imported items have the same restrictions as concrete items regarding the uniqueness of their names.
      In the example below, the name :code:`potOfPaint` is used for the locally defined units in line 2, but the same name is used as the name for the imported units in line 6.
      This is not permitted as it violates the :ref:`unique name<issue_units_name>` requirement.

      .. code-block:: xml

        <model name="paintingTheHouse">
          <units name="potOfPaint">
            <unit units="metre" exponent="3" multiplier="0.002">
          </units>

          <!-- This destination name conflicts with the locally defined name above -->
          <import xlink:href="paint_pot_sizes.cellml" xmlns:xlink="http://www.w3.org/1999/xlink">
            <units units_ref="twoLitrePot" name="potOfPaint"/>
          </import>
          <component name="paintCalculator">
            ...
          </component>
        </model>
