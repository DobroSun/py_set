#!/usr/bin/env python3

import unittest

class TestSet(unittest.TestCase):
    def test_import(self):
        try:
            import pyset
        except ImportError:
            self.fail()
        else:
            pass 
          

if __name__ == "__main__":
    unittest.main()
