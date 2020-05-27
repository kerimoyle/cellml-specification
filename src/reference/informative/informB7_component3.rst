.. _informB7_3:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    .. container:: heading3

      The mathematics of a component

    Perhaps the most important part of a :code:`component` item is the mathematics it contains.
    This is stored inside a collection of :code:`<math>` blocks as described in :numref:`{number} {name}<specB_math>`.
    The :code:`math` then defines the operation of the local :code:`variable` items and how they relate to each other mathematically.

    For example, a component to calculate Einstein's :math:`E=mc^2` could be represented by:

    .. code-block:: xml

      <component name="mass_into_energy">
        <math>
          <apply><eq/>
            <ci>E</ci>
            <apply><times/>
              <ci>m</ci>
              <apply><power/>
                <ci>c</ci>
                <cn cellml:units="dimensionless">2</cn>
              </apply>
            </apply>
          </apply>
        </math>
        ...
      </component>

    Please refer to :numref:`{number} {name}<math>` for information on the :code:`math` items and MathML format.

    .. container:: heading3

      The variables of a component

    The MathML block above refers to three variables named :code:`E`, :code:`m` and :code:`c`.
    These variable names must be the same as the :code:`name` attributes of the child :code:`variable` items in this component.

    .. code-block:: xml

      <component name="mass_into_energy">
        ...
        <variable name="E" units="joule" />
        <variable name="m" units="kilogram" />
        <variable name="c" units="metres_per_second" />
      </component>

    Please refer to :numref:`{number} {name}<variable>` for information on :code:`variable` items.

    .. container:: heading3

      The reset items of a component

    Please refer to :numref:`{number} {name}<reset>` for more information on :code:`reset` items.
