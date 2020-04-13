.. _informC10_interpretation_of_map_variables6:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding mathematics

    In :calvin_and_hobbes:`an episode of Bill Watterson's comic, Calvin and Hobbes <1990/01/09>`, Calvin builds a duplicator machine and clones himself several times so that the clones can do his chores in different rooms of the house.
    This is essentially the purpose of creating :code:`map_variables` elements: to enable the "clones" (the mapped variables) to be used in separate "rooms" (components) whilst really representing the same thing.
    The first sentence in :hardcodedref:`3.10.11` explains this: Each :code:`variable` element in a CellML model SHALL be treated as belonging to a single "connected variable set"; or, while there are many "connected variable sets" in a model, any one :code:`variable` may belong to only one of them.

    In a *CellML model* there are two mechanisms by which variables can relate to one another: through the mathematics in the :code:`math` elements, and through the mapping in the :code:`map_variables` elements.
    In a mathematical model, there is only one mechanism: the maths itself.
    There are no clones, no duplicates, no mappings. 

    Thus, the purely mathematical model is found by collapsing each set of mapped variables (cloned characters) onto a single unique variable (character), until the relationships between these unique variables no longer involve mapping (cloning) but only mathematics.
    In the end, :calvin_and_hobbes:`Calvin does the same <1990/01/30>`, and the world returns to (roughly) normal.
