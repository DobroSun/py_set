from distutils.core import setup, Extension

module = Extension("pyset",
                   extra_compile_args=["-std=c++17"],
                   sources = ["ext.cpp"])

         
setup(name="pyset", 
      ext_modules=[module]
)

