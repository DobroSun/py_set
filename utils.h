#include "Python.h"

#include <variant>
#include <set>
#include <string>

#define VARIANT_TYPE std::variant<double, const char*, long int>

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
    PyObject *operator()(const char *s) const {
        return Py_BuildValue("s", s);
    }
};

void fill_pyset(A *self, int start, int stop, int step) {
    int p = (step > 0)?1: -1;

    for (long int i = start; p*i < p*stop; i += step) {
        VARIANT_TYPE a = i;
        self->s->insert(a);
    }
}

static PyObject *from_c_values(VARIANT_TYPE value) {
    PyObject *val;
    val = std::visit(visit_helper{}, value);
    return val;
}


VARIANT_TYPE to_c_values(A *self, PyObject *item) {
    std::string type(item->ob_type->tp_name);

    if (type == std::string("float")) {
        VARIANT_TYPE d = PyFloat_AsDouble(item);
        return d;

    } else if (type == std::string("int")) {
        VARIANT_TYPE l = PyLong_AsLong(item);
        return l;

    } else if (type == std::string("str")) {
        VARIANT_TYPE s = PyUnicode_AsUTF8(item);
        return s;

    } else if (type == std::string("list") || type == std::string("tuple")
               || type == std::string("set") || type == std::string("dict")) {
        PyErr_SetString(PyExc_TypeError, "List(tuple) inserting not supported. Maybe you would like to use from_list() method.");

   } else {
        PyErr_SetString(PyExc_TypeError, "Undefined type");
    }
    PyErr_SetString(PyExc_TypeError, "Undefined type");
    return NULL;
}
