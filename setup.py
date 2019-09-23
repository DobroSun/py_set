import os.path
from distutils.core import setup, Extension

def read(fname):
    with open(os.path.join(os.path.dirname(__file__), fname)) as f:
        return f.read()


module = Extension("c_lib",
                   extra_compile_args=["-std=c++17"],
                   sources = ["ext.cpp"])

         
setup(name="c_lib", 
      version="0.1.0",
      long_description="C extension module actualizing red-black search tree for Python3",
      author="Dobrogost Pavel",
      author_email="mr.dobrogost02@mail.ru",
      url="https://github.com/DobroSun/py_set",
      
      ext_modules=[module],
)
