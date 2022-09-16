from math import sqrt

from utils import read_csv


def multi_target_regression_mae():
    real_outputs, computed_outputs = read_csv("sports.csv")
    error_predict = 0
    for i in range(len(real_outputs)):
        sum = 0
        for j in range(len(real_outputs[i])):
            dif = abs(int(real_outputs[i][j]) - int(computed_outputs[i][j]))
            sum = sum + dif
        error_predict = error_predict + sum / len(real_outputs[i])

    mae = error_predict / len(real_outputs)
    return mae


def multi_target_regression_rmse():
    real_outputs, computed_outputs = read_csv("sports.csv")
    error_predict = 0
    for i in range(len(real_outputs)):
        sum = 0
        for j in range(len(real_outputs[i])):
            dif = pow(int(real_outputs[i][j]) - int(computed_outputs[i][j]), 2)
            sum = sum + dif
        error_predict = error_predict + sum / len(real_outputs[i])

    rmse = sqrt(error_predict / len(real_outputs))
    return rmse


def multi_target_regression():
    print("MULTI TARGET REGRESSION")
    print("Mean Absolut Error: ", multi_target_regression_mae())
    print("Root Mean Square Error: ", multi_target_regression_rmse())
