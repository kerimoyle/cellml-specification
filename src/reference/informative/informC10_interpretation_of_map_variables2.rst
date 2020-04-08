.. _informC10_interpretation_of_map_variables2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding the players
    
    You can think of the previous two points as defining an address using a street name and number.
    Since streets (components) have lots of houses (variables) they all need different numbers (variable names) in that street.
    And since lots of streets (components) have houses (variables) with the same number (name), we need both the street name and the house number in order to locate a house properly.
    This is the purpose of the :code:`component_1` and :code:`component_2` attributes of :code:`connection` elements (to define the respective street (component) names), and the :code:`variable_1` and :code:`variable_2` attributes of each :code:`connection` element's :code:`map_variables` element (to define the respective house number (variable name)).

    Thus the "equivalent variable network" is a collection of unique variables (each specified a component and a variable name), which will be treated as the same variable throughout the model.

    Note that we use the term "network" here as it best describes the *process* by which variable equivalence is constructed, even if its final *interpretation* is not a network, but rather a set.
    
