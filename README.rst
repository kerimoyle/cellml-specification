
CellML Specification
====================

This repository will be used by the CellML editors to develop the CellML specification (starting with version 1.2)
The content has been reworked to include an informal guide embedded within the normative specification text (in version 2.0).

If things work correctly, changes in this repository will be reflected over at: https://cellml-specification.readthedocs.org/.

Building the documentation locally
----------------------------------

The documentation can be built on your local machine with the following instructions.
Do take note that the following instructions are suitable for Unix-derived operating systems and may need modification for other operating systems.
Also, note that we require at least version 3.5 of Python to build the documentation.

First clone a local copy of the CellML specification repository::

  git clone https://github.com/cellml/cellml-specification.git

Next setup a virtual environment::

  virtualenv venv_specification

Note: Make sure you are creating a Python 3 virtual environment, if required use the -p flag to set the Python interpreter (for example `virtualenv -p /absolute/path/to/python venv_specification`).

Then activate the virtual environment and instal the required packages::

  source venv_specification/bin/activate
  pip install sphinx sphinx_rtd_theme
  pip install -r cellml-specification/requirements.txt

That completes the environment setup required for building the documentation.
Once the environment is completed the HTML form of the documentation can be built with the following commands::

  cd cellml-specification
  make html

The built documentation will be available at::

  /absolute/path/to/cellml-specification/build/html/index.html

Any good internet browser will be able to display the documentation.

To build the PDF form of the documentation simply execute the following command::

  make latexpdf

Note: Creating the PDF form of the documentation requires that latexmk is available, information on latexmk can be found at https://ctan.org/pkg/latexmk/.

Note: The documentation built with `make html` is different to the documentation built with `make latexpdf`.
The HTML form of the documentation is the full form being both the normative specification and the informative specification, the PDF form of the documentation is solely the normative specification.
