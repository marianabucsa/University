# Pentru un șir cu n numere întregi care conține și duplicate, să se determine
# elementul majoritar (care apare de mai mult de n / 2 ori).
# De ex. 2 este elementul majoritar în șirul [2,8,7,2,2,5,2,3,1,2,2].

def read_numbers(x):
    # reads numbers from the keyboard
    # input: x array of integers
    # output: x  contain the read values
    n = int(input("Give the number of elements in X: "))
    for i in range(n):
        x.append(int(input("Give element in X: ")))


def majority_apparitions_number(numbers):
    # gives the number that has the majority of apparitions or raises exception if it does not exist
    # input: numbers - array of integers
    # output: returns the number that has the majority of apparitions or raises exception if it does not exist
    number_apparition = {}
    for nr in numbers:
        if nr not in number_apparition:
            number_apparition[nr] = 1
        else:
            number_apparition[nr] += 1
    rez = 0
    found = 0
    for key in number_apparition:
        if number_apparition[key] > (len(numbers) / 2):
            rez = key
            found = 1
    if found == 0:
        raise Exception("A majority number does not exist!")
    return int(rez)


def main():
    # main function
    # input: -
    # output: prints the result
    x = []
    read_numbers(x)
    try:
        rez = majority_apparitions_number(x)
        print("The majority apparitions number : " + str(rez))
    except Exception as e:
        print(str(e))


def test_majority_apparitions_number():
    # test for majority_apparitions_number function
    assert 2 == majority_apparitions_number([2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2])
    assert 3 == majority_apparitions_number([1, 3, 3, 3, 2])
    try:
        majority_apparitions_number([1, 2, 3, 4])
        assert False
    except Exception as e:
        assert (str(e) == "A majority number does not exist!")
    print("Test passed ")


test_majority_apparitions_number()
main()
