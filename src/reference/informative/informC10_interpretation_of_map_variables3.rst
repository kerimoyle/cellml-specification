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
    There are three situations which would render the model invalid if these variables were mapped incorrectly.

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
            ├─ variable: tois
            └─ variable: quatre
    

    1. Firstly, duplicated connections are not permitted because they create a mini-cycle of two variables.
       If an Anglophone is given a definition of *een* to mean *tahi*, and *tahi* to mean *een*, they are none the wiser.

    2. Secondly, *any* form of cyclical definition is invalid, as it leaves the mathematical model underdefined.
       So our Anglophone could be also told that *drie* means *tois*, *tois* means *toru*, and *toru* means *drie*, but unless one of them is nailed down to an actual value somewhere, the model remains under-defined.
    






