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
            bst = pyset.BST(4)
        except Exception:
            self.fail("Can't create an instance of BST")
    
    @unittest.expectedFailure
    def test_get_size(self):
        self.assertEqual(pyset.BST().size(), 0)

    @unittest.expectedFailure
    def test_add(self):
        bst = pyset.BST()
        try:
            bst.add(3)
            print(bst.size())
        except:
            self.fail()

if __name__ == "__main__":
    unittest.main()
