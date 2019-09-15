import pyset

ne = pyset.BST()
bst = pyset.BST()
print(bst.find(34))
print(bst)
print(ne)
print(ne is bst)

ne.add(30)
bst.add(30)
print(bst)
print(bst.size())
print(ne.size())
print(bst.size())
