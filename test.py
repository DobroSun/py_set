#!/usr/bin/env python3

import unittest
import pyset

class TestSet(unittest.TestCase):
    def test_import(self):
        try:
            import pyset
        except ImportError:
            self.fail()

    def test_creating_instance(self):
        try:
            bst = pyset.BST()
        except Exception:
            self.fail("Can't create an instance of BST")

    def test_add(self):
        bst = pyset.BST()
        try:
            bst.add(3.0)
            bst.add(7)
            bst.add("lol")
            self.assertEqual(bst.size(), 3)
        except:
            self.fail()

    def test_find(self):
        bst = pyset.BST()
        bst.add("lol")
        self.assertEqual(bst.find("lol"), 1)
        self.assertEqual(bst.find(38450), 0)


    def test_is_empty(self):
        bst = pyset.BST()
        self.assertEqual(bst.is_empty(), 1)
        bst.add(3)

        self.assertEqual(bst.is_empty(), 0)

    def test_size(self):
        bst = pyset.BST()
        self.assertEqual(bst.size(), 0)
        for i in range(10):
            bst.add(i)
        self.assertEqual(bst.size(), 10)

    def test_several_instances(self):
        try:
            bst = pyset.BST()
            nw = pyset.BST()
            ny = pyset.BST()
            bst.add(4)
            nw.add(6.84)
            ny.add("Hello world")
        except:
            self.fail()

    def test_range_constructor(self):
        try:
            # Have to check (10, 4, -1) too
            bst = pyset.BST(10)
            al = pyset.BST(2, 10)
            ls = pyset.BST(1, 4, 1)
        except:
            self.fail()

    def test_to_list(self):
        bst = pyset.BST()
        bst.add(48)
        self.assertEqual(bst.to_list(), [48])

if __name__ == "__main__":
    unittest.main()
