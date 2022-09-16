from regression import run_tool_regression, run_my_regression
from utils import ManageData

read_information = ManageData()
#read_information.plot_read_data()
read_information.split_data()
run_tool_regression(read_information)
run_my_regression(read_information)
