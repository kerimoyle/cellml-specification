.. _informB12_2:

.. container:: toggle

  .. container:: header

    See more

  .. container:: infospec

    When specifying a constant with :code:`<cn>`, its
    :ref:`real number value<specA_real_number>` is given between the tags,
    and its units are specified as an attribute.  

    .. code-block:: xml

      <!-- These are valid: note the cellml namespace for the units -->
      <cn cellml:units="customUnitsDefinedInTheModel">35.3</cn> <!-- units which exist in the model are permitted -->
      <cn cellml:units="litre">10</cn> <!-- built-in units (with UK spelling) are permitted -->
      <cn cellml:units="dimensionless">3.14159e+03</cn> <!-- e-notation is permitted -->

    Please note that the units name specified must refer to
    a :code:`units` element that exists in the :code:`model` element,
    or be one from the :ref:`Built-in Units<table_built_in_units>` table.

    .. code-block:: xml

      <!-- These are not valid -->
      <cn cellml:units="unitsThatDontExist">35.3</cn> <!-- the units reference must exist in the model -->
      <cn>42</cn> <!-- units must be specified -->
      <cn some_other_namespace:units>502.642</cn> <!-- units must be in the cellml namespace -->
      <cn cellml:units="meter">26.6</cn> <!-- built-in unit names must be in UK spelling, ie: metre, litre -->
      <cn cellml:units="dimensionless">3,000</cn> <!-- must be a valid real number string, the comma separator is not permitted -->
      <cn cellml:units="dimensionless">+4.0</cn> <!-- the plus sign indicator is not permitted except in e-notation exponents -->
      <cn cellml:units="dimensionless">0x235abc</cn> <!-- value must be in base 10 -->
      <cn cellml:units="dimensionless">i_am_a_variable</cn> <!-- only real number values are permitted in <cn> blocks -->





    

