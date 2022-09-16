import numpy
from sklearn import neural_network
from sklearn.metrics import accuracy_score
from sklearn.model_selection import train_test_split

from utils import DataManagement


def run_classification_emoji():
    data = DataManagement()
    data.read_emojis_iteration_1()
    train_input, test_input, train_output, test_output = train_test_split(numpy.array(data.input),
                                                                          numpy.array(data.output), test_size=0.20,
                                                                          random_state=42, shuffle=True)
    classifier = neural_network.MLPClassifier(solver='adam', hidden_layer_sizes=(1, 64), activation='relu',
                                              max_iter=500)
    classifier.fit(train_input, train_output)
    computed_output = classifier.predict(test_input)
    print("Emoji accuracy: ", accuracy_score(test_output, computed_output))
