# Să se genereze toate numerele (în reprezentare binară) cuprinse între 1 și n.
# De ex. dacă n = 4, numerele sunt: 1, 10, 11, 100.

def read_number():
    # reads a number from keyboard
    # input: -
    # output: returns the number that was read
    return int(input("Enter n: "))


def convert_from_base_10(nr):
    # convert a number form base 10 to base 2
    # input: nr- integer
    # output: rez- a string that represents the conversion in that base of the number
    digits = "01"
    rez = ""
    nr = int(nr)
    while nr:
        rez += digits[nr % 2]
        nr //= 2
    return rez[::-1]


def binary_numbers(n):
    # gives the numbers between 1 and n in binary format
    # input: n- integer
    # output: a list of all the numbers between 1 and n in binary format
    rez = []
    for i in range(1, n + 1):
        rez.append(convert_from_base_10(i))
    return rez


def test_binary_numbers():
    # test for binary_numbers function
    assert ["1", "10", "11", "100"] == binary_numbers(4)
    assert ["1"] == binary_numbers(1)
    assert ["1", "10", "11", "100", "101"] == binary_numbers(5)
    print("Test passed")


def test_convert_from_base_10():
    # test for convert_from_base_10
    assert "1" == convert_from_base_10(1)
    assert "10" == convert_from_base_10(2)
    assert "1000" == convert_from_base_10(8)
    print("Test passed")


def main():
    # main function
    # input: -
    # output: prints the result
    n = read_number()
    rez = binary_numbers(n)
    print("Numbers from 1 to n in base 2:")
    print(rez)


test_convert_from_base_10()
test_binary_numbers()
main()
