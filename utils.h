#include "Python.h"

#include <variant>
#include <set>
#include <string>


struct A {
    PyObject_HEAD
    std::string type;

    std::set<std::variant<int, double>> *s;
};

static PyObject *_converting_values(PyObject *item, std::string *name) {
}


