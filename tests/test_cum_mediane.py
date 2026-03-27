import numpy as np
import pytest
import cum_mediane_pkg


def test_cum_mediane_diapo():
    donnees = np.array([2.0, 3.0, 0.0, 1.0, 5.0])
    attendu = np.array([2.0, 2.5, 2.0, 1.5, 2.0])
    obtenu = cum_mediane_pkg.cum_mediane(donnees)
    assert np.allclose(obtenu, attendu)


def test_cum_mediane_repetition():
    donnees = np.array([2.0, 3.0, 2.0])
    with pytest.raises(RuntimeError, match="repetees|repetees|Donnees repetees"):
        cum_mediane_pkg.cum_mediane(donnees)
