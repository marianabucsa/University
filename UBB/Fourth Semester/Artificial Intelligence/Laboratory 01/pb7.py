# Să se determine al k-lea cel mai mare element al unui șir de numere cu n elemente (k < n).
# De ex. al 2-lea cel mai mare element din șirul [7,4,6,3,9,1] este 7.

def read_numbers(x):
    # reads numbers from the keyboard
    # input: x array of integers
    # output: x  contain the read values
    n = int(input("Give the number of elements in X: "))
    for i in range(n):
        x.append(int(input("Give element in X: ")))
    return int(input("Give K: "))


def k_biggest_number(numbers, k):
    # gives the k biggest number in the array
    # input: numbers - an array on float
    # output: returns the k biggest number in the array - float
    numbers = sorted(numbers, reverse=True)
    return numbers[k - 1]


def test_k_biggest_number():
    # test for k_biggest_number function
    assert 4 == k_biggest_number([5, 6, 4, 3], 3)
    assert 5 == k_biggest_number([5, 6, 4, 3, 1, 98], 3)
    assert 6 == k_biggest_number([5, 6, 4, 3, 1, 98], 2)
    assert 5 == k_biggest_number([5], 1)
    print("Test passed")


def main():
    # main function
    # input: -
    # output: prints the result
    x = []
    k = read_numbers(x)
    rez = k_biggest_number(x, k)
    print("The k biggest number " + str(rez))


test_k_biggest_number()
main()
