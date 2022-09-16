import numpy as np
from keras.datasets import mnist
from keras.utils import np_utils

from layers.ActivationLayer import ActivationLayer
from layers.FCLayer import FCLayer


class Loss:
    def __init__(self):
        self.given_output = []
        self.computed_output = []

    def forward_loss(self, given_output, computed_output):
        self.given_output = given_output
        self.computed_output = computed_output
        return np.mean(np.power(self.given_output - self.computed_output, 2))

    def backward_loss(self, given_output, computed_output):
        self.given_output = given_output
        self.computed_output = computed_output
        return 2 * (self.computed_output - self.given_output) / self.given_output.size


class Network:
    def __init__(self, layers, loss):
        self.layers = layers
        self.loss = loss

    # predict output for given input
    def predict(self, input_data):
        # sample dimension first
        samples = len(input_data)
        result = []

        # run network over all samples
        for i in range(samples):
            # forward propagation
            output = input_data[i]
            for layer in self.layers:
                output = layer.forward_propagation(output)
            result.append(output)
        return result

    # train the network
    def fit(self, train_input, train_output, no_epochs=35, learning_rate=0.01):
        # training loop
        for i in range(no_epochs):
            err = 0
            for j in range(len(train_input)):
                # forward propagation
                output = train_input[j]
                for layer in self.layers:
                    output = layer.forward_propagation(output)

                # compute loss (for display purpose only)
                err += self.loss.forward_loss(train_output[j], output)

                # backward propagation
                error = self.loss.backward_loss(train_output[j], output)
                for layer in reversed(self.layers):
                    error = layer.backward_propagation(error, learning_rate)

            # calculate average error on all samples
            err /= len(train_input)
            print('Epoch: %d/%d  -> Error=%f' % (i + 1, no_epochs, err))


def get_network_layers():
    layer1 = FCLayer(28 * 28, 100)
    layer2 = ActivationLayer()
    layer3 = FCLayer(100, 50)
    layer4 = ActivationLayer()
    layer5 = FCLayer(50, 10)
    layer6 = ActivationLayer()
    return [layer1, layer2, layer3, layer4, layer5, layer6]


def run_my_ann():
    # load data
    (train_input, train_output), (test_input, test_output) = mnist.load_data()

    # reshape and normalize input data
    train_input = train_input.reshape(train_input.shape[0], 1, 28 * 28)
    train_input = train_input.astype('float32')
    train_input /= 255

    test_input = test_input.reshape(test_input.shape[0], 1, 28 * 28)
    test_input = test_input.astype('float32')
    test_input /= 255

    # encode output which is a number in range [0,9] into a vector of size 10
    train_output = np_utils.to_categorical(train_output)
    test_output = np_utils.to_categorical(test_output)

    # Network
    network_layers = get_network_layers()
    net = Network(network_layers, Loss())

    net.fit(train_input[0:1000], train_output[0:1000])

    # test on 10 samples
    out = net.predict(test_input[0:10])
    computed_output = []
    for element in out:
        for el in element:
            computed_output.append(el)

    print("\n")
    for i in range(10):
        print("Predicted value: " + str(computed_output[i]))
        print("True value: " + str(test_output[i]))
        print('\n')


run_my_ann()
