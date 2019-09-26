#!/bin/bash

cd test_upload/
source venv/bin/activate
 
pip3 install --upgrade --force-reinstall c_set
python3 test.py

deactivate
