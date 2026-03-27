#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <stdexcept>
#include "cum_mediane.h"

namespace py = pybind11;

py::array_t<double> cum_mediane_py(py::array_t<double> input) {
    py::buffer_info buf = input.request();

    if (buf.ndim != 1) {
        throw std::runtime_error("Number of dimensions must be one");
    }

    auto result = py::array_t<double>(buf.size);
    py::buffer_info buf_out = result.request();

    double* donnees_ptr = static_cast<double*>(buf.ptr);
    double* sortie_ptr = static_cast<double*>(buf_out.ptr);

    int taille = (int)buf.size;
    int status = cum_mediane(donnees_ptr, taille, sortie_ptr);

    if (status == ERROR_DONNEES_REPETEES) {
        throw std::runtime_error("Donnees repetees");
    }

    return result;
}

PYBIND11_MODULE(cum_mediane_pkg, m) {
    m.def(
        "cum_mediane",
        &cum_mediane_py,
        "Calcule la médiane cumulative d'un tableau 1D de float64 et lève une erreur si des valeurs sont répétées."
    );
}