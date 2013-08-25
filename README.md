cellml-spec-sphinx-test
=======================

This repository will be used by the CellML editors to test out the use of reST and sphinx with github and readthedocs in developing the CellML 1.2 specification. The content was initially obtained from https://github.com/A1kmm/cellml-core-spec/tree/normative, using pandoc to convert the docbook XML to reST format (``for f in *.xml; do pandoc -f docbook -o `basename $f .xml`.rst $f; done``). This was incorporated into a basic sphinx project.

If things work correctly, changes in this repository will be reflected over at: https://cellml-specifications-sphinx-testing.readthedocs.org/.
