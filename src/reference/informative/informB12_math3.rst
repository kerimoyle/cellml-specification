.. _informB12_3:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    Consider the same :math:`E=mc^2` formula as earlier, but now the value of mass :code:`m` is calculated in another component:

    .. code-block:: xml

      <component name="mass_into_energy">

        <!-- The local variables for energy E and speed of light c are listed here ... -->
        <variable name="E" units="joule"/>
        <variable name="c" units="metres_per_second"/>
        <!-- ... but the variable for mass calculated in another component. -->

        <math>
          <apply><eq/>
            <ci>E</ci>
            <apply><times/>
              <ci>m</ci>
              <apply><power/>
                <ci>c</ci>
                <cn cellml:units="dimensionless">2</cn>
              </apply>
            </apply>
          </apply>
        </math>
      </component>
      <component name="calculate_mass">
        <variable name="m" units="kilograms" initial_value="54" />
      </component>

    This situation is not valid, as the :code:`math` block in component :code:`mass_into_energy` doesn't have access to the variable :code:`m` in the component :code:`calculate_mass`.
    To get around this, you would need to create a new local variable within the :code:`mass_into_energy` component, and use a :code:`connection` element to link it to the mass variable :code:`m` in the other component.
    The valid form of the model is shown below. You can read more about :code:`connections` in :numref:`{number} {name}<specB_connection>`, and the :code:`interface_type` attribute in :numref:`{number} {name}<specB_variable>`.

    .. code-block:: xml

      <component name="mass_into_energy">
        <variable name="E" units="joule"/>
        <variable name="c" units="metres_per_second"/>
        <!-- A new local variable named m is created here with a public interface type. -->
        <variable name="m" units="kilograms" interface_type="public"/>
        <math>
          <apply><eq/>
            <ci>E</ci>
            <apply><times/>
              <ci>m</ci>
              <apply><power/>
                <ci>c</ci>
                <cn cellml:units="dimensionless">2</cn>
              </apply>
            </apply>
          </apply>
        </math>
      </component>
      <component name="calculate_mass">
        <variable name="mass" units="kilograms" initial_value="54" />
      </component>
      <!-- A connection element is created which links components "calculate_mass" and "mass_into_energy". -->
      <connection component_1="mass_into_energy" component_2="calculate_mass">
        <!-- A map_variable pair is created which links the "m" variables in each of the connected components. -->
        <map_variables variable_1="m" variable_2="m" />
      </connection>
