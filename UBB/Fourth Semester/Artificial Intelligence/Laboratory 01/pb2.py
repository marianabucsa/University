# Să se determine distanța Euclideană între două locații identificate prin perechi de numere.
# De ex. distanța între (1,5) și (4,1) este 5.0
from math import sqrt


def read_points(A, B):
    # reads the coordinates for the points
    # input: A, B - array of float
    # output: the values in A and B are the ones that where read
    A[0] = float(input("Give x coordinate for A: "))
    A[1] = float(input("Give y coordinate for A: "))
    B[0] = float(input("Give x coordinate for B: "))
    B[1] = float(input("Give y coordinate for B: "))


def euclidean_distance(xA, yA, xB, yB):
    # calculates the euclidean distance for the given coordinates
    # input: xA, yA, xB, yB - float
    # output: returns the euclidean distance for the given coordinates
    return sqrt(((xA - xB) * (xA - xB)) + ((yA - yB) * (yA - yB)))


def test_euclidean_distance():
    # test for euclidean distance
    assert 2 == euclidean_distance(0, 0, 0, 2)
    assert 2 * sqrt(2) == euclidean_distance(0, 0, 2, 2)
    assert 0 == euclidean_distance(0, 0, 0, 0)
    assert 2 == euclidean_distance(0, -1, 0, -3)
    print("Test passed ")


def main():
    # main function
    # input: -
    # output: prints the result
    A = [0, 0]
    B = [0, 0]
    read_points(A, B)
    dist = euclidean_distance(A[0], A[1], B[0], B[1])
    print("Distance" + str(dist))


test_euclidean_distance()
main()
