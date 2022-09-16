import numpy as np
import pandas
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.model_selection import train_test_split


class DataManagement:
    def __init__(self, filename):
        self.filename = filename
        self.x = []
        self.y = []
        self.train_inputs = []
        self.train_outputs = []
        self.test_inputs = []
        self.test_outputs = []
        self.read_data(self.filename)
        self.change_to_binary_labels()
        self.change_data_format()

    def read_data(self, filename):
        data = pandas.read_csv(filename)
        self.x = data['Text']
        self.y = data['Sentiment']

    def change_to_binary_labels(self):
        y = []
        for output in self.y:
            if output == 'positive':
                y.append(0)
            else:
                y.append(1)
        self.y = y

    def change_data_format(self):
        train_inputs, test_inputs, train_outputs, test_outputs = train_test_split(self.x, self.y,
                                                                                  test_size=0.30,
                                                                                  random_state=123,
                                                                                  shuffle=True)
        vectorizer = CountVectorizer()
        train_inputs = vectorizer.fit_transform(train_inputs)
        test_inputs = vectorizer.transform(test_inputs)
        train_inputs = [list(train_inputs.toarray()[i]) for i in range(len(train_inputs.toarray()))]
        test_inputs = [list(test_inputs.toarray()[i]) for i in range(len(test_inputs.toarray()))]
        self.train_inputs = np.array(train_inputs)
        self.test_inputs = np.array(test_inputs)
        self.train_outputs = np.array(train_outputs)
        self.test_outputs = np.array(test_outputs)
