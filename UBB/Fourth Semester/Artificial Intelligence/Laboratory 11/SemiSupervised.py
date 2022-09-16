import numpy
from sklearn.metrics import accuracy_score
from sklearn.semi_supervised import LabelPropagation


def run_semi_supervised(data):
    label_prop_model = LabelPropagation(kernel='knn', n_neighbors=5, max_iter=200)
    rng = numpy.random.RandomState(42)
    random_unlabeled_points = rng.rand(len(data.train_outputs)) < 0.3
    labels = numpy.copy(data.train_outputs)
    labels[random_unlabeled_points] = -1
    label_prop_model.fit(data.train_inputs, labels)
    computed_outputs = label_prop_model.predict(data.test_inputs)
    print("Semi-supervised accuracy:", accuracy_score(data.test_outputs, computed_outputs))
