import csv

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

    def read_data_multivariate(self):
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
                if data[i][data_names.index(colon)] == '' or data[i][data_names.index(self.needed_output_colons)] == '':
                    line_with_data_error = True
                else:
                    line.append(float(data[i][data_names.index(colon)]))
            if not line_with_data_error:
                self.input_GPD_freedom.append(line)
                self.output_happiness.append(float(data[i][data_names.index(self.needed_output_colons)]))

    def read_data_univariate(self):
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
            if data[i][data_names.index(self.needed_input_colons)] != '' and data[i][
                data_names.index(self.needed_output_colons)] != '':
                self.input_GPD_freedom.append(float(data[i][data_names.index(self.needed_input_colons)]))
                self.output_happiness.append(float(data[i][data_names.index(self.needed_output_colons)]))

    def split_data(self):
        np.random.seed(6)
        # split the data into train and validation
        indexes = [i for i in range(len(self.input_GPD_freedom))]  # indexes for input data
        train_sample = np.random.choice(indexes, int(0.8 * len(self.input_GPD_freedom)),
                                        replace=False)  # take 80% from that indexes for the trainSample
        validation_sample = [i for i in indexes if not
        i in train_sample]  # take the rest of indexes for validationSample

        self.train_inputs = [self.input_GPD_freedom[i] for i in train_sample]
        # print("Train inputs: ", self.train_inputs)
        self.train_outputs = [self.output_happiness[i] for i in
                              train_sample]
        # print("Train outputs: ", self.train_outputs)
        self.validation_inputs = [self.input_GPD_freedom[i] for i in validation_sample]
        # print("Validation inputs: ", self.validation_inputs)
        self.validation_outputs = [self.output_happiness[i] for i in validation_sample]
        # print("Validation outputs: ", self.validation_outputs)

    def __normalisation_algorithm(self, train_data, validation_data):
        if not isinstance(train_data[0], list):
            train = train_data
        else:
            train = [i[0] for i in train_data]
        if not isinstance(validation_data[0], list):
            validation = validation_data
        else:
            validation = [i[0] for i in validation_data]

        mean_error = sum(train) / len(train)
        std_error = np.sqrt((1 / len(train) * sum([(x - mean_error) ** 2 for x in train])))
        normalised_train = [(x - mean_error) / std_error for x in train]
        normalised_validation = [(x - mean_error) / std_error for x in validation]

        if not isinstance(train_data[0], list):
            normalised_train_data = normalised_train
            normalised_validation_data = normalised_validation
        else:
            if(len(train_data[0]) == 2):
                train = [i[1] for i in train_data]
                validation = [i[1] for i in validation_data]
                mean_error = sum(train) / len(train)
                std_error = np.sqrt((1 / len(train) * sum([(x - mean_error) ** 2 for x in train])))
                normalised_train_2 = [(x - mean_error) / std_error for x in train]
                normalised_validation_2 = [(x - mean_error) / std_error for x in validation]
                normalised_train_data = [[e1, e2] for e1, e2 in zip(normalised_train, normalised_train_2)]
                normalised_validation_data = [[e1, e2] for e1, e2 in zip(normalised_validation, normalised_validation_2)]
            else:
                normalised_train_data = [[e] for e in normalised_train]
                normalised_validation_data = [[e] for e in normalised_validation]

        return normalised_train_data, normalised_validation_data

    def normalise_data(self):
        self.train_inputs, self.validation_inputs = self.__normalisation_algorithm(self.train_inputs,
                                                                                   self.validation_inputs)
        self.train_outputs, self.validation_outputs = self.__normalisation_algorithm(self.train_outputs,
                                                                                     self.validation_outputs)


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
