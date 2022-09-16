import math

import numpy as np
from sklearn import linear_model
from sklearn.metrics import accuracy_score


def sigmoid(z):
    return 1.0 / (1.0 + np.exp(0.0 - z))


class MyRegression:
    def __init__(self):
        self.intercept_ = []
        self.coef_ = []
        self.losses = []

    def loss(self, input, output):
        no_data = len(input)
        total_cost = 0.0
        for i in range(len(input)):
            example = input[i]
            predicted_value = sigmoid(self.eval(example))
            real_label = output[i]
            class1_cost = real_label * math.log(predicted_value)
            if predicted_value == 1:
                class2_cost = 1 - real_label
            else:
                class2_cost = (1 - real_label) * math.log(1 - predicted_value)
            crt_cost = - class1_cost - class2_cost
            total_cost += crt_cost
        return total_cost / no_data

    def fit(self, x, y, learningRate=0.01, noEpochs=1000):
        for element in list(set(y)):
            self.coef_.append([0.0 for _ in range(len(x[0]) + 1)])
            y_current = [0 for _ in range(len(y))]
            for i in range(len(y)):
                if y[i] == element:
                    y_current[i] = 1
            for epoch in range(noEpochs):
                # error = [0.0 for _ in range(len(x[0]) + 1)]
                for i in range(len(x)):
                    y_computed = sigmoid(self.eval2(x[i], self.coef_[element]))
                    error_current = y_computed - y_current[i]
                    for j in range(len(x[i])):
                        self.coef_[element][j + 1] = self.coef_[element][j + 1] - learningRate * x[i][j] * error_current
                    self.coef_[element][0] = self.coef_[element][0] - learningRate * error_current
                    '''
                    for j in range(len(x[0])):
                        error[j] += error_current * x[i][j]
                    error[len(x[0])] += error_current'''
                '''for j in range(len(x[0])):
                    self.coef_[element][j + 1] = self.coef_[element][j + 1] - learningRate * error[j] / len(x)
                self.coef_[element][0] = self.coef_[element][0] - learningRate * error[len(x[0])] / len(x)
                '''

        self.intercept_ = [intercept[0] for intercept in self.coef_]
        self.coef_ = [coef[1:] for coef in self.coef_]

    def eval(self, x):
        yi = self.coef_[-1]
        for j in range(len(x)):
            yi += self.coef_[j] * x[j]
        return yi

    def eval2(self, xi, coef):
        yi = coef[0]
        for j in range(len(xi)):
            yi += coef[j + 1] * xi[j]
        return yi

    def predict_one_sample(self, sampleFeatures):
        threshold = 0.5
        rez = []
        for i in range(len(self.coef_)):
            coefficients = [self.intercept_[i]] + [c for c in self.coef_[i]]
            computedFloatValue = self.eval2(sampleFeatures, coefficients)
            computed01Value = sigmoid(computedFloatValue)
            rez.append(computed01Value)
        return np.argmax(rez)

    def predict(self, x):
        y_computed = [self.predict_one_sample(xi) for xi in x]
        return y_computed


def run_tool_regression(read_information):
    classifier = linear_model.LogisticRegression(max_iter=2000)
    classifier.fit(read_information.train_inputs, read_information.train_outputs)
    computed_outputs = classifier.predict(read_information.test_inputs)
    print('Tool Regression')
    print('Tool accuracy: ' + str(accuracy_score(read_information.test_outputs, computed_outputs) * 100) + "%")
    error = 1 - accuracy_score(read_information.test_outputs, computed_outputs)
    print('Tool error: ', error)


def run_my_regression(read_information):
    classifier = MyRegression()
    # read_information.normalise_data()
    read_information.cross_validation()
    # read_information.plot_classification_data()
    classifier.fit(read_information.train_inputs, read_information.train_outputs)
    computed_outputs = classifier.predict(read_information.test_inputs)
    read_information.plot_predictions(computed_outputs,read_information.test_outputs,read_information.outputs_names)
    # accuracy = accuracy_score(read_information.test_outputs, computed_outputs)
    noMatches = 0
    for i in range(len(computed_outputs)):
        if computed_outputs[i] == read_information.test_outputs[i]:
            noMatches += 1
    accuracy = (noMatches / len(computed_outputs)) * 100
    error = 0.0
    for i in range(0, len(computed_outputs)):
        error += abs(computed_outputs[i] - read_information.test_outputs[i])
    error /= len(computed_outputs)
    print("My Regression")
    print('Ny accuracy: ' + str(accuracy) + '%')
    print('My error: ', error)
    print('\n')
    # print('My losses: ', classifier.losses)
