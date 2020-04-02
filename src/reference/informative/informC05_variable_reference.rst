.. _informC05_variable_reference:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding variable references

    A :code:`variable` item only exists within its parent :code:`component` item, but can be connected to others via the :code:`map_variables` functionality.
    There are two different ways that any :code:`variable` could be referenced.

    The first and simplest is within its own local scope, the parent :code:`component`.
    In that situation, the :code:`variable`\'s :code:`name` attribute is enough to uniquely locate it.

    The second situation is when a :code:`variable` is referred to from a :code:`component` other than its parent, so a reference to the parent :code:`component` as well as the :code:`variable`'s :code:`name` is required.
    This is found when creating :code:`connection` items using :code:`map_variables`.

    The example below shows how the pairing of components and variables are required to form a valid connection.  


    .. code-block:: xml

        <model name="FamousFreds">

          <component name="Flintstone">
            <variable name="Fred" units="dimensionless" />
            <variable name="Wilma" units="dimensionless" />
          </component>

          <component name="Astair">
            <variable name="Fred" units="dimensionless" />
          </component>

          <component name="CartoonCharacters">
            <variable name="FredFlintstone" units="dimensionless" />
            <variable name="DaffyDuck" units="dimensionless" />
          </component>

          <component name="Dancers">
            <variable name="FredAstaire" units="dimensionless" />
            <variable name="GingerRogers" units="dimensionless" />
          </component>

          <!-- Correct: connecting the variable "Fred" in component "Flintstone" into the
               variable "FredFlintsone" in the "CartoonCharacters" component. -->
          <connection component_1="Flintstone" component_2="CartoonCharacters" >
            <map_variables variable_1="Fred" variable_2="FredFlintstone" />
          </connection>

          <!-- Incorrect: trying to connect variable "Fred" from component "Dancers" into the
               variable "FredAstaire" from component "Astair": variable_1 must exist within
               component_1, and variable_2 must exist within component_2. -->
          <connection component_1="Dancers" component_2="Astaire">
            <map_variables variable_1="Fred" variable_2="FredAstaire" />
          </connection>
        </model>
