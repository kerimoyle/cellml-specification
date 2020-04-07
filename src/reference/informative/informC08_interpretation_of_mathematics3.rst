.. _informC08_interpretation_of_mathematics3:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding how the units work

    We know that units in real life make a big difference, but in the CellML specification universe, they don't. 
    Each :code:`variable` element has to specify a corresponding :code:`units` element, but this combination doesn't affect the validity of the :code:`math` element.
    It does, however, make a difference to how your model needs to be interpreted.
    Some examples are shown below.

    Constants and variables in an equation have different units: this is not invalid CellML, but doesn't make any mathematical sense.

    .. code-block:: xml

      <variable name="lunch" units="omelette" />
      ...
      <apply><eq/>
        <ci>lunch</ci>
        <apply><plus/>
          <cn cellml:units="egg">2</cn>
          <cn cellml:units="cheese">5</cn>
          <cn cellml:units="milk">0.1</cn>
        </apply>
      </apply>

    Exponents have units other than :code:`dimensionless`: again, not invalid CellML, but mathematical nonsense.

    .. code-block:: xml

      <variable name="E" units="joule" />
      <variable name="m" units="kilogram" />
      <variable name="c" units="metres_per_second" />
      ...
      <apply><eq/>
        <ci>E</ci>
        <apply><times/>
          <ci>m</ci>
          <apply></power>
            <ci>c</ci>
            <cn cellml:units="anything_not_dimensionless">2</cn>
          </apply>
        </apply>
      </apply>

    The only situation in which :code:`units` items are compared to one another is between equivalent variables, i.e.: the :code:`variable_1` and :code:`variable_2` attributes of a :code:`map_variables` element.
    Here, both of the :code:`variable` elements referenced must have the same :ref:`unit reduction<_informC03_interpretation_of_units_3_2>`, though not necessarily the same multiplication factor.
    Some examples of these are shown below.
    
    Any custom or built-in units with differing scaling factors between connected variables: valid, as the unit reduction is the same, but the resulting mathematics will need to be interpreted carefully!

    .. code::

      model: DCUniverse
        ├─ component: Metropolis
        │   └─ variable: Superman (units = megapowers) <╴╴┐
        │                                                 ╷
        │                                       connected variables
        ├─ component: Smallville                          ╵
        │   └─ variable: ClarkKent (units = micropowers) ╴┘
        │
        └─ units: powers
            ├─ units: micropowers = 0.000001*powers
            └─ units: megapowers = 1,000,000*powers


    .. toggle::

      .. header::

        See CellML syntax

      .. code-block:: xml

        <model name="DCUniverse">
          <!-- Defining a custom base unit called "powers". -->
          <units name="powers" />
          <!-- Creating the derived custom units with different prefixes, 
               mega and micro. -->
          <units name="megapowers >
            <unit units="powers" prefix="mega" />
          </units>
          <units name="micropowers">
            <unit units="powers" prefix="micro" />
          </units>
          <!-- The variable "Superman" in component "Metropolis" 
               has units of "megapowers". -->
          <component name="Metropolis">
            <variable name="Superman" units="megapowers" />
          </component>
          <!-- The variable "ClarkKent" in component "Smallville" 
               has units of "micropowers". -->
          <component name="Smallville">
            <variable name="ClarkKent" units="micropowers" />
          </component>
          <!-- The connection is valid, because the unit reduction is the same,
               even though the multiplication factor between the two variables
               is different. -->
          <connection component_1="Metropolis" component_2="Smallville">
            <map_variables variable_1="Superman" variable_2="ClarkKent" />
          </connection>
        </model>

    Any custom of built-in units with *differing* unit reduction tuples between connected variables: invalid, as it contradicts point :hardcodedref:`3.10.6` in the :ref:`Interpretation of map_variables<specC_interpretation_of_map_variables>` section.  
    Please see the third informative block on the :ref:`Interpretation of units<specC_interpretation_of_units>` section for more discussion and examples of unit reductions.

    .. code::

      model: DCUniverse
        ├─ component: FarFromKryptonite
        │   └─ variable: Superman (units = megapowers) <╴╴╴╴┐
        │                                                   ╷
        │                                      connection is now invalid
        ├─ component: NearToKryptonite                      ╵
        │   └─ variable: ClarkKent (units = marshmallow) ╴╴╴┘
        │
        ├─ units: powers
        │   └─ units: megapowers = 1,000,000*powers
        │
        └─ units: marshmallow

    .. toggle::

      .. header::

        See CellML syntax

      .. code-block:: xml

        <model name="DCUniverse">
          <units name="powers" />
          <units name="megapowers >
            <unit units="powers" prefix="mega" />
          </units>
          <!-- Creating a new base unit called "marshmallow".-->
          <units name="marshmallow" />

          <!-- The variable "Superman" in component "FarFromKryptonite" 
               has units of "megapowers". -->
          <component name="FarFromKryptonite">
            <variable name="Superman" units="megapowers" />
          </component>

          <!-- The variable "ClarkKent" in component "NearToKryptonite" 
               has units of "marshmallow". -->
          <component name="NearToKryptonite">
            <variable name="ClarkKent" units="marshmallow" />
          </component>

          <!-- The connection is invalid, because the unit reduction not the same. -->
          <connection component_1="FarFromKryptonite" component_2="NearToKryptonite">
            <map_variables variable_1="Superman" variable_2="ClarkKent" />
          </connection>
        </model>



