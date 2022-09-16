import numpy as np


class ActivationLayer:
    def __init__(self):
        self.input = None
        self.output = None

    def forward_activation(self):
        self.output = np.tanh(self.input)

    def backward_activation(self):
        return 1 - np.tanh(self.input) ** 2

    # activate
    def forward_propagation(self, input_data):
        self.input = input_data
        self.forward_activation()
        return self.output

    # backward_activate
    def backward_propagation(self, output_error, learning_rate):
        return self.backward_activation() * output_error
