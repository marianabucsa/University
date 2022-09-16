# Considerându-se o matrice cu n x m elemente întregi și o listă cu perechi
# formate din coordonatele a 2 căsuțe din matrice ((p,q) și (r,s)),
# să se calculeze suma elementelor din sub-matricile identificate de fiecare pereche.
# De ex, pt matricea
# [0, 2, 5, 4, 1],
# [4, 8, 2, 3, 7],
# [6, 3, 4, 6, 2],
# [7, 3, 1, 8, 3],
# [1, 5, 7, 9, 4]]
# și lista de perechi ((1, 1) și (3, 3)), ((2, 2) și (4, 4)), suma elementelor din prima sub-matrice este 38, iar suma elementelor din a 2-a sub-matrice este 44.


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


def read_pairs(mat):
    # read the pairs for the sub-matrices
    # input: mat- a matrix
    # output: a matrix of the pairs for the sub-matrices
    n = int(input("Give number of pairs: "))
    for i in range(n):
        print("Enter the pair coordinates: ")
        x = int(input("Give coordinate for the first position: "))
        y = int(input("Give coordinate for the first position: "))
        z = int(input("Give coordinate for the second position: "))
        t = int(input("Give coordinate for the second position: "))
        mat.append([x, y, z, t])
    return n


def get_sum_for_pair(pair, mat):
    # calculates the sum for the sub-matrix defined by the pair
    # input: pair an array, mat - a matrix
    # output: returns the sum of the numbers in the sub-matrix
    sum = 0
    for i in range(pair[0], pair[2] + 1):
        for j in range(pair[1], pair[3] + 1):
            sum += mat[i][j]
    return sum


def get_sum_pairs(mat, pairs, n):
    # gives the sum of the numbers in the sub-matrices defined by the pairs
    # input: mat - matrix, pairs - matrix, n -integer
    # output: an array of the sum for each pair
    rez = []
    for i in range(n):
        rez.append(get_sum_for_pair(pairs[i], mat))
    return rez


def main():
    # main function
    # input: -
    # output: prints the result
    mat = []
    nm = []
    read_matrix(mat, nm)
    print(mat)
    pairs = []
    n = read_pairs(pairs)
    rez = get_sum_pairs(mat, pairs, n)
    for i in range(n):
        print("For pair " + str(pairs[i]) + "the sum is : " + str(rez[i]))


def test_get_sum_for_pair():
    # tests get_sum_for_pair function
    mat = [[0, 2, 5, 4, 1], [4, 8, 2, 3, 7], [6, 3, 4, 6, 2], [7, 3, 1, 8, 3], [1, 5, 7, 9, 4]]
    assert 14 == get_sum_for_pair([0, 0, 1, 1], mat)
    assert 24 == get_sum_for_pair([3, 3, 4, 4], mat)
    assert 0 == get_sum_for_pair([0, 0, 0, 0], mat)
    print("Test passed")


def test_get_sum_pairs():
    # test get_sum_pairs function
    mat = [[0, 2, 5, 4, 1], [4, 8, 2, 3, 7], [6, 3, 4, 6, 2], [7, 3, 1, 8, 3], [1, 5, 7, 9, 4]]
    pairs = [[1, 1, 3, 3], [2, 2, 4, 4]]
    assert [38, 44] == get_sum_pairs(mat, pairs, 2)
    pairs = [[0, 0, 1, 1], [3, 3, 4, 4]]
    assert [14, 24] == get_sum_pairs(mat, pairs, 2)
    print("Test passed")


test_get_sum_for_pair()
test_get_sum_pairs()
main()
