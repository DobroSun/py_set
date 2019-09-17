#include "Python.h"

#include <cstdio>
#include <variant>
#include <set>
#include <string>

#define VARIANT_TYPE std::variant<double, char*, long int>

typedef struct {
    PyObject_HEAD

    std::set<VARIANT_TYPE> *s;
    std::set<VARIANT_TYPE>::iterator it;
} A;

struct visit_helper {
    PyObject *operator()(double d) const {
        return Py_BuildValue("d", d);
    }
    PyObject *operator()(long int l) const {
        return Py_BuildValue("l", l);
    }
    PyObject *operator()(char *s) const {
        return Py_BuildValue("s", s);
    }

};


void fill_pyset(A *self, int start, int stop, int step) {
    int p = (step > 0)?1: -1;

    for (long int i = start; p*i < p*stop; i += step) {
        self->s->insert(i);
    }
}
void fill_pyset(A *self, int start, int stop) {
    for (long int i = start; i < stop; i++) {
        self->s->insert(i);
    }
} 
void fill_pyset(A *self, int stop) {
    for (long int i = 0; i < stop; i++) {
        self->s->insert(i);
    }
}

static PyObject *from_c_values(VARIANT_TYPE value) {
    PyObject *val;
    val = std::visit(visit_helper{}, value);
    return val;
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

        VARIANT_TYPE s = PyBytes_AsString(tmp);
        return s;
    } else {
        PyErr_SetString(PyExc_Exception, "Wrong type");
    }
    PyErr_SetString(PyExc_Exception, "Wrong type");
    return NULL;
}


