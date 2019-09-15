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


    def test_is_empty(self):
        bst = pyset.BST()
        self.assertEqual(bst.is_empty(), 1)
        bst.add(3)
        self.assertEqual(bst.is_empty(), 0)

    def test_size(self):
        bst = pyset.BST()
        self.assertEqual(bst.size(), 0)

        new_bst = pyset.BST()
        new_bst.add(43)

        self.assertEqual(bst.size(), 0)
        self.assertEqual(new_bst.size(), 1)


if __name__ == "__main__":
    unittest.main()
