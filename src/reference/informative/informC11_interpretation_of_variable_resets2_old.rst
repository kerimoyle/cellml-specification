.. _informC11_interpretation_of_variable_resets2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding the reset order

    CellML is designed to represent complicated model behaviour, and this includes the idea that a single variable might need to be reset based different kinds of behaviour; or, that more than one reset is permitted per variable.

    Continuing the example from the previous block, we'll now add the behaviour of the automatic vacuum cleaner when it reaches its starting position at the first side of the room.

    .. code::

      model: CleaningTheHouse
        └─ component: Roomba
            ├─ variable: position 
            ├─ variable: step
            ├─ variable: width 
            │
            ├─ variable: direction
            │    ├─ reset A: order = 1
            │    │   ├─ "when position equals width"
            │    │   └─ "then reverse direction"
            │    └─ reset B: order = 2
            │        ├─ "when position equals start"
            │        └─ "then reverse direction"
            │
            └─ math: 
                └─ position = position + direction*step
    
    At present it's clear from the conditions on the two resets (the position at the start and at the far wall) that they cannot occur simulataneously, but this is not always the case.
    For this reason, every reset must specify an :code:`order` attribute which will be used as a tie-breaker in situations where more than one reset on a variable is active.

    It's also worth noting that because of the variable equivalence functionality, when we talk about "per variable" here, we're really including *all* resets which directly (as above, through the same :code:`variable` attribute) or indirectly (where another variable in the same equivalent variable set is referenced) change a variable's value.

    To illustrate the idea of the equivalent variables and order, we'll add a new component which represents the battery charge on the device.
    When the battery is empty, the direction will be set to 0 and the machine will stop moving.






  