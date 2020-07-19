.. _informB11:
.. _inform_reset_value:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    The :code:`test_value` (like the :code:`reset_value`) block takes a slightly different kind of MathML statement to those in the :code:`component` elements.
    Because the the left hand side of the equation has already been effectively defined by specifying the :code:`test_variable`, the :code:`math` child of a :code:`test_value` needs only to specify the right hand side.
    This means that the normal opening block of :code:`<apply><eq/><ci>left_hand_side_variable</ci> ... </apply>` is omitted:

    .. code-block:: xml

      <reset variable="position" test_variable="height_above_the_floor_in_metres" order="1"/>
        <test_value>
          <math>
              <cn cellml:units="metre">1.0</cn>
          </math>
        </test_value>
        <reset_value>
          <math>
            <apply><plus/>
              <apply><abs/>
                <apply><minus/>
                  <cn cellml:units="metre">1</cn>
                  <ci>position</ci>
                </apply>
              </apply>
              <cn cellml:units="metre">1.0</cn>
            </apply>
          </math>
        </reset_value>
      </reset>

    In the above example, the position of a ball above a 1 metre high table is maintained, as every time it appears to drop below the table-level datum of :code:`position=1.0` it is reset to a "bounced" value greater than 1.0 instead.

    For the :code:`reset` to be useful, the equations it contains need to make sense.
    Be sure to check that the units that you're using within the :code:`test_value` block match those of the :code:`test_variable` against which it will be compared.
    In this example the :code:`reset_value` (the new position of the ball over the table) must be in metres to match the :code:`variable`\'s units, as with the :code:`test_value` which must match the units of the :code:`test_variable`.
    A mismatch of units here doesn't mean you have an invalid CellML 2.0 model, but it does mean that it may not behave in the way you are expecting!
