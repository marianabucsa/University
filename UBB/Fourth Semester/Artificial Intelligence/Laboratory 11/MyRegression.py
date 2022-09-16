from math import exp

import numpy as np


def sigmoid(x):
    return 1 / (1 + exp(-x))


class MyRegression:
    def __init__(self):
        self.intercept_ = 0.0
        self.coef_ = []

    def fit(self, x, y, learningRate=0.1, noEpochs=100):
        self.coef_ = [0.0 for _ in range(len(x[0]))]  # beta or w coefficients y = w0 + w1 * x1 + w2 * x2 + ...
        for epoch in range(noEpochs):
            # print(epoch)
            errors = []
            for i in range(len(x)):  # for each sample from the training data
                y_computed = sigmoid(self.eval(x[i]))  # estimate the output
                current_error = y_computed - y[i]  # compute the error for the current sample
                errors.append(current_error)  # append the error to the errors array
            # add up the errors
            sum_error = np.sum(errors)
            for j in range(len(x[0])):  # update the coefficients
                sum_coefficient = 0.0  # for each coefficient define sum
                # for each sample add the element on the j column multiplied by the error of the sample
                for i in range(len(x)):
                    sum_coefficient = sum_coefficient + x[i][j] * errors[i]
                self.coef_[j] = self.coef_[j] - learningRate * sum_coefficient  # update the coefficients
            self.intercept_ = self.intercept_ - learningRate * sum_error  # update the intercept

    def eval(self, xi):
        yi = self.intercept_
        for j in range(len(xi)):
            yi += self.coef_[j] * xi[j]
        return yi

    def predict_one_sample(self, sample_features, threshhold):
        computed_float_value = self.eval(sample_features)
        computed_value = sigmoid(computed_float_value)
        if computed_value < threshhold:
            return 0
        else:
            return 1

    def predict(self, inTest):
        computed_labels = [self.predict_one_sample(sample, threshhold=0.45) for sample in inTest]
        return computed_labels



