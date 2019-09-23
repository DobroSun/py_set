#!/bin/bash

cd test_upload/
source venv/bin/activate

cd ..
sudo apt-get install twine
make upload
 
cd -
pip3 install c_set==0.1.0
python3 test.py

echo "Test Passed"
