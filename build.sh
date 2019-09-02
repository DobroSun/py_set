#!/bin/bash

cd /usr/local/lib/python3.6/dist-packages;
rm pyset.cpython-36m-x86_64-linux-gnu.so;

cd /set;
python3 setup.py install;

rm -R build;

