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

    def test_delete(self):
        bst = pyset.BST()
        try:
            del bst
            with self.assertRaises(UnboundLocalError):
                bst.add("Hello world")
        except:
            self.fail()

    def test_add(self):
        bst = pyset.BST()
        try:
            bst.add(3.0)
            bst.add(7)
            bst.add("lol")
            self.assertEqual(bst.size(), 3)
            with self.assertRaises(TypeError):
                bst.add(3, 40)
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

    def test_max_size(self):
        bst = pyset.BST(50.4)
        try:
            bst.max_size()
        except:
            self.fail()

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

    def test_to_list(self):
        bst = pyset.BST()
        bst.add(48)
        bst.add(38.4)
        self.assertEqual(bst.to_list(), [38.4, 48])

    def test_range_constructor(self):
        bst = pyset.BST(10)
        self.assertEqual(bst.to_list(), list(range(10)))
        al = pyset.BST(2, 10)
        self.assertEqual(al.to_list(), list(range(2, 10)))
        ls = pyset.BST(10, 4, -1)
        self.assertEqual(ls.to_list(), list(sorted(range(10, 4, -1))))

    def test_iterations(self):
        expected = []
        bst = pyset.BST()
        for i in range(1, 100):
            bst.add(i)

        for i in bst:
            expected.append(i)
        self.assertEqual(bst.to_list(), expected)

    def test_clear(self):
        bst = pyset.BST(4, 100, 10)
        bst.clear()
        self.assertEqual(bst.to_list(), [])

    def test_from_list(self):
        bst = pyset.BST()
        ex = list(range(200))
        lo = list(range(400, 50000))
        ex.extend(lo)
        bst.from_list(ex, lo)
        self.assertEqual(bst.to_list(), ex)

    def test_in_pyset(self):
        bst = pyset.BST(10)
        res = int(3 in bst)
        self.assertEqual(res, 1)


if __name__ == "__main__":
    unittest.main()
