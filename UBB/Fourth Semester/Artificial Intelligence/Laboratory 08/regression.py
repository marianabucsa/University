from sklearn import linear_model
from sklearn.metrics import mean_squared_error


class MyRegression:
    def __init__(self):
        self.intercept_ = 0.0
        self.coef_ = []

    def fit(self, x, y, learningRate=0.01, noEpochs=1000):
        self.coef_ = [0.0 for _ in range(len(x[0]) + 1)]  # initialize the coefficients with 0.0

        for epoch in range(noEpochs):
            error = [0.0 for _ in range(len(x[0]) + 1)]

            for i in range(len(x)):  # for each sample from the training data
                y_computed = self.eval(x[i])  # estimate the output
                current_error = y_computed - y[i]  # compute the error for the current sample
                for j in range(len(x[0])):
                    error[j] += current_error * x[i][j]
                error[len(x[0])] += current_error

            for j in range(len(x[0])):  # update the coefficients
                self.coef_[j] = self.coef_[j] - learningRate * error[j] / len(x)

            self.coef_[len(x[0])] = self.coef_[len(x[0])] - learningRate * error[len(x[0])] / len(x)
        self.intercept_ = self.coef_[-1]
        self.coef_ = self.coef_[:-1]

    def eval(self, x):
        yi = self.coef_[-1]
        for j in range(len(x)):
            yi += self.coef_[j] * x[j]
        return yi

    def predict(self, x):
        y_computed = [self.eval(xi) for xi in x]
        return y_computed


def run_tool_univariate_regression(read_information):
    v_train_inputs_list = [[i] for i in read_information.get_train_inputs()]
    epochs = 1000
    regression = linear_model.SGDRegressor()
    for i in range(epochs):
        regression.partial_fit(v_train_inputs_list, read_information.get_train_outputs())

    v_train_outputs_list = [[x] for x in read_information.get_validation_inputs()]
    computed_output = regression.predict(v_train_outputs_list)
    error = mean_squared_error(read_information.get_validation_outputs(), computed_output)
    print('Tool Univariate Regression')
    print('Tool error: ', error)


def run_my_univariate_regression(read_information):
    v_train_inputs_list = [[i] for i in read_information.get_train_inputs()]
    regression = MyRegression()
    regression.fit(v_train_inputs_list, read_information.get_train_outputs())

    v_train_outputs_list = [[x] for x in read_information.get_validation_inputs()]
    computed_output = regression.predict(v_train_outputs_list)
    error = 0.0
    for t1, t2 in zip(computed_output, read_information.get_validation_outputs()):
        error += (t1 - t2) ** 2
    error = error / len(read_information.get_validation_outputs())
    print("My Univariate Regression")
    print('My error: ', error)


def run_tool_multivariate_regression(read_information):
    regression = linear_model.SGDRegressor()
    regression.fit(read_information.get_train_inputs(), read_information.get_train_outputs())

    computed_output = regression.predict(read_information.get_validation_inputs())
    error = mean_squared_error(read_information.get_validation_outputs(), computed_output)
    print("Tool Multivariate regression")
    print('Tool error: ', error)


def run_my_multivariate_regression(read_information):
    regression = MyRegression()
    regression.fit(read_information.get_train_inputs(), read_information.get_train_outputs())

    computed_output = regression.predict(read_information.get_validation_inputs())
    error = 0.0
    for t1, t2 in zip(computed_output, read_information.get_validation_outputs()):
        error += (t1 - t2) ** 2
    error = error / len(read_information.get_validation_outputs())
    print("My Multivariate regression")
    print('My error: ', error)
