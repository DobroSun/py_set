from distutils.core import setup, Extension

module = Extension("pyset",
                   sources = ["test.cpp"])
         



setup(name="pyset", 
      ext_modules=[module]
)

