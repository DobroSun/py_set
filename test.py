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

    def test_get_size(self):
        self.assertEqual(pyset.BST().size(), 0)

    def test_add(self):
        bst = pyset.BST()
        try:
            bst.add(3.0)
        except:
            self.fail()

if __name__ == "__main__":
    unittest.main()
