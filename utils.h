#include "Python.h"

#include <cstdio>
#include <variant>
#include <set>
#include <string>


struct A {
    PyObject_HEAD
    std::string type;

    std::set<std::variant<int, double, std::string>> *s;
};

auto converting_values(PyObject *item, std::string *name) {
    if (*name == std::string("float")) {
        double cur = PyFloat_AsDouble(item);
        return cur;
    }
}


