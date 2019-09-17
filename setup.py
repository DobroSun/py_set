from distutils.core import setup, Extension

module = Extension("pyset",
                   include_dirs=["/usr/include/"],
                   libraries=["variant"],
                   sources = ["ext.cpp"])

         
setup(name="pyset", 
      ext_modules=[module]
)

