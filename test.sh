#!/bin/bash

cd test_upload/
source venv/bin/activate
 
pip3 install --upgrade --force-reinstall c_set
./test.py
./test_compare.py

deactivate
