API
===

cum_mediane
-----------

Fonction exposée par le module compilé ``cum_mediane_pkg``.

Elle prend un tableau NumPy 1D de ``float64`` et retourne un tableau
des médianes cumulatives.

Erreur
------

Une ``RuntimeError`` est levée si des données répétées sont présentes.