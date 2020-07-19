.. _informB9_3:
.. _inform_reset3:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    The :code:`order` attribute of a :code:`reset` element must be specified, and is used when there is more than one reset with the ability to change a variable.

    We'll continue the example above which represents the mythological story of Sisyphus rolling a boulder up a mountain, but tweak it a little.  
    The ruler of Tartarus has decided that Sisyphus should have a day off on Tuesdays, so once a week the boulder doesn't roll down the mountain until the following midnight.
    Adding a second :code:`reset` to the model gives us the arrangement shown below.

    .. code::

      model: Tartarus
        └─ component: Sisyphus
            ├─ math: ode(position, time) = 1
            ├─ variable: time
            └─ variable: position, initially 0
                ├─ reset: A
                │   ├─ when: time is midnight
                │   ├─ then: position is bottom of hill
                │   └─ order: 2
                │
                └─ reset: B
                    ├─ when: time is Tuesday midnight
                    ├─ then: position is unchanged at top of hill
                    └─ order: 1

    As it stands, at midnight on a Tuesday *both* of the resets above are active: the first, reset A, because midnight on any day meets the midnight criterion; the second because midnight on Tuesday also meets the criterion for B.
    To decide which of the two consequences to enact - to roll the stone or not - we need to consider the :code:`order` attribute, the interpretation of which is discussed in detail in :numref:`{number} {name}<specC_interpretation_of_resets>`.
    The valid CellML syntax for this situation is shown below, with some examples of invalid syntax too. 
 
    .. container:: toggle

      .. container:: header

        Show CellML syntax

      .. code-block:: xml

        <!-- This is valid: the order attribute of both resets is present, 
            unique, and an integer. -->
        <model name="Tartarus">
          <component name="Sisyphus">
            <variable name="time" units="second" />
            <variable name="position" units="dimensionless" />

            <!-- The first reset represents all midnight times. -->
            <reset variable="position" test_variable="time" order="2">
              ...
            </reset>
            <!-- The second reset represents midnight on Tuesdays only. -->
            <reset variable="position" test_variable="time" order="1">
              ...
            </reset>
          </component>
        </model>

      .. code-block:: xml

        <!-- These are not valid: -->
        <model name="Tartarus">
          <component name="Sisyphus">
            <variable name="time" units="second" />
            <variable name="position" units="dimensionless" initial_value="0" />

            <!-- Invalid: missing order attribute. -->
            <reset variable="position" test_variable="time" >
              ...
            </reset>

            <!-- Invalid: order must be an integer. -->
            <reset variable="position" test_variable="time" order="first" >
              ...
            </reset>
            <reset variable="position" test_variable="time" order="1.0" >
              ...
            </reset>

          </component>
        </model>

    Finally we'll look at the condition for uniqueness of a variable's resets' orders.
    Note that this is applied within the component itself across all the resets which could apply to a given variable, as well as across the set of equivalent variables too.
    Let's create a second component to represent the whim of Zeus, ruler of the gods, who can intervene at any time to send the stone rolling down the mountain.

    .. code::

      model: Tartarus
        ├─ component: Zeus
        │   └─ variable: sisyphus_position <╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┐
        │       └─ reset: C                                       ╷
        │           ├─ when: Sisyphus reaches some position       ╷
        │           ├─ then: sisyphus_position is bottom of hill  ╷
        │           └─ order: -1                                  ╷
        │                                                    equivalent
        └─ component: Sisyphus                               variables
            ├─ math: ode(position, time) = 1                      ╵
            ├─ variable: time                                     ╵
            └─ variable: position <╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘
                ├─ reset: A
                │   ├─ when: time is midnight
                │   ├─ then: position is bottom of hill
                │   └─ order: 2
                │
                └─ reset: B
                    ├─ when: time is Tuesday midnight
                    ├─ then: position is unchanged at top of hill
                    └─ order: 1

    .. container:: toggle

      .. container:: header

        Show CellML syntax

      .. code-block:: xml

        <model name="Tartarus">
          <!-- Including a new component with a connected variable, sisyphus_position: -->
          <component name="Zeus" >
            <variable name="sisyphus_position" units="metre" initial_value="0" interface="public"/>
            <!-- Creating a reset that will send the boulder to the bottom of the mountain 
                 when it reaches a certain point: -->
            <reset variable="sisyphus_position" test_variable="sisyphus_position" order="-1">
              ...
            </reset>
          </component>

          <component name="Sisyphus">
            <variable name="time" units="second" />
            <variable name="position" units="dimensionless" interface="public" />

            <!-- The first reset represents all midnight times. -->
            <reset variable="position" test_variable="time" order="2">
              ...
            </reset>
            <!-- The second reset represents midnight on Tuesdays only. -->
            <reset variable="position" test_variable="time" order="1">
              ...
            </reset>
            ...
          </component>

          <!-- Connecting the variable "position" in component "Sisyphus" with the variable
               "sisyphus_position" in component "Zeus": -->
          <connection component_1="Zeus" component_2="Sisyphus" >
            <map_variables variable_1="sisyphus_position" variable_2="position" />
          </connection>
        </model>






    This arrangement is valid, because none of the :code:`order` attributes on resets within the same equivalent variable set have duplicated values: reset A has order 2, reset B has order 1, and reset C has order -1.
    Note also that order values may be negative, as shown here.

    .. container:: heading3

      Gotcha: an "equivalent variable set" without any equivalent variables?

    The equivalent variable set rule here refers to any reset which references the same variable.
    This is possible in two ways - either by directly referencing it (as in resets A and B above) or through the equivalence network (as in reset C).  
    Thus, even in situations where there are no equivalent variables defined in the model (which is the case before Zeus stepped in) there is still the need for order uniqueness between resets of the same variable (as in between A and B).