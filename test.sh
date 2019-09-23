#!/bin/bash

cd test_upload/
source venv/bin/activate

cd ..
make upload
 
cd -
#pip3 install
python3 test.py
