#include "Python.h"

#include <cstdio>
#include <variant>
#include <set>
#include <string>

#define VARIANT_TYPE std::variant<double, std::string, long int>

struct A {
    PyObject_HEAD
    std::string type;

    std::set<VARIANT_TYPE> *s;
};

auto converting_values(PyObject *item, std::string *name) {
    if (*name == std::string("float")) {
        VARIANT_TYPE d = PyFloat_AsDouble(item);
        return d;

    } else if (*name == std::string("int")) {
        VARIANT_TYPE l = PyLong_AsLong(item);
        return l;

    } else if (*name == std::string("str")) {
        VARIANT_TYPE s(PyBites_AsString(item));
        return s;
    }

}


