.. _informC08_interpretation_of_mathematics2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding how the mathematics works

    The mathematics of a mathematical model is a collection of statements which are held to be true.
    The collection of statements in CellML are the set of top-level children of a :code:`math` elements inside pertinent model components.
    The example from the previous point is extended below.
     
    .. code-block:: xml

      <!-- In file: MyHouse.cellml -->
      <model name="BackyardCricket" >

        <!-- The local component Tom now has a score, measured by the variable "runs". 
             This score is constant for all of time.  Tom will never get his century! -->
        <component name="Tom">
          <variable name="runs" units="dimensionless" />
          <math>
            <apply><eq/>
              <ci>runs</ci>
              <cn>99</cn>
            </apply>
          </math>
        </component>

        <import href="Neighbours.cellml">
          <component component_ref="Harry" name="Harry" />
        </import>

        <!-- The total tally for the game is stored in the variable "total". -->
        <component name="FirstGame">
          <variable name="total" units="dimensionless" />
          <variable name="toms_runs" units=" dimensionless" />
          <variable name="harrys_runs" units=" dimensionless" />
          <variable name="dicks_runs" units=" dimensionless" />
          <math>
            <apply><eq/>
              <ci>total</ci>
              <apply><plus/>
                <ci>toms_runs</ci>
                <ci>harrys_runs</ci>
                <ci>dicks_runs</ci>
              </apply>
            </apply>
          </math>
        </component>

        <!-- Connections to report the runs from each player are established. -->
        <connection component_1="FirstGame" component_2="Tom" >
          <map_variables variable_1="toms_runs" variable_2="runs" />
        </connection>
        <!-- Since component "DickTheDog" is too distant in the encapsulation structure to be
             visible to the "FirstGame" component, any runs scored by the dog must be passed
             through Harry's component. -->
        <connection component_1="FirstGame" component_2="Harry" >
          <map_variables variable_1="harrys_runs" variable_2="runs" />
          <map_variables variable_1="dicks_runs" variable_2="dicks_runs" />
        </connection>

        <encapsulation>
          <component_ref component="FirstGame" >
            <component_ref component="Tom" />
            <component_ref component="Harry" />
          </component_ref>
        </encapsulation>
      </model>

      <!-- In file: Neighbours.cellml -->
      <model name="HarrysHouse" >

        <component name="DickTheDog">
          <variable name="runs" units="dimensionless" />
          <math>
            <!-- This statement sets Dick's score to 0 for all time.  He's a dog.  He can't use a cricket bat. -->
            <apply><eq/>
              <ci>runs</ci>
              <cn>0</cn>
            </apply>
          </math>
        </component>

        <component name="Harry">
          <variable name="time" units="minute" />
          <variable name="runs" units="dimensionless" />
          <math>
            <!-- This statement represents DickTheDog running away with the ball, 
                 enabling Harry to score an ever-increasing number of runs. -->
            <apply><eq/>
              <ci>runs</ci>
              <apply><times/>
                <cn cellml:units="per_minute">10</cn>
                <ci>time</ci>
            </apply>
          </math>
        </component>

        <!-- A connection is established between Harry and Dick to enable sharing of their run tally. -->
        <connection component_1="Harry" component_2="DickTheDog" >
          <map_variables variable_1="dicks_runs" variable_2="runs" />
        </connection>
        ...
      </model>

      .. container:: heading3

        Understanding how and when the mathematics *doesn't* work

      It's possible to write valid CellML that does not represent valid mathematics.
      You can think of this like correctly spelling a set of words which together do not form a meaningful sentence.
      Some examples of valid versus valid-but-nonsense :code:`math` elements' contents are shown below.

      Simple over-definition is valid, but not useful:

      .. math:

        x = 0

        x = 1

      Complex over-definition is likewise valid, but not useful:

      .. math:

        x + y = 1

        x - y = 3

        x * y = 12

      Redundant information is valid, but (well) redundant:

      .. math:

        x = 1

        x = 1

        x = 1

      Under-definition at a localised component level is both valid and useful, as you may need to connect to other components in order to know the value of the variables the maths statements are using.
      Models which *overall* have insufficient definition are also valid, but clearly won't be useful or solvable.

      .. math:

        x = y + z

      Unsolvable models and "bad" maths is valid CellML:

      .. math:

        x = 1 / 0

        x = \sqrt{-1}

      Conflicting information arising from initialising variables which are not state variables will have an outcome which depends on how the implementation software interprets the condition.  
      It is not invalid CellML, but may not result in the same interpretation between software implementations. 
      **TODO** check that this is right because it sounds dodgy!

      .. code:

        x = 1
        x has initial value 2
