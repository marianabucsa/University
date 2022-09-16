from glob import glob

import cv2
import numpy as np
from PIL import Image
from sklearn.datasets import load_iris
from sklearn.preprocessing import StandardScaler


# liniarizeaza matricea de pixeli
def flatten(mat):
    x = []
    for line in mat:
        for el in line:
            x.append(el)
    return x


class ReadDataSepia:
    def __init__(self):
        self.train_inputs = []
        self.train_outputs = []
        self.validation_inputs = []
        self.validation_outputs = []
        self.inputs = []
        self.outputs = []
        self.manage_data()

    def read_data(self):
        images = glob('Images/**/*.jpg', recursive=True)
        for i in range(len(images)):
            image = Image.open(images[i])
            image_matrix = np.array(image)
            image_matrix = cv2.resize(image_matrix, (10, 10))
            self.inputs.append(image_matrix)
            if images[i].find('sepia') != -1:
                self.outputs.append(0)
            else:
                self.outputs.append(1)


    def split_data(self):
        np.random.seed(5)
        indexes = [i for i in range(len(self.inputs))]
        train_sample = np.random.choice(indexes, int(0.8 * len(self.inputs)), replace=False)
        test_sample = [i for i in indexes if not i in train_sample]

        self.train_inputs = [self.inputs[i] for i in train_sample]
        self.train_outputs = [self.outputs[i] for i in train_sample]
        self.validation_inputs = [self.inputs[i] for i in test_sample]
        self.validation_outputs = [self.outputs[i] for i in test_sample]

    def normalisation(self):
        scaler = StandardScaler()
        if not isinstance(self.train_inputs[0], list):
            # encode each sample into a list
            train_data = [[d] for d in self.train_inputs]
            validation_data = [[d] for d in self.validation_inputs]

            scaler.fit(train_data)  # fit only on training data
            self.train_inputs = scaler.transform(train_data)  # apply same transformation to train data
            self.validation_inputs = scaler.transform(validation_data)  # apply same transformation to test data

            # decode from list to raw values
            self.train_inputs = [el[0] for el in self.train_inputs]
            self.validation_inputs = [el[0] for el in self.validation_inputs]
        else:
            scaler.fit(self.train_inputs)  # fit only on training data
            self.train_inputs = scaler.transform(self.train_inputs)  # apply same transformation to train data
            self.validation_inputs = scaler.transform(self.validation_inputs)  # apply transformation to test data

    def manage_data(self):
        self.read_data()
        self.split_data()
        self.train_inputs = [flatten(flatten(el)) for el in self.train_inputs]
        self.validation_inputs = [flatten(flatten(el)) for el in self.validation_inputs]
        self.normalisation()

