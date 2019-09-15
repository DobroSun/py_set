#include <iostream>
#include "utils.h"


static int pyset_init(PyObject *m, PyObject *args, PyObject *kwargs) {
    A *self = (A *)m;

    self->s = new std::set<VARIANT_TYPE>;
    return 0;
}
/*
static PyObject *pyset_new(PyTypeObject *type, PyObject *args, PyObject *kwargs) {
    printf("I'm here");

    A *self = (A *)pyset_type.tp_new(type, args, kwargs);

    if (!self) {
        return NULL;
    }
    return (PyObject *)self;
}*/



static PyObject *pyset_size(PyObject *m) {
    A *self = (A *)m;
    int len = self->s->size();
    return Py_BuildValue("i", len);
}


static PyObject *pyset_empty(A *self) {
    int emp = self->s->empty();
    return Py_BuildValue("i", emp);
}

static PyObject *pyset_add(PyObject *m, PyObject *args) {
    A *self = (A *)m;
    PyObject *item;

    if (!PyArg_ParseTuple(args, "O", &item)) PyErr_SetString(PyExc_Exception, "Exception");

    auto current = converting_values(self, item);

    self->s->insert(current);

    Py_RETURN_NONE;
}

static PyObject *pyset_find(A *self, PyObject *args) {
    PyObject *item;
    int res;

    if (!PyArg_ParseTuple(args, "O", &item)) PyErr_SetString(PyExc_Exception, "Exception");

    auto current = converting_values(self, item);

    auto search = self->s->find(current);
    if (search != self->s->end()) {
       res = 1;
    } else {
        res = 0;
    }
    return Py_BuildValue("i", res);
}

static PyTypeObject pysetType = {
    PyVarObject_HEAD_INIT(NULL, 0)
};


static PyMethodDef pyset_methods[] = {
    {"size", (PyCFunction)pyset_size, METH_NOARGS,
        "Return size of set"},
    {"add", (PyCFunction)pyset_add, METH_VARARGS,
        "Add item in set"},
    {"find", (PyCFunction)pyset_find, METH_VARARGS,
        "Search for items in set"},
    {"is_empty", (PyCFunction)pyset_empty, METH_NOARGS,
        "Checks if pyset is empty or not"},
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

    pysetType.tp_name = "pyset.BST",
    pysetType.tp_new = PyType_GenericNew;
    pysetType.tp_init = (initproc)pyset_init;
    pysetType.tp_methods = pyset_methods;
    
    if (PyType_Ready(&pysetType) < 0) return NULL;

    m = PyModule_Create(&pysetmodule);

    Py_INCREF(&pysetType);
    PyModule_AddObject(m, "BST", (PyObject *)&pysetType);
    return m;
}
