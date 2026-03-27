#include "cum_mediane.h"
#include <set>
#include <iterator>

int cum_mediane(const double* donnees_ptr, const int taille, double* sortie_ptr) {
    std::set<double> valeurs;
    std::set<double>::iterator med;

    for (int i = 0; i < taille; i++) {
        double x = donnees_ptr[i];
        auto resultat = valeurs.insert(x);
        auto it = resultat.first;
        bool inserted = resultat.second;

        if (!inserted) return ERROR_DONNEES_REPETEES;

        if (valeurs.size() == 1) {
            med = it;
        } else if (valeurs.size() % 2 == 0) {
            if (x < *med) med--;
        } else {
            if (x > *med) med++;
        }

        if (valeurs.size() % 2 == 1) {
            sortie_ptr[i] = *med;
        } else {
            auto droite = std::next(med);
            sortie_ptr[i] = (*med + *droite) / 2.0;
        }
    }
    return SUCCESS;
}