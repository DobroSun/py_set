#include "python3.6m/Python.h"
#include <set>

#include <typeinfo>
#include <iostream>


struct A {
    PyObject_HEAD
    std::set<int> *s;
};


static int pyset_init(A *self, PyObject *args, PyObject *kwargs) {
    self->s = new std::set<int>;
    return 0;
}

static PyObject *pyset_size(A *self) {
    int len = self->s->size();
    return Py_BuildValue("i", len);
}

static PyObject *pyset_add(A *self, PyObject *args) {
    int item;

    if (!PyArg_ParseTuple(args, "i", &item)) PyErr_SetString(PyExc_Exception, "Exception");

    std::cout << args->ob_type << std::endl;

    self->s->insert(item);
    Py_RETURN_NONE;
}

static PyTypeObject pysetType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "pyset.BST",
};


static PyMethodDef pyset_methods[] = {
    {"size", (PyCFunction)pyset_size, METH_NOARGS,
        "Return size of set"},
    {"add", (PyCFunction)pyset_add, METH_VARARGS,
        "Add item in set"},
    {NULL, NULL, 0, NULL}
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

    pysetType.tp_new = PyType_GenericNew;
    pysetType.tp_init = (initproc)pyset_init;
    pysetType.tp_methods = pyset_methods;
    
    if (PyType_Ready(&pysetType) < 0) return NULL;

    m = PyModule_Create(&pysetmodule);
    Py_INCREF(&pysetType);
    PyModule_AddObject(m, "BST", (PyObject *)&pysetType);
    return m;
}
