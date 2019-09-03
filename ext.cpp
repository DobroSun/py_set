#include "python3.6m/Python.h"
#include <set>




static int pyset_init(std::set<int> *self, PyObject *args, PyObject *kwargs) {
    int type;

    if (!PyArg_ParseTuple(args, "i", &type)) return -1;

    self = new std::set<int>;



    return 0;
}


static PyTypeObject pysetType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyset.BST",
    .tp_new = PyType_GenericNew,
    .tp_init = (initproc) pyset_init
};



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
    PyObject *m;
    

    m = PyModule_Create(&pysetmodule);
    Py_INCREF(&pysetType);
    PyModule_AddObject(m, "BST", (PyObject *)&pysetType);
    return m;
}
