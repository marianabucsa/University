# Pentru un șir cu n elemente care conține valori din mulțimea {1, 2, ..., n - 1}
# astfel încât o singură valoare se repetă de două ori, să se identifice
# acea valoare care se repetă. De ex. în șirul [1,2,3,4,2] valoarea 2 apare de două ori.

def read_numbers(x):
    # reads numbers from the keyboard
    # input: x array of integers
    # output: x  contain the read values
    n = int(input("Give the number of elements in X: "))
    for i in range(n):
        x.append(int(input("Give element in X: ")))


def two_apparitions_number(numbers):
    # gives the number that appears two times in x
    # input: x - array of integers
    # output: returns the number that appears two times in the array
    number_apparition = {}
    for nr in numbers:
        if nr not in number_apparition:
            number_apparition[nr] = 1
        else:
            number_apparition[nr] += 1
    for key in number_apparition:
        if number_apparition[key] == 2:
            return key


def test_two_apparitions_number():
    # tests two_apparitions_number function
    assert 2 == two_apparitions_number([1, 2, 3, 2])
    assert 3 == two_apparitions_number([1, 2, 3, 3])
    assert 2 == two_apparitions_number([1, 2, 3, 4, 2])
    print("Test passed ")


def main():
    # main function
    # input: -
    # output: prints the result
    x = []
    read_numbers(x)
    rez = two_apparitions_number(x)
    print("The number that appears two times : " + str(rez))


test_two_apparitions_number()
main()
