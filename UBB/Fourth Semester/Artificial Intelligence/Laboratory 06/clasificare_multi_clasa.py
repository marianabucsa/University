import math

from utils import read_csv


def eval_multi_class(real_labels, computed_labels, label_names):
    acc = sum([1 if real_labels[i] == computed_labels[i] else 0 for i in range(0, len(real_labels))]) / len(real_labels)
    TP = {}
    FP = {}
    TN = {}
    FN = {}
    for label in label_names:
        TP[label] = sum(
            [1 if (real_labels[i] == label and computed_labels[i] == label) else 0 for i in range(len(real_labels))]
        )
        FP[label] = sum(
            [1 if (real_labels[i] != label and computed_labels[i] == label) else 0 for i in range(len(real_labels))])
        TN[label] = sum(
            [1 if (real_labels[i] != label and computed_labels[i] != label) else 0 for i in range(len(real_labels))])
        FN[label] = sum(
            [1 if (real_labels[i] == label and computed_labels[i] != label) else 0 for i in range(len(real_labels))])

    precision = {}
    recall = {}

    for label in label_names:
        precision[label] = TP[label] / (TP[label] + FP[label])
        recall[label] = TP[label] / (TP[label] + FN[label])

    return acc, precision, recall


def multi_class_classification():
    real_outputs, computed_outputs = read_csv("flowers.csv")
    acc, prec, recall = eval_multi_class(real_outputs, computed_outputs, list(set(real_outputs)))
    print('Accuracy: ', acc)
    print("\n")
    print('Precision')
    for i in prec:
        print(str(i) + ":", prec[i])
    print("\n")
    print('Rappel')
    for i in recall:
        print(str(i) + ":", recall[i])


def loss_binary_class_classification_cross_entropy(name, computed_outputs):
    real_labels, computed_labels = read_csv("flowers.csv")
    # [a Daisy,not a Daisy]

    real_outputs = [[1, 0] if label == 'name' else [0, 1] for label in real_labels]
    dataset_size = len(real_labels)
    no_classes = 2
    dataset_ce = 0.0
    for i in range(dataset_size):
        sample_ce = - sum([real_outputs[i][j] * math.log(computed_outputs[i][j]) for j in range(no_classes)])
        dataset_ce += sample_ce
    mean_ce = dataset_ce / dataset_size
    return mean_ce


def loss_multi_class_classification_cross_entropy():
    real_labels, computed_labels = read_csv("flowers.csv")
    computed_outputs = [[0.2, 0.3, 0.5],
                        [0.4, 0.1, 0.5],
                        [0.5, 0.3, 0.2],
                        [0.2, 0.1, 0.7],
                        [0.1, 0.7, 0.2],
                        [0.6, 0.1, 0.3],
                        [0.1, 0.8, 0.1],
                        [0.2, 0.3, 0.5],
                        [0.1, 0.7, 0.2],
                        [0.8, 0.1, 0.1],
                        [0.6, 0.3, 0.1],
                        [0.2, 0.5, 0.3],
                        [0.6, 0.1, 0.3],
                        [0.05, 0.05, 0.9],
                        [0.4, 0.3, 0.3],
                        [0.3, 0.5, 0.2],
                        [0.1, 0.2, 0.7],
                        [0.2, 0.3, 0.5],
                        [0.3, 0.2, 0.5],
                        [0.3, 0.4, 0.3],
                        [0.1, 0.7, 0.2],
                        [0.1, 0.2, 0.7],
                        [0.7, 0.2, 0.1],
                        [0.3, 0.5, 0.2],
                        [0.1, 0.3, 0.6],
                        [0.3, 0.2, 0.5]]
    real_outputs = []
    for label in real_labels:
        if label == 'Tulip':
            real_outputs.append([1, 0, 0])
        else:
            if label == 'Rose':
                real_outputs.append([0, 1, 0])
            else:
                real_outputs.append([0, 0, 1])
    dataset_size = len(real_labels)
    no_classes = len(set(real_labels))
    dataset_ce = 0.0
    for i in range(dataset_size):
        sample_ce = - sum([real_outputs[i][j] * math.log(computed_outputs[i][j]) for j in range(no_classes)])
        dataset_ce += sample_ce
    mean_ce = dataset_ce / dataset_size
    return mean_ce


def loss_multi_label_classification_cross_entropy():
    real_labels, computed_labels = read_csv("flowers.csv")
    computed_outputs = [[0.6, 0.3, 0.5],
                        [0.4, 0.7, 0.5],
                        [0.5, 0.3, 0.2],
                        [0.3, 0.1, 0.7],
                        [0.9, 0.7, 0.2],
                        [0.6, 0.1, 0.3],
                        [0.1, 0.8, 0.1],
                        [0.2, 0.3, 0.5],
                        [0.1, 0.7, 0.2],
                        [0.8, 0.5, 0.1],
                        [0.6, 0.3, 0.1],
                        [0.2, 0.5, 0.3],
                        [0.6, 0.7, 0.3],
                        [0.2, 0.3, 0.9],
                        [0.4, 0.9, 0.3],
                        [0.3, 0.5, 0.2],
                        [0.1, 0.2, 0.7],
                        [0.2, 0.3, 0.5],
                        [0.3, 0.2, 0.5],
                        [0.6, 0.2, 0.3],
                        [0.1, 0.7, 0.2],
                        [0.1, 0.7, 0.7],
                        [0.7, 0.2, 0.1],
                        [0.8, 0.2, 0.2],
                        [0.1, 0.7, 0.6],
                        [0.4, 0.2, 0.5]]
    real_outputs = []
    for i in range(len(real_labels)):
        if (real_labels[i] == 'Tulip' and computed_labels[i] == 'Rose') or (
                computed_labels[i] == 'Tulip' and real_labels[i] == 'Rose'):
            real_outputs.append([1, 1, 0])
        if (real_labels[i] == 'Tulip' and computed_labels[i] == 'Daisy') or (
                computed_labels[i] == 'Tulip' and real_labels[i] == 'Daisy'):
            real_outputs.append([1, 0, 1])
        if (real_labels[i] == 'Rose' and computed_labels[i] == 'Daisy') or (
                computed_labels[i] == 'Rose' and real_labels[i] == 'Daisy'):
            real_outputs.append([0, 1, 1])
        if real_labels[i] == 'Rose' and computed_labels[i] == 'Rose':
            real_outputs.append([0, 1, 0])
        if real_labels[i] == 'Daisy' and computed_labels[i] == 'Daisy':
            real_outputs.append([0, 0, 1])
        if real_labels[i] == 'Tulip' and computed_labels[i] == 'Tulip':
            real_outputs.append([1, 0, 0])
    dataset_size = len(real_labels)
    no_classes = len(set(real_labels))
    dataset_ce = 0.0
    for i in range(dataset_size):
        sample_ce = - sum([real_outputs[i][j] * math.log(computed_outputs[i][j]) for j in range(no_classes)])
        dataset_ce += sample_ce
    return dataset_ce/dataset_size
