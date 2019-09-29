# Pyset
[![Build Status](https://travis-ci.com/DobroSun/py_set.svg?branch=master)](https://travis-ci.com/DobroSun/py_set)

PySet is wrapper of C++ standart red-black tree realization(std::set)

Usage
-----
```
>>>rbt = pyset()\n
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
>>>
>>>del rbt
>>>
>>>rbt = pyset(5, 10, 1)
>>>rbt.to_list()
[5, 6, 7, 8, 9]

```
