.. _informB9_2:
.. _inform_reset2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    Consider the following example which represents the mythological story of Sisyphus, king of Ephrya.
    He was condemned to roll a huge boulder up a mountain each day, but, as it reached the top, the boulder would roll to the bottom and he had to begin again.

    .. code::

      model: Tartarus
        └─ component: Sisyphus
            ├─ variable: time
            └─ variable: position
                └─ reset:
                    ├─ when: time is midnight
                    └─ then: position is bottom of hill

    .. container:: toggle

      .. container:: header

        Show CellML syntax

      .. code-block:: xml

        <!-- This is valid: both the reset variable "position" and the 
             test_variable "time" are in the same component as the reset
             which uses them. -->
        <model name="Tartarus">
          <component name="Sisyphus">
            <variable name="time" units="second" />
            <variable name="position" units="dimensionless" />
            <reset variable="position" test_variable="time" order="1">
              ...
            </reset>
          </component>
        </model>

        <!-- This is not valid: The test variable "eternity_time" does not exist 
             in the same component as the reset. -->
        <model name="Tartarus">
          <component name="Sisyphus">
            <variable name="time_of_day" units="second" />
            <variable name="position" units="dimensionless" />
            <reset variable="position" test_variable="eternity_time" order="1">
              ...
            </reset>
          </component>
        </model>

        <!-- This is not valid: The reset variable "position" is in component 
             "Sisyphus", but the reset which changes it is in component 
             "RulerOfTartarus". -->
        <model name="Tartarus">
          <component name="Sisyphus">
            <variable name="position" units="dimensionless" />
          </component>
          <component name="RulerOfTartarus">
            <variable name="time" units="second" />
            <reset variable="position" test_variable="time" order="1">
              ...
            </reset>
          </component>
        </model>

