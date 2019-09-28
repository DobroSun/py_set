import os.path
from setuptools import setup, Extension

def read(fname):
    with open(os.path.join(os.path.dirname(__file__), fname)) as f:
        return f.read()

module = Extension("py_set",
                   extra_compile_args=["-std=c++17"],
                   sources = ["ext.cpp"])
         
setup(name="py_set",
      version="0.1.1",
      description="C extension module actualizing red-black search tree for Python3",
      long_description=read("README.md"),
      author="Dobrogost Pavel",
      author_email="mr.dobrogost02@mail.ru",
      url="https://github.com/DobroSun/py_set",
      
      ext_modules=[module],
)
