from regression import run_tool_univariate_regression, run_my_univariate_regression, run_tool_multivariate_regression, \
    run_my_multivariate_regression
from utils import ManageData

read_information = ManageData('data/v3_world-happiness-report-2017.csv', 'Economy..GDP.per.Capita.',
                              'Happiness.Score')
read_information.read_data_univariate()
read_information.split_data()
run_tool_univariate_regression(read_information)
print()
run_my_univariate_regression(read_information)
print("-------------------------------------------------------------------------------------------------------")
read_information = ManageData('data/v3_world-happiness-report-2017.csv', ['Economy..GDP.per.Capita.', 'Freedom'],
                              'Happiness.Score')
read_information.read_data_multivariate()
read_information.split_data()
read_information.normalise_data()
run_tool_multivariate_regression(read_information)
print()
run_my_multivariate_regression(read_information)
