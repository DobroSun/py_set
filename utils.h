#include "Python.h"

#include <cstdio>
#include <variant>
#include <set>
#include <string>

#define VARIANT_TYPE std::variant<double, std::string, long int>

typedef struct {
    PyObject_HEAD

    std::set<VARIANT_TYPE> *s;
    std::set<VARIANT_TYPE>::iterator it;
} A;

void fill_pyset(A *self, int *c_start=NULL, int *c_stop=NULL, int *c_step=NULL) {
    int start, stop, step;
    stop = *c_stop;
    if (c_start == NULL && c_step == NULL) {
        start = 0;
        step = 1;
    } else if (c_step == NULL) {
        start = *c_start;
        step = 1;
    } else {
        start = *c_start;
        step = *c_step;
    }
    for (long int i = start; i < stop; i += step) {
        self->s->insert(i);
    }
    
}

static PyObject *from_c_values(VARIANT_TYPE value) {
    //item = std::get<PyObject>(value);
    Py_RETURN_NONE;
}


VARIANT_TYPE to_c_values(A *self, PyObject *item) {
    std::string type(item->ob_type->tp_name);

    PyObject *tmp;
    if (type == std::string("float")) {
        VARIANT_TYPE d = PyFloat_AsDouble(item);
        return d;

    } else if (type == std::string("int")) {
        VARIANT_TYPE l = PyLong_AsLong(item);
        return l;

    } else if (type == std::string("str")) {
        if (PyUnicode_Check(item)) {
            tmp = PyUnicode_AsUTF8String(item);
        } else if (PyBytes_Check(item)) {
            tmp = PyObject_Bytes(item);
        } else {
            tmp = NULL;
            PyErr_SetString(PyExc_Exception, "Wrong type");
        }

        VARIANT_TYPE s = std::string(PyBytes_AsString(tmp));

        return s;
    } else {
        PyErr_SetString(PyExc_Exception, "Wrong type");
    }
    PyErr_SetString(PyExc_Exception, "Wrong type");
    return NULL;
}


