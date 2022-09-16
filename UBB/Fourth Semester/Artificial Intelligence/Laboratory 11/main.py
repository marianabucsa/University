from sklearn.metrics import accuracy_score

from KMeans import K_Means
from MyRegression import MyRegression
from SemiSupervised import run_semi_supervised
from utils import DataManagement

print("---Bag of Words---")
data1 = DataManagement("data.txt")
data2 = DataManagement("data.txt")
data3 = DataManagement("data.txt")

print("Supervised:")


def run_my_regression(info):
    classifier = MyRegression()
    classifier.fit(info.train_inputs, info.train_outputs)
    computed_output = classifier.predict(info.test_inputs)
    accuracy = accuracy_score(info.test_outputs, computed_output)
    print("MyRegression accuracy: ", accuracy)
    return accuracy


run_my_regression(data1)
print('\n')
print("Semi-supervised:")

run_semi_supervised(data2)
print('\n')
print("Unsupervised:")


def run_k_means(info):
    k_means = K_Means(info)
    k_means.calculate_means()
    k_means.obtain_clusters()
    computed_output = [0 for _ in range(len(info.test_inputs))]
    for cluster in k_means.clusters:
        for el in cluster:
            computed_output[el] = k_means.clusters.index(cluster)
    print("KMeans accuracy: ", accuracy_score(info.test_outputs, computed_output))


run_k_means(data3)
