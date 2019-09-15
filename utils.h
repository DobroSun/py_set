#include "Python.h"

#include <cstdio>
#include <variant>
#include <set>
#include <string>

#define VARIANT_TYPE std::variant<double, std::string, long int>

typedef struct {
    PyObject_HEAD
    std::string type;

    std::set<VARIANT_TYPE> *s;
} A;

auto converting_values(A *self, PyObject *item) {
	if (item) {
        self->type = std::string(item->ob_type->tp_name);
    } else PyErr_SetString(PyExc_Exception, "Wrong type");


    if (self->type == std::string("float") && PyFloat_Check(item)) {
        VARIANT_TYPE d = PyFloat_AsDouble(item);
        return d;

    } else if (self->type == std::string("int")) {
        VARIANT_TYPE l = PyLong_AsLong(item);
        return l;

    } else if (self->type == std::string("str")) {
        PyObject *tmp;
        if (PyUnicode_Check(item)) {
            tmp = PyUnicode_AsUTF8String(item);
        } else if (PyBytes_Check(item)) {
            tmp = PyObject_Bytes(item);
        } else {
            PyErr_SetString(PyExc_Exception, "Wrong type");
        }

        VARIANT_TYPE s = std::string(PyBytes_AsString(tmp));

        return s;
    } else {
        PyErr_SetString(PyExc_Exception, "Wrong type");
    }

}


