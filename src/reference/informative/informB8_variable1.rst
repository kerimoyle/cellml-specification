.. _informB8:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    In addition to the standard :code:`name` attribute, each :code:`variable` must also define a :code:`units` attribute too.

    Reusing Einstein's example from :numref:`{number} {name}<specB_component>` section we can give the three variables their fuller definitions:

    .. code-block:: xml

      <component name="mass_into_energy">
          <math>
            ...
          </math>
          <variable name="E" units="joule"/>
          <variable name="m" units="kilogram"/>
          <variable name="c" units="metre_per_second"/>
      </component>

    Extra attributes that can be used as needed include the :code:`initial_value`, which will either set a constant value for a variable, or set its initial conditions if it's being solved for.
    More information about initialisation can be found in :numref:`{number} {name}<specC_interpretation_of_initial_values>`.

    Finally, where one :code:`variable` (A) has been mapped to another (B) in a different component (BB), both A and B must specify :code:`interface` attributes.
    These prescribe the relative positions in the encapsulation that the components AA and BB must have in order for their respective variables A and B to access one another.
    This is outlined in more detail in :numref:`{number} {name}<specB_encapsulation>`.
