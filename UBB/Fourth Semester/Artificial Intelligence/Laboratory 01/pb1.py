# Să se determine ultimul (din punct de vedere alfabetic) cuvânt care poate apărea într-un
# text care conține mai multe cuvinte separate prin ” ” (spațiu).
# De ex. ultimul (dpdv alfabetic) cuvânt din ”Ana are mere rosii si galbene” este cuvântul "si".

def read_text():
    # reads a text from keyboard
    # input: -
    # output: returns the text that was read
    return input("Write text: ")

def last_word_alphabetically(text):
    # gives the last word from a text alphabetically
    # input: text - a string
    # output: return the last word from a text alphabetically
    words=text.split(" ")
    word = words[0]
    for w in words:
        if w > word:
            word = w
    return word


def main():
    # main function
    # input: -
    # output: prints the result
    text = read_text()
    rez = last_word_alphabetically(text)
    print(rez)

def test_last_word_alphabetically():
    # test for last_word_alphabetically
    assert "" == last_word_alphabetically("")
    assert "are" == last_word_alphabetically("ana are")
    assert "mere" ==  last_word_alphabetically("ana are mere")
    assert "si" == last_word_alphabetically("ana are si mere")
    print("Test passed ")


test_last_word_alphabetically()
main()