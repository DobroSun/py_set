#include <iostream>
#include "utils.h"


static int pyset_init(A *self, PyObject *args, PyObject *kwargs) {
    self->s = new std::set<VARIANT_TYPE>;
    return 0;
}

static PyObject *pyset_new(PyTypeObject *type, PyObject *args, PyObject *kwargs) {
    A *self;
    self = (A *)type->tp_alloc(type, 0);

    if (!self) {
        return NULL;
    }
    return (PyObject *)self;
}



static PyObject *pyset_size(A *self) {
    int len = self->s->size();
    return Py_BuildValue("i", len);
}


static PyObject *pyset_empty(A *self) {
    int emp = self->s->empty();
    return Py_BuildValue("i", emp);
}

static PyObject *pyset_add(A *self, PyObject *args) {
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

    // It doesn't work inside pysetType, so It has to be defined there
    pysetType.tp_name = "pyset.BST",
    pysetType.tp_itemsize = 0,
    pysetType.tp_flags = Py_TPFLAGS_DEFAULT,
    pysetType.tp_basicsize = sizeof(A),
    pysetType.tp_new = pyset_new;
    pysetType.tp_init = (initproc)pyset_init;
    pysetType.tp_methods = pyset_methods;
    
    if (PyType_Ready(&pysetType) < 0) return NULL;

    m = PyModule_Create(&pysetmodule);

    Py_INCREF(&pysetType);
    PyModule_AddObject(m, "BST", (PyObject *)&pysetType);
    return m;
}
