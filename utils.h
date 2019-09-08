#include "Python.h"

#include <set>

struct A {
    PyObject_HEAD
    std::string type;
    std::set<PyObject> *s;
};

static PyObject *_converting_values(PyObject *type, std::string *name) {
    
}


