import unittest

from sortari.Sortari import selection_sort, shake_sort


class TestSortari(unittest.TestCase):

    def test_selection_sort(self):
        lista = [3, 4, 2, 1]
        selection_sort(lista)
        self.assertEqual(lista[0], 1)
        self.assertEqual(lista[1], 2)
        self.assertEqual(lista[2], 3)
        self.assertEqual(lista[3], 4)
        selection_sort(lista, reversed=True)
        self.assertEqual(lista[0], 4)
        self.assertEqual(lista[1], 3)
        self.assertEqual(lista[2], 2)
        self.assertEqual(lista[3], 1)

    def test_shake_sort(self):
        lista = [3, 4, 2, 1]
        shake_sort(lista)
        self.assertEqual(lista[0], 1)
        self.assertEqual(lista[1], 2)
        self.assertEqual(lista[2], 3)
        self.assertEqual(lista[3], 4)
        shake_sort(lista, reversed=True)
        self.assertEqual(lista[0], 4)
        self.assertEqual(lista[1], 3)
        self.assertEqual(lista[2], 2)
        self.assertEqual(lista[3], 1)

if __name__ == '__main__':
    unittest.main()