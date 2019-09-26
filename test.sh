#!/bin/bash

cd test_upload/
source venv/bin/activate

cd ..
#make upload
 
cd -
pip3 install c_set==0.1.6
python3 test.py

deactivate

