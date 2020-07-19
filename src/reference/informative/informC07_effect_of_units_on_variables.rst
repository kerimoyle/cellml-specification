.. _informC07_effect_of_units_on_variables:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding variables and their units 
    
    The pairing of variables with units is distinct from every other relationship in CellML in that sometimes it matters, and sometimes it doesn't.
    To better understand why this is, we first have to understand the ideas of reusability and modularity that prompted the design of encapsulation.

    Each component in a CellML model is a package.
    That package may in turn contain other packages too, but each one is intended to represent an idea, a functionality, a black-boxed *thing* which can then be passed around and reused as needed.

    Now think about a component from the perspective of another modeller who wants to reuse your component in their  model:

    - When variables are passed *between* components (through equivalent variables) the units of those variables must be checked for consistency; the external modeller does not necessarily have knowledge of the inner workings of the black-box component, only the variables it passes to and fro across the boundaries.
      There are examples and further details available in :numref:`{number} {name}<specC_interpretation_of_map_variables>`.

    - When variables are created to operate *within* a component (its local mathematics) their units are not checked; the modeller *does* have knowledge of the inner workings, and can control and interpret them as needed.
      There are examples and further details available in :hardcodedref:`3.8.3` in :numref:`{number} {name}<specC_units_and_maths>`.

    Thus, CellML deems it important for the component border crossings to have as much information as possible (that is: the units and variable pairs), yet permits modellers the flexibility to make their own decisions about units within components.

