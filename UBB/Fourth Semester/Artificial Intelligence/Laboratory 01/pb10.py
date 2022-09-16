# Considerându-se o matrice cu n x m elemente binare (0 sau 1) sortate crescător
# pe linii, să se identifice indexul liniei care conține cele mai multe elemente de 1.
# De ex. în matricea
# [0,0,0,1,1],
# [0,1,1,1,1],
# [0,0,1,1,1]
# a doua linie conține cele mai multe elemente 1.


def read_matrix(mat, nm):
    # reads a matrix from keyboard
    # input: mat - a matrix , nm - an array
    # output: mat and nm contain the read values
    nm.append(int(input("Write n: ")))
    nm.append(int(input("Write m: ")))
    for i in range(nm[0]):
        mat.append([])
        for j in range(nm[1]):
            mat[i].append(int(input("Give number: ")))


def line_max_1(mat, nm):
    # gives the line number that contains the greatest number of 1
    # input: mat - a matrix, nm - an array of integers
    # output: returns the line number that contains the greatest number of 1
    nr_o = nm[1]
    row = -1
    for i in range(nm[0]):
        min_local = 0
        for j in range(nm[1]):
            if mat[i][j] == 0:
                min_local += 1
            else:
                break
        if min_local < nr_o:
            nr_o = min_local
            row = i
    return row + 1


def test_line_max_1():
    # test for line_max_1 function
    assert 2 == line_max_1([[0, 0, 0, 1, 1], [0, 1, 1, 1, 1], [0, 0, 1, 1, 1]], [3, 5])
    assert 4 == line_max_1([[0, 0, 0, 1, 1], [0, 1, 1, 1, 1], [0, 0, 1, 1, 1], [1, 1, 1, 1]], [4, 5])
    assert 1 == line_max_1([[0, 0, 0, 1, 1], [0, 0, 0, 0, 1]], [2, 5])
    print("Test passed ")


def main():
    # main function
    # input: -
    # output: prints the result
    mat = []
    nm = []
    read_matrix(mat, nm)
    print(mat)
    rez = line_max_1(mat, nm)
    print(" Line that has the greatest number of 1: " + str(rez))


test_line_max_1()
main()
