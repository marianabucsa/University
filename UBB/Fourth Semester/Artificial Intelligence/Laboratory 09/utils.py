import matplotlib.pyplot as plt
import numpy as np
from sklearn.datasets import load_iris


class ManageData:
    def __init__(self):
        data = load_iris()
        inputs = data['data']
        self.outputs = data['target']
        self.outputs_names = data['target_names']
        feature_names = list(data['feature_names'])
        self.feature1 = [feat[feature_names.index('sepal length (cm)')] for feat in inputs]
        self.feature2 = [feat[feature_names.index('sepal width (cm)')] for feat in inputs]
        self.feature3 = [feat[feature_names.index('petal length (cm)')] for feat in inputs]
        self.feature4 = [feat[feature_names.index('petal width (cm)')] for feat in inputs]
        self.inputs = [[feat[feature_names.index('sepal length (cm)')], feat[feature_names.index('sepal width (cm)')],
                        feat[feature_names.index('petal length (cm)')], feat[feature_names.index('petal width (cm)')]]
                       for feat in
                       inputs]
        self.train_inputs = []
        self.train_outputs = []
        self.test_inputs = []
        self.test_outputs = []
        self.feature1train = []
        self.feature2train = []
        self.feature3train = []
        self.feature4train = []
        self.feature1test = []
        self.feature2test = []
        self.feature3test = []
        self.feature4test = []

    def plot_read_data(self):
        labels = set(self.outputs)
        no_data = len(self.inputs)
        for crt_label in labels:
            x = [self.feature2[i] * self.feature1[i] for i in range(no_data) if self.outputs[i] == crt_label]
            y = [self.feature4[i] * self.feature3[i] for i in range(no_data) if self.outputs[i] == crt_label]
            plt.scatter(x, y, label=self.outputs_names[crt_label])
        plt.legend()
        plt.show()

    def split_data(self):
        np.random.seed(5)
        indexes = [i for i in range(len(self.inputs))]
        train_sample = np.random.choice(indexes, int(0.8 * len(self.inputs)), replace=False)
        test_sample = [i for i in indexes if not i in train_sample]

        self.train_inputs = [self.inputs[i] for i in train_sample]
        self.train_outputs = [self.outputs[i] for i in train_sample]
        self.test_inputs = [self.inputs[i] for i in test_sample]
        self.test_outputs = [self.outputs[i] for i in test_sample]

    def dataset_minmax(self, dataset):
        minmax = list()
        for i in range(len(dataset[0])):
            col_values = [row[i] for row in dataset]
            value_min = min(col_values)
            value_max = max(col_values)
            minmax.append([value_min, value_max])
        return minmax

    def normalize_dataset(self, dataset, minmax):
        for row in dataset:
            for i in range(len(row)):
                row[i] = (row[i] - minmax[i][0]) / (minmax[i][1] - minmax[i][0])
        return dataset

    def normalise_data(self):
        minmax = self.dataset_minmax(self.train_inputs)
        self.train_inputs = self.normalize_dataset(self.train_inputs, minmax)
        minmax = self.dataset_minmax(self.test_inputs)
        self.test_inputs = self.normalize_dataset(self.test_inputs, minmax)

    def cross_validation(self):
        permutation = np.random.permutation(len(self.inputs))
        input_perm = []
        output_perm = []
        for i in permutation:
            input_perm.append(self.inputs[i])
            output_perm.append(self.outputs[i])
        n = len(self.inputs) // 3
        for i in range(3):
            train_inputs = []
            train_outputs = []
            test_inputs = []
            test_outputs = []
            for j in range(0, n * i):
                train_inputs.append(input_perm[j])
                train_outputs.append(output_perm[j])
            for j in range(n * (i + 1), len(self.inputs)):
                train_inputs.append(input_perm[j])
                train_outputs.append(input_perm[j])
            for v in range(n * i, n * (i + 1)):
                test_inputs.append(input_perm[v])
                test_outputs.append(output_perm[v])
        self.train_inputs = train_inputs
        self.test_inputs = test_inputs
        self.train_outputs = train_outputs
        self.test_outputs = test_outputs

    def plot_classification_data(self):
        feature1train = [ex[0] for ex in self.train_inputs]
        feature2train = [ex[1] for ex in self.train_inputs]
        feature3train = [ex[2] for ex in self.train_inputs]
        feature4train = [ex[3] for ex in self.train_inputs]
        labels = set(self.train_outputs)
        noData = len(feature1train)
        for crtLabel in labels:
            x = [feature1train[i] * feature2train[i] for i in range(noData) if self.train_outputs[i] == crtLabel]
            y = [feature3train[i] * feature4train[i] for i in range(noData) if self.train_outputs[i] == crtLabel]
            plt.scatter(x, y, label=self.outputs_names[crtLabel])
        plt.legend()
        plt.title("Normalized train data")
        plt.show()

    def plot_predictions(self, realOutputs, computedOutputs,
                        labelNames):
        feature1test = [ex[0] for ex in self.test_inputs]
        feature2test = [ex[1] for ex in self.test_inputs]
        feature3test = [ex[2] for ex in self.test_inputs]
        feature4test = [ex[3] for ex in self.test_inputs]
        labels = list(set(self.outputs))
        noData = len(feature1test)
        for crtLabel in labels:
            x = [feature1test[i]*feature2test[i] for i in range(noData) if realOutputs[i] == crtLabel and computedOutputs[i] == crtLabel]
            y = [feature3test[i]*feature4test[i] for i in range(noData) if realOutputs[i] == crtLabel and computedOutputs[i] == crtLabel]
            plt.scatter(x, y, label=labelNames[crtLabel] + ' (correct)')
        for crtLabel in labels:
            x = [feature1test[i]*feature2test[i]  for i in range(noData) if realOutputs[i] == crtLabel and computedOutputs[i] != crtLabel]
            y = [feature3test[i]*feature4test[i]for i in range(noData) if realOutputs[i] == crtLabel and computedOutputs[i] != crtLabel]
            plt.scatter(x, y, label=labelNames[crtLabel] + ' (incorrect)')
        plt.legend()
        plt.title('Solution')
        plt.show()
