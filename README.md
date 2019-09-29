# Pyset
[![Build Status](https://travis-ci.com/DobroSun/py_set.svg?branch=master)](https://travis-ci.com/DobroSun/py_set)

PySet is wrapper of C++ standart red-black tree realization(std::set)

Install
-----
```
pip3 install py_set
```

Usage
-----
```
>>>from py_set import pyset
>>>rbt = pyset()
>>>
>>>rbt.size()
0
>>>rbt.is_empty()
1
>>>rbt.add("Hello world")
>>>rbt.add(20.15)
>>>rbt.add(6)
>>>
>>>rbt.to_list()
[20.15, 'Hello world', 6]
>>>rbt.remove(6)
>>>rbt.size()
2
>>>del rbt
>>>
>>>rbt = pyset(5, 10, 1)
>>>rbt.to_list()
[5, 6, 7, 8, 9]
>>>
>>>rbt.from_list([1, 2, 3, 4], (10, 11, 12))
>>>rbt.to_list()
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
>>>rbt.find(4)
1
>>>rbt.find("Hello")
0
>>>rbt.clear()
>>>rbt.to_list()
[]
>>>del rbt
```

Comparing with python structures:
-----
```
*** Adding elements ***
List time on adding 10^6 items: 142.03ms
Set time on adding 10^6 items: 168.01ms
Pyset time on adding 10^6 items: 457.31ms

*** Searching for elements ***
Set time on searching in 10^6 items: 178.88ms
Pyset time on searching in 10^6 items: 773.05ms

*** Deleting elements ***
Set time on deleting 10^6 items: 154.70ms
Pyset time on deleting 10^6 items: 348.18ms
```
