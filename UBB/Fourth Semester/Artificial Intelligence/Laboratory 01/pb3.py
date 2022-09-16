# Să se determine produsul scalar a doi vectori rari care conțin numere reale.
# Un vector este rar atunci când conține multe elemente nule.
# Vectorii pot avea oricâte dimensiuni. De ex. produsul scalar a 2 vectori unisimensionali [1,0,2,0,3]
# și  [1,2,0,3,1] este 4.

def read_arrays(x, y):
    # reads the numbers of the arrays
    # input: x ,y arrays of float
    # output: x, y contain the read values
    n = int(input("Give the number of elements in X: "))
    for i in range(n):
        x.append(float(input("Give element in X: ")))
    n = int(input("Give the number of elements in Y: "))
    for i in range(n):
        y.append(float(input("Give element in Y: ")))


def scalar_product(x, y):
    # calculates the scalar product of two arrays
    # input: x,y arrays of float
    # output: returns the scalar product of arrays x and y
    n = min(len(x), len(y))
    rez = 0
    for i in range(n):
        if x[i] != 0 and y[i] != 0:
            rez = rez + (x[i] * y[i])
    return rez


def test_scalar_product():
    # tests scalar_product function
    assert 32 == scalar_product([1, 2, 3], [4, 5, 6])
    assert 4 == scalar_product([1, 0, 2, 0, 3], [1, 2, 0, 3, 1])
    assert 0 == scalar_product([1, 0], [0, 1])
    assert 0 == scalar_product([1, 0], [0, 1, 3, 4])
    print("Test passed ")


def main():
    # main function
    # input: -
    # output: prints the result
    x = []
    y = []
    read_arrays(x, y)
    rez = scalar_product(x, y)
    print("Scalar product of x and y: " + str(rez))


test_scalar_product()
main()
