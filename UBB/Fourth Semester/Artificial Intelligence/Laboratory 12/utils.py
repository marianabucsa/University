import os
from glob import glob

import cv2
import numpy
from PIL import Image


class DataManagement:
    def __init__(self):
        self.input = []
        self.output = []
        self.test_input = []
        self.test_output = []

    def read_emojis_iteration_1(self):
        images_folder = glob('data_iteration1/**/*.jpg', recursive=True)
        for i in images_folder:
            img = Image.open(i)
            img_matrix = numpy.array(img)
            img_matrix = cv2.resize(img_matrix, (32, 32))
            img_matrix = img_matrix.reshape((1, 4 * 32 * 32))
            if i.find('positive') != -1:
                self.output.append(1)
            else:
                self.output.append(0)
            self.input.append(img_matrix[0])

    def read_faces_iteration_2(self):
        images_folder = glob('data_iteration2/**/*.png', recursive=True)
        for i in images_folder:
            img = cv2.imread(i)
            img = cv2.resize(img, (96, 96))
            directory = os.path.dirname(os.path.realpath(i)).split('\\')[-1]
            if directory == "anger":
                self.test_output.append(0)
            elif directory == "disgust":
                self.test_output.append(1)
            elif directory == "fear":
                self.test_output.append(2)
            elif directory == "happy":
                self.test_output.append(3)
            elif directory == "sadness":
                self.test_output.append(4)
            elif directory == "surprise":
                self.test_output.append(5)
            else:
                print("Error in reading faces!")
            self.test_input.append(img)
