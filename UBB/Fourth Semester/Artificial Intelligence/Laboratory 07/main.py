from regression import run_tool_regression, run_my_regression
from utils import ManageData

# data preparation

read_information = ManageData('data/v3_world-happiness-report-2017.csv', ['Economy..GDP.per.Capita.', 'Freedom'],
                              'Happiness.Score')

# run regression by tool
run_tool_regression(read_information)
# run my regression
run_my_regression(read_information)
