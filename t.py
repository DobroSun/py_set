from py_set import pyset

rbt = pyset()
rbt.add("Hello world")
rbt.add(20.15)
rbt.add(6)
print(rbt.to_list())
del rbt
rbt = pyset(0.5, 10, 1.5)
for i in rbt:
    print(i)
