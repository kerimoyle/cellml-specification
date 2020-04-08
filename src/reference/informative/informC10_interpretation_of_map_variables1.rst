.. _informC10_interpretation_of_map_variables1:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding the terminology
    
    The idea of component modularity and separateness is helpful in organising models and reusing parts of them, but only if it's also possible to share information between the distinct components.
    This is the goal of "variable equivalence", and requires the combined mechanisms of :code:`connection` elements (to connect components) and :code:`map_variables` elements (to connect their variables).
    Several different words have been used to describe what is essentially this one process: equivalent variables, the connected variable set, mapped variables, etc.
    All of these mean the same thing: that the variables in the set act as a single agent throughout the model.
    They may have different local names within a component, but they will have the same value everywhere they exist.

    Thus there are two ways in which variables are related to one another.  
    The first is through the mathematical equations as specified in intra-component :code:`math` elements; the second is through variable equivalences as specified in inter-component :code:`connection` and :code:`map_variables` elements.

    Both the :code:`connection` and :code:`map_variables` elements are *undirected*.
    There is no update direction or hierarchy; they all have, instantaneously, the same value.
    
