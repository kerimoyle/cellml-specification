.. _informC06_interpretation_of_initial_values:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    Best practice suggests that the :code:`initial_value` attribute is used to set the initial values only, rather than to simply set the value of a :code:`variable`.  
    Initialising a variable is different from setting the value of a variable; the former is true only at the *beginning* of a simulation, whereas the latter is true *throughout* the simulation.
    The option to use a variable reference for initialisation is provided in CellML 2.0 to enable easier migration from CellML 1.1 models, and may not be supported in future releases.
    Consider the model below which describes the countdown in a game of hide and seek.  **TODO** put in proper time equation?

    .. code-block:: xml

      <model name="games">
        <component name="hide_and_seek">
          <variable name="countdown_start" units="second" initial_value="100"/>
          <variable name="counter" units="second" initial_value="countdown_start" />
          <variable name="time" units="second" />
          <math>
            <apply><eq/>
              <ci>counter</ci>
              <apply><minus/>
                <ci>countdown_start</ci>
                <ci>time</ci>
              </apply>
            </apply>
          </math>
        </component>

        <component name="hiding_games">
          <variable name="time" units="second" />
        </component>

        <component name="sardines" />

        <!-- Creating a generic component to hold global variables like time -->
        <component name="parameters">
          <variable name="time" units="second" initial_value="0" />
        </component>

        <!-- Encapsulating the games into the hiding_games component -->
        <encapsulation>
          <component_ref component="hiding_games">
            <component_ref component="hide_and_seek"/>
            <component_ref component="sardines"/>
          </component_ref>
        </encapsulation>

        <!-- Connect the time variable into the other components -->
        <connection component_1="parameters" component_2="hiding_games">
          <map_variables variable_1="time" variable_2="time" />
        </connection>
        <connection component_1="hiding_games" component_2="hide_and_seek">
          <map_variables variable_1="time" variable_2="time" />
        </connection>
      </model>

    This is valid CellML and will work as expected, but it uses a constant (the :code:`initial_value` on the :code:`countdown_start` variable) embedded within the deepest level of the encapsulation, which makes it more difficult to restart the game from different countdown points.
    A better way to organise the model is shown below, annotated with the differences as appropriate.

    .. code-block:: xml

      <model name="games">
        <component name="hide_and_seek">

          <!-- Remove the initial_value attribute from this deeply encapsulated component, and move it to the "parameters" component instead -->
          <variable name="countdown_start" units="second" />
          <variable name="counter" units="second" initial_value="countdown_start" />
          <variable name="time" units="second">
          <math>
            <apply><eq/>
              <ci>counter</ci>
              <apply><minus/>
                <ci>countdown_start</ci>
                <ci>time</ci>
              </apply>
            </apply>
          </math>
        </component>
        <component name="sardines"/>

        <!-- Define (or import) a top-level component used for setting all parameters, constants, and initial values -->
        <component name="parameters">
          <variable name="time" units="second" />

          <!-- Moving the initialisation of the countdown start into this top-level component -->
          <variable name="hide_and_seek_start" initial_value="100" />
        </component>

        <!-- Add a new transfer variable throughout the encapsulation hierarchy -->
        <component name="hiding_games">
          <variable name="time" units="second" />
          <variable name="hide_and_seek_start" units="second" />
        </component>

        <encapsulation>
          <component_ref component="hiding_games">
            <component_ref component="hide_and_seek"/>
            <component_ref component="sardines"/>
          </component_ref>
        </encapsulation>

        <!-- Connect the initialisation variable thoughout the encapsulation hierarchy -->
        <connection component_1="parameters" component_2="hiding_games">
          <map_variables variable_1="time" variable_2="time" />
          <map_variables variable_1="hide_and_seek_start" variable_2="hide_and_seek_start">
        </connection>
        <connection component_1="hiding_games" component_2="hide_and_seek">
          <map_variables variable_1="time" variable_2="time" />
          <map_variables variable_1="hide_and_seek_start" variable_2="countdown_start" />
        </connection>

      </model>

    Moving the initialisation out of the encapsulation hierarchy and into a top-level component allows us to more easily adjust the parameters of the game, as well as making its use more modular so that it can be shared with others.


      
    
     