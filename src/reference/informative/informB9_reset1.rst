.. _informB9_1:
.. _inform_reset1:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      Understanding reset elements

    Resets are a new addition to CellML in version 2.0, and their intention is to allow the user to specify how and when discontinuities can exist in variable values throughout the solution.
    A reset lets you set a variable to a totally different value: restart a timer, flip a switch, take a step, start again.
    In order to work, a reset needs to know some information:

    - **Which variable's value do you want to change?**
      This is called the "reset variable" and is specified by the :code:`variable` attribute in the :code:`reset` block.
    - **What new value should be given to the reset variable?**
      This is called the "reset value" and is specified by evaluating the MathML content which is inside the :code:`reset_value` element child of this :code:`reset` element.
    - **Which variable will tell us when to trigger the change?**
      This is called the "test variable" and is referenced by the :code:`test_variable` attribute in the :code:`reset` block.
      The test variable can be the same as the reset variable.
    - **What value of the test variable should be used to trigger the change?**
      This is called the "test value" and is specified by evaluating the MathML content inside the :code:`test_value` element child of this :code:`reset` element.
    - **What happens if more than one reset points to the same reset variable?**
      This will be sorted out by the unique :code:`order` attribute on each :code:`reset` element which changes this reset variable.
      The order will determine which of the active competing resets is applied.

    Some of the syntax is explained below in the "see more" sections, and a final example is given at the end.
    For a much more thorough discussion and examples of resets in different scenarios, please see the
    :numref:`{number} {name}<specC_interpretation_of_resets>` section.
