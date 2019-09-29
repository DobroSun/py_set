#!/usr/bin/env python3

from py_set import pyset
import time
import sys
import random

random_list = [random.randrange(-1000000, 2000000) for _ in range(1000000)]

pst = pyset()
st = set()
lst = list()

print()
print("*** Adding elements ***")
start = time.time()
for i in range(1000000):
    lst.append(i)
end = time.time() - start
print("List time on adding 10^6 items: %.2fms" % (end * 1000))

start = time.time()
for i in range(1000000):
    st.add(i)
end = time.time() - start
print("Set time on adding 10^6 items: %.2fms" % (end * 1000))

start = time.time()
for i in range(1000000):
    pst.add(i)
end = time.time() - start
print("Pyset time on adding 10^6 items: %.2fms" % (end * 1000))
print()

print("*** Searching for elements ***")
start = time.time()
for i in random_list:
    i in st
end = time.time() - start
print("Set time on searching in 10^6 items: %.2fms" % (end * 1000))

start = time.time()
for i in random_list:
    i in pst
end = time.time() - start
print("Pyset time on searching in 10^6 items: %.2fms" % (end * 1000))
print()

print("*** Deleting elements ***")
start = time.time()
for i in range(1000000):
    st.remove(i)
end = time.time() - start
print("Set time on deleting 10^6 items: %.2fms" % (end * 1000))
start = time.time()
for i in range(1000000):
    pst.remove(i)
end = time.time() - start
print("Pyset time on deleting 10^6 items: %.2fms" % (end * 1000))
