#!/bin/bash

cd test_upload/
source venv/bin/activate
 
pip3 install --upgrade --force-reinstall py_set
./test.py
./test_compare.py

deactivate
