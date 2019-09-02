#!/bin/bash

cd /usr/lib/python3/dist-packages;
rm pyset.cpython-36m-x86_64-linux-gnu.so;

cd /set;
python3 setup.py build_ext -i;

mv pyset.cpython-36m-x86_64-linux-gnu.so /usr/lib/python3/dist-packages;
rm -R build;

