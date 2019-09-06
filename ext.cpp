#include "python3.6m/Python.h"
#include <set>

#include <iostream>
#include <typeinfo>


static PyObject *pyset_new(PyTypeObject *type, PyObject *args, PyObject *kwargs) {
    void *c_type;

    std::set<decltype(c_type)> *self;
    self = (std::set<decltype(c_type)> *)type->tp_alloc(type, 0);
    
    return (PyObject *)self;
}
/*
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

static PyMethodDef pyset_methods[] = {
    {"size", (PyCFunction)pyset_size, METH_NOARGS,
        "Return size of set"},
    {"add", (PyCFunction)pyset_add, METH_VARARGS,
        "Add item in set"},
    {NULL, NULL, 0, NULL}
};
*/

static PyTypeObject pysetType = {
    PyVarObject_HEAD_INIT(NULL, 0)
 
    .tp_name = "pyset.BST",
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

    pysetType.tp_new = pyset_new;
    //pysetType.tp_methods = pyset_methods;

    if (PyType_Ready(&pysetType) < 0) return NULL;

    m = PyModule_Create(&pysetmodule);
    Py_INCREF(&pysetType);
    PyModule_AddObject(m, "BST", (PyObject *)&pysetType);
    return m;
}
