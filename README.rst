
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

Note: Creating the PDF form of the documentation requires that some or all of a tool like Windows/MikTeX, macOS/MacTeX, Windows/TeXlive, Linux/TeXlive is available to the Sphinx build tool.

Documentation builds
^^^^^^^^^^^^^^^^^^^^

There are three types of build that can be created from this codebase.

1. Full documentation build of the normative and informative specification combined.
2. Multi-paged documentation build of the normative specification.
3. Single page documentation build of the normative specification.

The different builds can be controlled through the use of the environment variable::

  CELLML_SPEC_BUILD

To build the multi-paged normative specification set the value of this environment variable to **MultiPageNormative**.
For the single page normative specification set the value of the environment variable to **SinglePageNormative**.
Any other value, or if the environment variable is not set, will build the full documentation.
