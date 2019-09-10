#include "Python.h"

#include <variant>
#include <set>
#include <string>

struct types {
    std::variant<int, double> T_type;
};


struct A {
    PyObject_HEAD
    std::string type;

    std::set<std::auto> *s;
};

static PyObject *_converting_values(PyObject *type, std::string *name) {

}


