import csv
from copy import deepcopy

import matplotlib.pyplot as plt
import numpy as np


class ManageData:
    def __init__(self, path_to_file, needed_input_colons, needed_output_colons):
        self.path_to_file = path_to_file
        self.needed_input_colons = needed_input_colons
        self.needed_output_colons = needed_output_colons
        self.input_GPD_freedom = []
        self.output_happiness = []
        self.train_outputs_matrix_format = []
        self.train_inputs = []
        self.train_outputs = []
        self.train_outputs_matrix_format = []
        self.validation_inputs = []
        self.validation_outputs = []

        # data processing
        self.read_data()
        self.split_data()

    def get_path_to_file(self):
        return self.path_to_file

    def get_needed_input_colons(self):
        return self.needed_input_colons

    def get_needed_output_colons(self):
        return self.needed_output_colons

    def get_input_GPD_freedom(self):
        return self.input_GPD_freedom

    def get_output_happiness(self):
        return self.output_happiness

    def get_train_inputs(self):
        return self.train_inputs

    def get_train_outputs(self):
        return self.train_outputs

    def get_train_outputs_matrix_format(self):
        return self.train_outputs_matrix_format

    def get_validation_inputs(self):
        return self.validation_inputs

    def get_validation_outputs(self):
        return self.validation_outputs

    def read_data(self):
        data = []
        data_names = []
        with open(self.path_to_file) as csv_file:
            csv_reader = csv.reader(csv_file, delimiter=',')
            line_count = 0
            for row in csv_reader:
                if line_count == 0:
                    data_names = row
                else:
                    data.append(row)
                line_count += 1

        for i in range(len(data)):
            line_with_data_error = False
            line = []
            for colon in self.needed_input_colons:
                if data[i][data_names.index(colon)] == '':
                    line_with_data_error = True
                else:
                    line.append(float(data[i][data_names.index(colon)]))
            if not line_with_data_error:
                self.input_GPD_freedom.append(line)

        for i in range(len(data)):
            self.output_happiness.append(float(data[i][data_names.index(self.needed_output_colons)]))

    def split_data(self):
        np.random.seed(6)
        # split the data into train and validation
        indexes = [i for i in range(len(self.input_GPD_freedom))]  # indexes for input data
        train_sample = np.random.choice(indexes, int(0.8 * len(self.input_GPD_freedom)),
                                        replace=False)  # take 80% from that indexes for the trainSample
        validation_sample = [i for i in indexes if not
        i in train_sample]  # take the rest of indexes for validationSample

        self.train_inputs = [[1] + self.input_GPD_freedom[i] for i in
                             train_sample]
        # print("Train inputs: ", self.train_inputs)
        self.train_outputs = [self.output_happiness[i] for i in
                              train_sample]
        self.train_outputs_matrix_format = [[self.output_happiness[i]] for i in
                                            train_sample]
        # print("Train outputs: ", self.train_outputs)
        self.validation_inputs = [self.input_GPD_freedom[i] for i in validation_sample]
        # print("Validation inputs: ", self.validation_inputs)
        self.validation_outputs = [self.output_happiness[i] for i in validation_sample]
        # print("Validation outputs: ", self.validation_outputs)


class MatrixOperations:
    def multiply(self, mat1, mat2):
        result = [[0 for _ in range(len(mat2[0]))] for _ in range(len(mat1))]
        for i in range(len(mat1)):
            for j in range(len(mat2[0])):
                for k in range(len(mat1[0])):
                    result[i][j] += mat1[i][k] * mat2[k][j]
        return result

    def transpose(self, mat):
        transpose = []
        for i in range(len(mat[0])):
            line = []
            for j in range(len(mat)):
                line.append(mat[j][i])
            transpose.append(line)
        return transpose

    def determinant(self, mat):
        for i in mat:
            if len(i) != len(mat):
                print('Cannot calculate determinant')
                return None
        if len(mat) == 1:
            return mat[0][0]
        else:
            if len(mat) == 2:
                return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0]
            else:
                result = 0
                for j in range(len(mat)):
                    nr = (-1) ** j * mat[0][j] * self.determinant(self.remove_row_colomn(mat, 0, j))
                    result += nr
                return result

    def remove_row_colomn(self, mat, row, column):
        smat = deepcopy(mat)
        smat.remove(mat[row])
        for i in range(len(smat)):
            smat[i].remove(smat[i][column])
        return smat

    def reverse(self, mat):
        adjacency = self.adjacency(mat)
        determinant = self.determinant(mat)
        return [[adjacency[i][j] / determinant for j in range(len(adjacency[0]))] for i in range(len(mat))]

    def adjacency(self, mat):
        adjacency = []
        for i in range(len(mat)):
            row = []
            for j in range(len(mat[0])):
                minor = (-1) ** (i + j) * self.determinant(self.remove_row_colomn(mat, i, j))
                row.append(minor)
            adjacency.append(row)
        return self.transpose(adjacency)


def plot_3D(regression, inputs, ax, val):
    ax.set_xlabel("GDP")
    ax.set_ylabel("Freedom")
    ax.set_zlabel("Happiness")

    if val == 'train':
        x = np.arange(min([inputs[i][1] for i in range(len(inputs))]),
                      max([inputs[i][1] for i in range(len(inputs))]), 0.01)

        y = np.arange(min([inputs[i][2] for i in range(len(inputs))]),
                      max([inputs[i][2] for i in range(len(inputs))]), 0.1)
    else:
        x = np.arange(min([inputs[i][0] for i in range(len(inputs))]),
                      max([inputs[i][1] for i in range(len(inputs))]), 0.01)

        y = np.arange(min([inputs[i][0] for i in range(len(inputs))]),
                      max([inputs[i][1] for i in range(len(inputs))]), 0.1)

    x, y = np.meshgrid(x, y)

    z = [regression.predict([d1, d2]) for d1, d2 in zip(x, y)]
    z = np.array(z)

    ax.plot_surface(x, y, z.reshape(x.shape), alpha=0.7)
    plt.show()


def plot_results(regression, train_inputs, train_outputs, validation_input, validation_output):
    fig1 = plt.figure()
    ax_train = fig1.add_subplot(111, projection='3d')
    ax_train.scatter([train_inputs[i][1] for i in range(len(train_inputs))],
                     [train_inputs[i][2] for i in range(len(train_inputs))],
                     train_outputs, marker='.', color='green')
    plot_3D(regression, train_inputs, ax_train, 'train')
    fig2 = plt.figure()
    ax_validation = fig2.add_subplot(111, projection='3d')
    ax_validation.scatter([validation_input[i][0] for i in range(len(validation_input))],
                          [validation_input[i][1] for i in range(len(validation_input))],
                          validation_output, marker='.', color='red')
    plot_3D(regression, train_inputs, ax_validation, 'train')
