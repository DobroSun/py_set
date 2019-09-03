#include "python3.6m/Python.h"
#include <set>



static PyMethodDef pysetMethods[] = {
};

static struct PyModuleDef pysetmodule = {
    PyModuleDef_HEAD_INIT,
    "pyset",
    "",
    -1,
    NULL, NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC PyInit_pyset(void) {
    return PyModule_Create(&pysetmodule);
}
