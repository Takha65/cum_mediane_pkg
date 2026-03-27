.. Cum_mediane_pkg documentation master file, created by
   sphinx-quickstart on Fri Mar 27 07:43:47 2026.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Cum_mediane_pkg documentation
=============================



Bienvenue dans la documentation de cum_mediane_pkg
=================================================

cum_mediane_pkg est un package Python avec extension C++ via pybind11
qui calcule la médiane cumulative d'un tableau NumPy 1D.

Exemple
-------

.. code-block:: python

   import numpy as np
   import cum_mediane_pkg

   x = np.array([2.0, 3.0, 0.0, 1.0, 5.0])
   print(cum_mediane_pkg.cum_mediane(x))

Sortie attendue::

   [2.  2.5 2.  1.5 2. ]

.. toctree::
   :maxdepth: 2
   :caption: Contenu

   api
