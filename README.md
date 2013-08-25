cellml-specification
====================

This repository will be used by the CellML editors to develop the CellML specification (starting with version 1.2). The content was initially obtained from https://github.com/A1kmm/cellml-core-spec/tree/normative, using pandoc to convert the docbook XML to reST format (``for f in *.xml; do pandoc -f docbook -o `basename $f .xml`.rst $f; done``). The reST documents were then incorporated into a basic sphinx project.

If things work correctly, changes in this repository will be reflected over at: https://cellml-specification.readthedocs.org/.
