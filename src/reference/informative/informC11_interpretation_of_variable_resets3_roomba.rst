.. _informC11_interpretation_of_variable_resets3:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding the test value element

    In the previous block we introduced a model which showed how both a low battery and an encounter with a wall could affect the velocity of the Roomba, and used the :code:`order` attribute to determine which reset was followed.
    Now we'd like to make sure that the low-battery Roomba is only ever stopped at a wall, so that people don't trip up on it.

    Conditional statements are legal inside both the :code:`test_value` block and :code:`reset_value` blocks, so we can write this as:

    .. code::

      model: CleaningTheHouse
        └─ component: Roomba
            ├─ variable: position 
            ├─ variable: width 
            ├─ variable: battery_level [charge], initially 100
            ├─ variable: charge_use_rage [charge_per_metre_per_second], constant
            │
            ├─ variable: velocity
            │    ├─ reset A1: order = 1
            │    │   ├─ "when IF position equals width AND battery level is more than 10"
            │    │   └─ "then reverse direction"
            │    ├─ reset A2: order = 2
            │    │   ├─ "when IF position equals width AND battery level is 10 or less"
            │    │   └─ "then stop"
            │    │
            │    └─ reset B: order = 2
            │        ├─ "when position equals start AND battery level is more than 10"
            │        └─ "then IF battery is more than 10 reverse direction ELSE stop"
            │
            └─ math: 
                ├─ ode(position, time) = velocity
                └─ ode(battery_level, time) = -abs(velocity)*charge_use_rate

                
  
    In this situation, reset A1 is only ever active when there is sufficient battery to change direction.
    This means that we've had to add a second reset A2 that tests for when the far wall is encountered and the battery is low.
    In contrast, similar behaviour is found in reset B using just one reset, where the conditional statement is in the reset value rather than the test value.
    Other combinations of conditional statements are outlined in the Examples chapter **TODO**.


    