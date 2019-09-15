#include "Python.h"

#include <cstdio>
#include <variant>
#include <set>
#include <string>

#define VARIANT_TYPE std::variant<double, std::string, long int, int>

typedef struct {
    PyObject_HEAD
    std::string type;

    std::set<VARIANT_TYPE> *s;
} A;

VARIANT_TYPE converting_values(A *self, PyObject *item) {
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


