.. _informC10_interpretation_of_map_variables3:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding the rules
    
    As well as the syntax definitions above, there are rules regarding which variables are able to be connected to one another too.

    Both points :hardcodedref:`3.10.4 and 3.10.5` address a similar issue: that the "network" of variable equivalence must not contain any cycles (a connection such that A-B-A is just a mini cycle after all).
    
    In the model below there are three sets of variables which have equivalent values, and it is the modeller's desire that they be able to use them interchangably in each language whilst maintaining their value throughout.
    There are two situations which would render the model invalid if these variables were mapped incorrectly, as shown below.

    .. code::

      model: LearningToCount
        ├─ component: Dutch
        │   ├─ variable: een
        │   ├─ variable: twee
        │   ├─ variable: drie
        │   └─ variable: vier
        ├─ component: Maori
        │   ├─ variable: tahi
        │   ├─ variable: rua
        │   ├─ variable: toru
        │   └─ variable: wha
        └─ component: French
            ├─ variable: un
            ├─ variable: deux
            ├─ variable: trois
            └─ variable: quatre

    .. container:: toggle

      .. container:: header

        See CellML syntax
      
      .. code-block:: xml

        <model name="LearningToCount">
          <component name="Dutch">
            <variable name="een" />
            <variable name="twee" />
            <variable name="drie" />
            <variable name="vier" />
          </component>
          <component name="Maori">
            <variable name="tahi" />
            <variable name="rua" />
            <variable name="toru" />
            <variable name="wha" />
          </component>
          <component name="French">
            <variable name="un" />
            <variable name="deux" />
            <variable name="trois" />
            <variable name="quatre" />
          </component>
        </model>

    1. Firstly, duplicated connections are not permitted because they create a mini-cycle of two variables.
       If an Anglophone is given a definition of *een* to mean *tahi*, and *tahi* to mean *een*, they are none the wiser.  

    .. code::

      model: LearningToCount
        ├─ component: Dutch
        │   ├─ variable: een <╴╴╴┬╴╴╴┐
        │   ├─ variable: twee    ╷   ╷
        │   ├─ variable: drie   duplicate mapping
        │   └─ variable: vier   causes a mini-cycle
        ├─ component: Maori      ╵   ╵
        │   ├─ variable: tahi <╴╴┴╴╴╴┘
        │   ├─ variable: rua
        │   ├─ variable: toru
        │   └─ variable: wha
        └─ component: French
            ├─ variable: un
            ├─ variable: deux
            ├─ variable: trois
            └─ variable: quatre

    .. container:: toggle

      .. container:: header

        See CellML syntax

      .. code-block:: xml

        <!-- Valid: First define the two components using a connection ... -->
        <connection component_1="Dutch" component_2="Maori">
          <!-- ... and then define the mapping between two variables within
              those two components. -->
          <map_variables variable_1="een" variable_2="tahi" />
            ...
        </connection>

        <!-- Invalid: Duplicated mappings are not allowed. -->
        <connection component_1="Dutch" component_2="Maori">
          <map_variables variable_1="een" variable_2="tahi" />
          <map_variables variable_1="een" variable_2="tahi" />
           ...
        </connection>

        <!-- Invalid: Duplicated connections are not allowed. -->
        <connection component_1="Dutch" component_2="Maori">
          <map_variables variable_1="een" variable_2="tahi" />
            ...
        </connection>
        <connection component_1="Maori" component_2="Dutch">
          <map_variables variable_1="tahi" variable_2="een" />
            ...
        </connection>

    2. Secondly, *any* form of cyclical definition is invalid, as it leaves the mathematical model underdefined.
       So our Anglophone could be also told that *drie* means *trois*, *trois* means *toru*, and *toru* means *drie*, but unless one of them is nailed down to an actual value somewhere, the model remains under-defined.

    .. code::

      model: LearningToCount
        ├─ component: Dutch
        │   ├─ variable: een <╴╴╴╴┐<╴╴╴╴╴╴╴╴┐
        │   ├─ variable: twee     ╷         ╷
        │   ├─ variable: drie    cycle created
        │   └─ variable: vier     ╷         ╷
        ├─ component: Maori       ╷         ╷
        │   ├─ variable: tahi <╴╴╴┘<╴╴╴┐    ╷
        │   ├─ variable: rua           ╷    ╷ 
        │   ├─ variable: toru          ╷    ╷
        │   └─ variable: wha           ╷    ╷
        └─ component: French           ╷    ╷
            ├─ variable: un <╴╴╴╴╴╴╴╴╴╴┘<╴╴╴┘
            ├─ variable: deux
            ├─ variable: trois
            └─ variable: quatre

    .. container:: toggle

      .. container:: header

        See CellML syntax

      .. code-block:: xml

        <!-- Invalid: a cycle is created. -->
        <connection component_1="Dutch" component_2="Maori">
          <map_variables variable_1="een" variable_2="tahi" />
            ...
        </connection>
        <connection component_1="Maori" component_2="French">
          <map_variables variable_1="tahi" variable_2="un" />
            ...
        </connection>
        <connection component_1="French" component_2="Dutch">
          <map_variables variable_1="un" variable_2="een" />
            ...
        </connection>
