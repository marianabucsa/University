from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

from utils import MatrixOperations, plot_results


class MyRegression:
    def __init__(self):
        self.fit_result = []

    def fit(self, train_inputs, train_outputs):
        matrix_operations = MatrixOperations()

        tr = matrix_operations.transpose(train_inputs)
        # first step
        first_mat = matrix_operations.multiply(matrix_operations.transpose(train_inputs), train_inputs)

        # second step
        second_mat = matrix_operations.multiply(matrix_operations.reverse(first_mat),
                                                matrix_operations.transpose(train_inputs))

        # third step
        self.fit_result = matrix_operations.multiply(second_mat, train_outputs)

    def predict(self, inputs):
        return sum([inputs[i] * self.fit_result[i + 1][0] for i in range(len(inputs))]) + self.fit_result[0][0]


def run_tool_regression(read_information):
    regression = LinearRegression()

    # train the model
    regression.fit(read_information.get_train_inputs(), read_information.get_train_outputs())

    # use the train model to predict new outputs
    vi = read_information.get_validation_inputs()
    validation_inputs = [[regression.intercept_] + vi[i] for i in range(len(vi))]
    tool_validation_outputs = regression.predict(validation_inputs)

    # calculate error
    error = mean_squared_error(read_information.get_validation_outputs(), tool_validation_outputs)
    print('Error detected by tool: ', error)


def run_my_regression(read_information):
    regression = MyRegression()

    # train the model
    regression.fit(read_information.get_train_inputs(), read_information.get_train_outputs_matrix_format())

    # use the train model to predict new outputs
    vi = read_information.get_validation_inputs()
    my_regression_validation_outputs = [regression.predict(inp) for inp in vi]

    err = 0
    for t1, t2 in zip(my_regression_validation_outputs, read_information.get_validation_outputs()):
        err += (t1 - t2) ** 2
    error = err / len(read_information.get_validation_outputs())
    print('Error detected by my regression: ', error)
    plot_results(regression, read_information.get_train_inputs(), read_information.get_train_outputs_matrix_format(),
                 read_information.get_validation_inputs(), my_regression_validation_outputs)
