.. container:: preamble

  A *variable* is a conceptual entity representing a mathematical variable.

  A variable is defined by a :code:`variable` element.

  A variable has a *name*, determined by the :code:`name` attribute of its :code:`variable` element.

  A variable has *units*, determined by the :code:`units` attribute of its :code:`variable` element.
  The value of the :code:`units` attribute of a :code:`variable` element must equal the name of a predefined unit, or a unit defined within the model.
  
  A variable has an *initial value*, determined by the :code:`initial_value` attribute of its :code:`variable`.

  A variable has an *interface*, determined by the :code:`interface` attribute of its :code:`variable` element.

  A variable can be part of an *equivalent variable network*, as defined in section PQR **TODO**.

  A variable can be used in equations, see section KLM **TODO**.

.. include:: ../sectionC_interpretation.inc
  :start-after: marker_interpretation_of_map_variables_start
  :end-before: marker_interpretation_of_map_variables_end

.. todo ../informative/informC10_interpretation_of_map_variables.rst
