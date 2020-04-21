.. _informC11_interpretation_of_variable_resets1:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding reset variables and test variables

    Consider the following model which simulates an old-fashioned automatic gearbox in a car, which changes gears in order to reduce the engine speed, but maintain the road speed.
    In this example we will consider that the road speed is an input, and the selection of a gear ratio is an output.

    .. code::

      model: LearningToDrive
        └─ component: Car
            ├─ variable: road_speed (kph)
            ├─ component: Engine
            │   └─ variable: revs (hertz)
            └─ component: Gearbox
                └─ variable: ratio (dimensionless)


    .. container:: toggle

      .. container:: header

        See CellML syntax

      .. code-block:: xml

        <model name="LearningToDrive">
          <!-- Defining the individual components and their variables. -->
          <component = "Car">
            <variable name="road_speed" units="kph" />
          </component>
          <component name="Gearbox">
            <variable name="ratio" units="dimensionless" />
          </component>
          <component name="Engine">
            <variable name="revs" units="hertz"/>
          </component>

          <!-- Defining the custom units required above. -->
          <units name="kph">
            <!-- kilometres: -->
            <unit units="metre" prefix="kilo" />
            <!-- per hour: -->
            <unit units="second" exponent="-1" multiplier="3600" />
          </units>

          <!-- Encapsulating the Gearbox and Engine components inside the Car component. -->
          <encapsulation>
            <component_ref component="Car">
              <component_ref component="Gearbox" />
              <component_ref component="Engine" />
            </component_ref>
          </encapsulation>
        </model>

    Of course, the operation of the engine and the gearbox together define the overall operation of the car, so they'll need to exchange information between them.
    This is done by creating equivalent variables between the components.

    **Note:** in the CellML model there is no directionality to the variable equivalences; they are part of a set.
    The arrows on the diagrams here are only to explain where information is calculated (the tail of the arrow) and where information is used (the heads of the arrows).

    .. code::

      model: LearningToDrive
        └─ component: Car
            ├─ variable: speed (kph) ╴╴╴╴╴╴ A ╴╴╴╴╴┐
            │                                      ╷
            │                            equivalent variables
            ├─ component: Engine                   ╵
            │   ├─ variable: road_speed (kph) <╴╴╴╴┘
            │   └─ variable: gear_ratio (dimensionless) <╴╴╴ B ╴╴╴╴┐ 
            │                                                      ╷
            │                                            equivalent variables
            └─ component: Gearbox                                  ╵ 
                ├─ variable: engine_revs (hertz)                   ╵
                └─ variable: ratio (dimensionless) ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘ 

    .. container:: toggle

      .. container:: header

        See CellML syntax

      .. code-block:: xml

        <!-- The following equivalences are added to the model above. -->

        <!-- Equivalence A: -->
        <connection component_1="Car" component_2="Engine" >
          <map_variables variable_1="speed" variable_2="road_speed" />
        </connection>

        <!-- Equivalence B: -->
        <connection component_1="Gearbox" component_2="Engine" >
          <map_variables variable_1="ratio" variable_2="gear_ratio" />
        </connection>


    The speed of the car is controlled.
    This is sent to the engine component through the equivalence A above between the :code:`speed` and :code:`road_speed` variables.
    The engine calculates its own turnover speed in the :code:`revs` variable based on the required road speed and the current gear ratio in the gearbox, accessed through equivalence B between the :code:`gear_ratio` and :code:`ratio` variables.
    If the engine revs are too high, the gearbox must change the gear ratio: thus a reset is needed.
    
    .. code::

      model: LearningToDrive
        └─ component: Car
            ├─ variable: speed (kph) ╴╴╴╴╴╴ A ╴╴╴╴╴┐
            │                                      ╷
            │                            equivalent variables
            ├─ component: Engine                   ╵
            │   ├─ variable: road_speed (kph) <╴╴╴╴┘
            │   ├─ variable: gear_ratio (dimensionless) <╴╴╴ B ╴╴╴╴┐ 
            │   └─ variable: revs (hertz)  ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴ C ╴┐  ╷
            │                                                   ╷  ╷
            │                                      equivalent variables
            └─ component: Gearbox                               ╵  ╵ 
          ┌╴╴╴╴╴╴├─ variable: engine_revs (hertz) <╴╴╴╴╴╴╴╴╴╴╴╴╴┘  ╵
          ╷      └─ variable: ratio (dimensionless) ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┘ 
          ╷          │
          ╷          └─ reset: 
          └╴╴╴╴╴╴╴╴╴╴╴╴╴>├─ "when engine_revs are over 3600rpm"
                         └─ "then reduce the gear ratio by 30%"

    There are two key aspects to a :code:`reset` item:

    - When should a change happen? In this case, when :math:`revs_{engine} \geq 60 [Hertz]`.
    - What should that change be? In this case, :math:`ratio_{new} = 0.7 \times ratio_{current}`.

    A third equivalence C is needed now, so that the reset in the :code:`Gearbox` component can have the information it needs (that is, the :code:`revs` of the :code:`Engine`) in order to decide when to change gears.  

    In CellML syntax the ideas in the "when" and "then" statements in the diagram above are captured between four items:

    - the "when" by the :code:`test_variable` nominating the variable to evaluate for testing;
    - the :code:`test_value` to specify the threshold point for that variable;
    - the "then" by the :code:`variable` attribute nominating the variable which will be altered by the reset; and
    - the :code:`reset_value` to specify the new value for the reset variable.
    
    Thus our model becomes:

    .. code::

      model: LearningToDrive
        └─ component: Car
            ├─ variable: speed (kph)
            ├─ component: Engine
            │   ├─ variable: road_speed (kph) 
            │   ├─ variable: gear_ratio (dimensionless) 
            │   └─ variable: revs (hertz)
            └─ component: Gearbox 
                ├─ variable: engine_revs (hertz) ╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴┐
                └─ variable: ratio (dimensionless)                     ╷
                    ╵ └─ reset:                                        ╷ 
                    ╵     ├─ "when the engine revs are over 60 Hertz"  ╷
                    ╵     │    ├─ test_variable: engine_revs <╴╴╴╴╴╴╴╴╴┘
                    ╵     │    └─ test_value: greater than 60 Hertz
                    ╵     │              
                    ╵     └─ "then reduce the gear ratio by 30%"
                    └╴<╴╴╴╴╴╴╴╴├─ variable: ratio
                               └─ reset_value: 0.7*ratio

    .. container:: toggle

      .. container:: header

        Show CellML syntax
      
      .. code-block:: xml

        <!-- Add a reset to the Gearbox component: -->

        <reset variable="ratio" test_variable="engine_revs" >

          <!-- The left hand side of the test_value equation is given 
               by the test_variable attribute above. -->
          <test_value>
            <math>
              <cn cellml:units="hertz">60<cn>
            </math>
          </test_value>

          <!-- The left hand side of the reset_value equation is given by
               the variable attribute above. -->
          <reset_value>
            <math>
              <apply></times>
                <cn cellml:units="dimensionless">0.7</cn>
                <ci>ratio</ci>
              </apply>
            </math>
          </reset_value>

        </reset>

      At this stage we'd expect the behaviour of the gear box to have a step-change in the :code:`ratio` value as the gear change occcured.
      We'd also expect a similar step-change in the :code:`revs` variable in the engine too, as the overall road speed is maintained.
      The difference with the :code:`revs` (and equivalent :code:`engine_revs`) variables is that since these are dependent on the gear ratio, their value will update based on that; they do not need their own reset to create this behaviour.

      To this point we have used only one reset.
      The next block will look at how more multiple resets can affect a single variable, and introduce concept of a reset order.



      **OR**
   
    .. container:: heading3

        An example: Cleaning the house
      
    In the following example we want to model the position of an automatic vacuum cleaner as it deflects off two opposite walls in a room.
    The device follows a straight line until it encounters a wall, at which point it immediately switches direction and travels back to the other wall.
    We will use resets to model the interaction of the device with the wall, but before they're added, we'll start with a very simplistic model which describes the position of the device changing with time:

    .. code::

      model: CleaningTheHouse
        └─ component: Roomba
            ├─ variable: position (metre), initially 0
            ├─ variable: step (metre)
            ├─ variable: width (metre), constant, 5
            ├─ variable: direction (dimensionless), initially 1
            └─ math: 
                └─ position = position + direction*step
    
    .. container:: toggle

      .. container:: header

        See CellML syntax

      .. code-block:: xml

        <model name="NotCleaningTheHouse">

          <component name="Roomba">
            <!-- Variables should be initialised using the initial_value attribute. -->
            <variable name="position" units="metre" initial_value="0" />
            <variable name="direction" units="dimensionless" initial_value="1" />

            <!-- Constants should be set in the math element so that they are true for all time. -->
            <variable name="step" units="metre"/>
            <variable name="width" units="metre" />

            <math>
              <!-- Constant: the room is 5m wide. -->
              <apply><eq/>
                <ci>width</ci>
                <cn cellml:units="metre">5</cn>
              </apply>

              <!-- Constant: the step update will be 0.1m. -->
              <apply><eq/>
                <ci>step</ci>
                <cn cellml:units="metre">0.1</cn>
              </apply>
              
              <!-- Variable: the position of the device will increment based on its direction and previous positon. -->
              <apply><eq/>
                <ci>position</ci>
                <apply><plus/>
                  <ci>position</ci>
                  <apply><times/>
                    <ci>step</ci>
                    <ci>direction</ci>
                  </apply>
                </apply>
              </apply>

            </math>
          </component>
        </model>

    Now let's add a reset to this such that when the device reaches the opposite wall, its direction of travel is reversed.

    .. code::

      model: CleaningTheHouse
        └─ component: Roomba
            ├─ variable: position 
            ├─ variable: step
            ├─ variable: width 
            │
            ├─ variable: direction
            │    └─reset:
            │      ├─ "when position equals width"
            │      └─ "then reverse direction"
            │
            └─ math: 
                └─ position = position + direction*step

    .. code-block:: xml

      <reset variable="direction" test_variable="position" order="1">

        <!-- The "when" statement above is true when the test_variable 
             attribute equals the test_value statement: -->
        <test_value>
          <ci>width</ci>
        </test_value>

        <!-- The "then" statement above is defined by setting the
              variable attribute to the reset_value statement: -->
        <reset_value>
          <apply><times/>
            <ci>direction</ci>
            <cn cellml:units="dimensionless">-1</cn>
          <apply>
        </reset_value>
      </reset>
    
    The behavior at the other end of the wall is discussed in the following section.

    

