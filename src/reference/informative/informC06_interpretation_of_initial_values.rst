.. _informC06_interpretation_of_initial_values:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3
        
        Cycles within initial values
   
    As with other places, it's possible to set initial conditions which are valid in syntax but lacking in sense.
    The examples below are technically valid CellML, but they will not lead to meaningful models.

    .. code-block:: xml

      <component name="cyclical_initialisation" >
        <variable name="A" initial_value="B" units="dimensionless"/>
        <variable name="B" initial_value="A" units="dimensionless"/>
      </component>

      <component name="self_initialisation" >
        <variable name="C" initial_value="C" units="dimensionless"/>
      </component>


    .. container:: heading3

        Best practice for constants, variables, and initial conditions
    

    - A :code:`variable` whose value needs to be set for only the *beginning* of a simulation is initialised using the :code:`initial_value` attribute. 
      
        - This is most frequently used for state variables (those whose value is found by solving a differential equation).
        - It may also be used for variables whose values will be reset during the course of the simulation.
          Please see :ref:`The reset element<_reset>` section for details.
        - It's possible - but not recommended - to use a variable reference with the :code:`initial_value` attribute.
          This option remains in CellML 2.0 only to provide ease of migration from CellML 1.1 models, and may be discontinued in future versions. 
      
    - A :code:`variable` whose value is *constant* throughout the simulation is best set within the :code:`math` block, rather than via the :code:`initial_value` attribute.  
      This is so that its value will be held to be true *throughout* the simulation, rather than only the beginning. 

    - A :code:`variable` which is not a state variable, and whose value changes during the simulation does not require initialisation; simply include it in a :code:`math` block so it can be evaluated.
        

    The following example shows a model for counting games like hide and seek, where the first section shows an older format and the second section shows a better practice for CellML 2.0 models.


    .. code-block:: xml

      <!-- Childhood games involving counting down. -->
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

        <!-- Creating a generic component to hold global variables like time. -->
        <component name="parameters">
          <variable name="time" units="second" initial_value="0" />
        </component>

        <!-- Encapsulating the games into the hiding_games component. -->
        <encapsulation>
          <component_ref component="hiding_games">
            <component_ref component="hide_and_seek"/>
            <component_ref component="sardines"/>
          </component_ref>
        </encapsulation>

        <!-- Connect the time variable into the other components. -->
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

          <!-- Remove the initial_values from encapsulated component, move to the "parameters" component. -->
          <variable name="countdown_start" units="second" />
          <variable name="counter" units="second" />
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

        <!-- Define (or import) a top-level component used for setting all parameters, constants, and initial values. -->
        <component name="parameters">
          <variable name="time" units="second" />

          <!-- Move the initialisation of the countdown initial value into this top-level component. -->
          <variable name="hide_and_seek_start" initial_value="100" />
        </component>

        <!-- Add a new transfer variable throughout the encapsulation hierarchy. -->
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

        <!-- Connect the initialisation variable thoughout the encapsulation hierarchy. -->
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
