#include "python3.6m/Python.h"
#include <set>

#include "gcd.h"




static PyObject *py_gcd(PyObject *self, PyObject *args) {
    int x, y, result;

    if (!PyArg_ParseTuple(args, "ii", &x, &y)) {
        return NULL;
    }

    result = gcd(x, y);
    return Py_BuildValue("i", result);
}



static PyMethodDef pysetMethods[] = {
    {"gcd", py_gcd, METH_VARARGS,
                     "Test for gcd"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef pysetmodule = {
    PyModuleDef_HEAD_INIT,
    "pyset",
    "",
    -1,
    pysetMethods
};

PyMODINIT_FUNC PyInit_pyset(void) {
    return PyModule_Create(&pysetmodule);
}
