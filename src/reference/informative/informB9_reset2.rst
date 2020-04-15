.. _informB9_2:
.. _inform_reset2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Reset variables and test variables

    Consider the following model which simulates an old-fashioned automatic gearbox in a car, which changes gears based on the speed of revolution in the engine.

    .. code::

      model: AutomaticTransmission
        ├─ component: Gearbox
        │   └─ variable: ratio (dimensionless)
        └─ component: Engine
            └─ variable: revs (hertz)

    .. code-block:: xml

      <model name="AutomaticTransmission">
        <component name="Gearbox">
          <variable name="ratio" units="dimensionless" initial_value="3" />
        </component>
        <component name="Engine">
          <variable name="revs" units="hertz" initial_value="0" />
        </component>
      </model>

    When the engine's revs get over 60 Hertz (3600rpm) then two things happen: the gearbox should change up a gear by reducing the ratio by 30%, and the engine's revs should drop by that same 30%.
    Because this behaviour involves discrete changes in value, resets are a good way model it.
    Let's add them now.

    .. code::

      model: AutomaticTransmission
        ├─ component: Gearbox
        │   └─ variable: ratio (dimensionless)
        │       └─ reset: want to change gear when revs are too high, but don't know the revs?
        │                  
        └─ component: Engine
            └─ variable: revs (hertz)
                └─ reset: want to reduce revs when the gear is changed, but don't know the gear?

    .. container:: toggle

      .. container:: header

        Show CellML syntax

      .. code-block:: xml

        <model name="AutomaticTransmission">
          <component name="Gearbox">
            <variable name="ratio" units="dimensionless" initial_value="3" />

            <!-- Invalid: the test_variable "revs" is outside of the "Gearbox" component. -->
            <reset variable="ratio" test_variable="revs" order="1" >
              ...
            </reset>

          </component>
          <component name="Engine">
            <variable name="revs" units="hertz" initial_value="0" />

            <!-- Invalid: the variable "ratio" is outside of the "Engine" component. -->
            <reset variable="ratio" test_variable="revs" order="2" >
              ...
            </reset>

          </component>
        </model>

    This example illustrates the fact that both the :code:`variable` and :code:`test_variable` attributes must refer to :code:`variable` elements in the same :code:`component` as the :code:`reset` is sitting.
    It can be fixed by either setting up some variable equivalences to map the required variables from one component to another, as shown below:

    .. code::

                  model: AutomaticTransmission
                    ├─ component: Gearbox
              ┌╴╴╴╴╴╴╴╴╴╴├─ variable: ratio (dimensionless)
              ╷     │    │    │
              ╷     │    │    ├─ reset: change ratio based on engine_revs
              ╷     │    │    │
              ╷ ┌╴╴╴╴╴╴╴>└─ variable: engine_revs (hertz)
              ╷ ╷   │
         equivalent │
          variables │
              ╵ ╵   └─ component: Engine
              ╵ └╴╴╴╴╴╴╴╴├─ variable: revs (hertz)
              ╵          │    │
              ╵          │    ├─ reset: change revs based on gear_ratio
              ╵          │    │
              └╴╴╴╴╴╴╴╴╴>└─ variable: gear_ratio (dimensionless)

    .. container:: toggle

      .. container:: header

        Show CellML syntax

      .. code-block:: xml

        <model name="AutomaticTransmission">
          <component name="Gearbox">
            <variable name="ratio" units="dimensionless" initial_value="3" />
            <variable name="engine_revs" units="hertz" />

            <!-- Valid: the test_variable "engine_revs" is now inside 
                the "Gearbox" component. -->
            <reset variable="ratio" test_variable="engine_revs" order="1" >
              ...
            </reset>
          </component>
          <component name="Engine">
            <variable name="revs" units="hertz" initial_value="0" />
            <variable name="gear_ratio units="dimensionless" />

            <!-- Valid: the variable "gear_ratio" is now inside the "Engine"
                component. -->
            <reset variable="ratio" test_variable="revs" order="2" >
              ...
            </reset>
          </component>

          <!-- Defining the equivalent variable mappings which enables
              them to be shared above. -->
          <connection component_1="Gearbox" component_2="Engine">
            <map_variables variable_1="ratio" variable_2="gear_ratio" />
            <map_variables variable_1="engine_revs" variable_2="revs" />
          </connection>
        </model>

    This example highlights the need for both the reset variable and the test variable to be local to the reset's parent component, and also brings up the possiblity of circular dependencies in resets.
    This latter issue will be discussed in the following "See more" block regarding the :code:`order` attribute.
