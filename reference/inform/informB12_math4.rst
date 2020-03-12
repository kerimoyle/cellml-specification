.. _informB12_2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    Perhaps the most important part of any model is the
    mathematics it contains.  This is stored inside a collection of
    :code:`<math>` blocks in :code:`component` items, which together define
    how the local :code:`variable` items are mathematically related.

    For example, the calculation of Einstein's :math:`E=mc^2` could be
    represented by:

    .. code-block:: xml

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


