.. _informB9_2:
.. _inform_reset2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    Consider the following example which represents the mythological story of Sisyphus, king of Ephrya.
    He was condemned to roll a huge boulder up a mountain each day, but, as it reached the top, the boulder would roll to the bottom so he had to begin again.

    .. code::

      model: Tartarus
        └─ component: Sisyphus
            ├─ variable: time
            └─ variable: position
                └─ reset:
                    ├─ when: time is midnight
                    └─ then: position is bottom of hill

    In this example it's clear that for the reset to operate, it must know what is happening and when; in other words, that the :code:`variable` attribute as well as the :code:`test_variable` attribute must be specified.
    This is shown in the CellML syntax block below.

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

    
    Examples of invalid configurations include when either the :code:`variable` or :code:`test_variable` attributes are unspecified, or when they do not refer to variables local to the reset's component.

    .. container:: toggle

      .. container:: header

        Show CellML syntax

      .. code-block:: xml

        
        <model name="Tartarus">
          <component name="Sisyphus">
            <variable name="time_of_day" units="second" />
            <variable name="position" units="dimensionless" />

            <!-- This is not valid: The test variable has not been specified. -->
            <reset variable="position" order="1">
              ...
            </reset>

            <!-- This is not valid: The reset variable has not been specified. -->
            <reset test_variable="time" order="1">
              ...
            </reset>

          </component>
        </model>

        
        <model name="Tartarus">
          <component name="Sisyphus">
            <variable name="time_of_day" units="second" />
            <variable name="position" units="dimensionless" />

            <!-- This is not valid: The test variable "eternity_time" does not exist 
                 in the reset's component. -->
            <reset variable="position" test_variable="eternity_time" order="1">
              ...
            </reset>

          </component>
        </model>

        
        <model name="Tartarus">

          <!-- This is not valid: The reset variable "position" is in component  Sisyphus ... -->
          <component name="Sisyphus">
            <variable name="position" units="dimensionless" />
          </component>

          <!-- ... but the reset which changes it is in component "RulerOfTartarus". -->
          <component name="RulerOfTartarus">
            <variable name="time" units="second" />
            <reset variable="position" test_variable="time" order="1">
              ...
            </reset>
          </component>

        </model>

