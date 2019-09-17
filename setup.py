from distutils.core import setup, Extension

module = Extension("pyset",
                   library_dirs=["."],
                   libraries=["utils.h"],
                   sources = ["ext.cpp"])

         
setup(name="pyset", 
      ext_modules=[module]
)

