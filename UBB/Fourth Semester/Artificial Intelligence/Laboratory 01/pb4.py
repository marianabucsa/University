# Să se determine cuvintele unui text care apar exact o singură dată în acel text.
# De ex. cuvintele care apar o singură dată în ”ana are ana are mere rosii ana" sunt:
# 'mere' și 'rosii'.

def read_text():
    # reads a text from keyboard
    # input: -
    # output: returns the text that was read
    return input("Write text: ")


def one_time_words(text):
    # gives the words that appear only one time in the text
    # input: text - string
    # output: returns an array of strings which represent the words that appear only one time in the text
    words = text.split(" ")
    word_apparition = {}
    for w in words:
        if w not in word_apparition:
            word_apparition[w] = 1
        else:
            word_apparition[w] += 1
    rez = []
    for key in word_apparition:
        if word_apparition[key] == 1:
            rez.append(key)
    return rez


def main():
    # main function
    # input: -
    # output: prints the result
    text = read_text()
    rez = one_time_words(text)
    print(rez)


def test_last_word_alphabetically():
    # test for last_word_alphabetically
    assert ["ana"] == one_time_words("ana are are")
    assert ["ana", "mere"] == one_time_words("ana are are mere")
    assert ["mere", "rosii"] == one_time_words("ana are ana are mere rosii ana")
    assert [""] == one_time_words("")
    print("Test passed ")


test_last_word_alphabetically()
main()
