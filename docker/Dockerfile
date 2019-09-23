FROM ubuntu:latest

RUN apt-get update && apt-get -y install python3\ 
                                         python3-dev\
                                         python3-pip \
                                         python3-setuptools \
                                         build-essential

COPY . .
WORKDIR .

RUN python3 setup.py install
RUN python3 test_upload/test.py
