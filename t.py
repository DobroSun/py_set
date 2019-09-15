import pyset

bst = pyset.BST()
print(bst)
ne = pyset.BST()
print(ne)
print(ne is bst)

print(bst)
print(bst.size())
ne.add(3)
print(ne.size())
bst.add("lo")
