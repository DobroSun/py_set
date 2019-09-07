#include "Python.h"

#include <iostream>
#include <string>
#include <set>

struct A {
    PyObject_HEAD
    std::string type;
    std::set<PyObject> *s;
};

static PyObject *_converting_values(PyObject *type, std::string *name) {
    
}

static int pyset_init(A *self, PyObject *args, PyObject *kwargs) {
    PyObject *item = 0;
    
    PyArg_ParseTuple(args, "|O", &item);
    
    if (item) {
        std::cout << "Creating user type" << std::endl;
        self->type = std::string(item->ob_type->tp_name);
    } else {
        self->type = "";
    }
    
    self->s = new std::set<PyObject>;
    return 0;
}

static PyObject *pyset_size(A *self) {
    int len = self->s->size();
    return Py_BuildValue("i", len);
}

static PyObject *pyset_add(A *self, PyObject *args) {
    PyObject *item;

    if (!PyArg_ParseTuple(args, "O", &item)) PyErr_SetString(PyExc_Exception, "Exception");
    std::cout << "Current value ";
    std::cout << std::string(item->ob_type->tp_name) << std::endl;
    
   
    std::cout << "Expected value ";
    std::cout << self->type << std::endl;
    
    if (self->type.empty()) {
        std::cout << "Building first value" << std::endl;
        self->type = std::string(item->ob_type->tp_name);

    } else if (std::string(item->ob_type->tp_name) != self->type) {
        std::cout << "Raising Error" << std::endl;
        PyErr_SetString(PyExc_Exception, "Wrong type");
    }
    
    //self->s->insert(*item);
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
