from distutils.core import setup, Extension

module = Extension("pyset",
                   sources = ["ext.cpp"])
         
setup(name="pyset", 
      ext_modules=[module]
)

