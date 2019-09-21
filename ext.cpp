#include "utils.h"


static int pyset_init(A *self, PyObject *args, PyObject *kwargs) {
    int start, stop, step;
    start = 0;stop = 0;step = 0;

    self->s = new std::set<VARIANT_TYPE>;
    if (PyTuple_Size(args) == 0) {

    } else if (PyArg_ParseTuple(args, "|iii", &start, &stop, &step)) {
        if (!stop && !step) {
            stop = start;
            start = 0;
            step = 1;
            fill_pyset(self, start, stop, step);

        } else if (!step) {
            step = 1;
            fill_pyset(self, start, stop, step);

        } else {
            fill_pyset(self, start, stop, step);
        }
    }
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

static PyObject *pyset_iter(PyObject *p) {
    A *self;
    self = (A *)p;

    self->it = self->s->begin();

    Py_INCREF(p);
    return p;
}

static PyObject *pyset_iternext(PyObject *p) {
    A *self;
    self = (A *)p;
    
    if (self->it != self->s->end()) {
        auto tmp = from_c_values(*self->it);
        (self->it)++;
        return tmp;
    } else {
        self->it = self->s->begin();
        PyErr_SetNone(PyExc_StopIteration);
        return NULL;
    }

}

static PyObject *pyset_size(A *self) {
    int len = self->s->size();
    return Py_BuildValue("i", len);
}


static PyObject *pyset_empty(A *self) {
    int emp = self->s->empty();
    return Py_BuildValue("i", emp);
}

static PyObject *pyset_clear(A *self) {
    self->s->clear();
    Py_RETURN_NONE;
}

static PyObject *pyset_add(A *self, PyObject *args) {
    PyObject *item;

    if (!PyArg_ParseTuple(args, "O", &item)) PyErr_SetString(PyExc_Exception, "Exception");

    auto current = to_c_values(self, item);

    self->s->insert(current);

    Py_RETURN_NONE;
}

static PyObject *pyset_find(A *self, PyObject *args) {
    PyObject *item;
    int res;

    if (!PyArg_ParseTuple(args, "O", &item)) PyErr_SetString(PyExc_Exception, "Exception");

    auto current = to_c_values(self, item);

    auto search = self->s->find(current);
    if (search != self->s->end()) {
       res = 1;
    } else {
        res = 0;
    }
    return Py_BuildValue("i", res);
}

static PyObject *pyset_to_list(A *self, PyObject *args) {
    PyObject *list;
    list = PyList_New(0);

    if (!list) return NULL;

    for (auto i: *(self->s)) {
        PyObject *item = from_c_values(i);
        PyList_Append(list, item);
    }
    
    return list;
}

static PyObject *pyset_from_list(A *self, PyObject *args) {

    for (int i = 0; i < PySequence_Size(args); i++) {
        PyObject *item = PySequence_GetItem(args, i);
        for (int j = 0; j < PySequence_Size(item); j++) {

            PyObject *var = PySequence_GetItem(item, j);
            VARIANT_TYPE current = to_c_values(self, var);
            self->s->insert(current);
        }
    }
    Py_RETURN_NONE;
}

static PyTypeObject pysetType = {
    PyVarObject_HEAD_INIT(NULL, 0)
};


static PyMethodDef pyset_methods[] = {
    {"size", (PyCFunction)pyset_size, METH_NOARGS,
        "Return size of pyset"},
    {"clear", (PyCFunction)pyset_clear, METH_NOARGS,
        "Clear pyset"},
    {"is_empty", (PyCFunction)pyset_empty, METH_NOARGS,
        "Checks if pyset is empty or not"},
    {"add", (PyCFunction)pyset_add, METH_VARARGS,
        "Add item in pyset"},
    {"find", (PyCFunction)pyset_find, METH_VARARGS,
        "Search for items in pyset"},
    {"to_list", (PyCFunction)pyset_to_list, METH_VARARGS,
        "Return list of pyset items"},
    {"from_list", (PyCFunction)pyset_from_list, METH_VARARGS,
        "Add all items from iterables to pyset"},
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
    pysetType.tp_iter = pyset_iter;
    pysetType.tp_iternext = pyset_iternext;
    
    if (PyType_Ready(&pysetType) < 0) return NULL;

    m = PyModule_Create(&pysetmodule);

    Py_INCREF(&pysetType);
    PyModule_AddObject(m, "BST", (PyObject *)&pysetType);
    return m;
}
