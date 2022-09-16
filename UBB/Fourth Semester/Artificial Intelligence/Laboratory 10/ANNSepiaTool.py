import numpy
from sklearn import neural_network
from sklearn.metrics import confusion_matrix
# Ignore the warnings
import warnings
warnings.filterwarnings("ignore")
from utils import ReadDataSepia


def eval_nn(real_labels, computed_labels, label_names):
    conf_matrix = confusion_matrix(real_labels, computed_labels)
    accuracy = sum([conf_matrix[i][i] for i in range(len(label_names))]) / len(real_labels)
    precision = {}
    recall = {}
    for i in range(len(label_names)):
        precision[label_names[i]] = conf_matrix[i][i] / sum([conf_matrix[j][i] for j in range(len(label_names))])
        recall[label_names[i]] = conf_matrix[i][i] / sum([conf_matrix[i][j] for j in range(len(label_names))])
    return accuracy, precision, recall


def run_tool_ANN():
    data = ReadDataSepia()
    classifier = neural_network.MLPClassifier(hidden_layer_sizes=(25,), activation='relu', max_iter=200, solver='adam',
                                              verbose=10, random_state=1, learning_rate_init=.01)
    classifier.fit(data.train_inputs, data.train_outputs)
    computed_outputs = classifier.predict(data.validation_inputs)
    accuracy, precision, recall = eval_nn(numpy.array(data.validation_outputs), computed_outputs, ['nofilter', 'sepia'])
    print('Accuracy ANNSepiaTool: ', accuracy)
    print('Precision ANNSepiaTool: ', precision)
    print('Recall ANNSepiaTool: ', recall)


run_tool_ANN()