from clasificare_multi_clasa import multi_class_classification, loss_multi_class_classification_cross_entropy, \
    loss_binary_class_classification_cross_entropy, loss_multi_label_classification_cross_entropy
from regresie_multi_target import multi_target_regression

multi_target_regression()
print("\n")
print("MULTI CLASS CLASSIFICATION")
multi_class_classification()
print("\n")
computed_outputs_daisy = [[0.6, 0.4],
                          [0.7, 0.3],
                          [0.2, 0.7],
                          [0.7, 0.3],
                          [0.2, 0.8],
                          [0.3, 0.7],
                          [0.1, 0.9],
                          [0.6, 0.4],
                          [0.2, 0.8],
                          [0.1, 0.9],
                          [0.1, 0.9],
                          [0.3, 0.7],
                          [0.3, 0.7],
                          [0.9, 0.1],
                          [0.3, 0.7],
                          [0.2, 0.8],
                          [0.7, 0.3],
                          [0.6, 0.4],
                          [0.6, 0.4],
                          [0.3, 0.7],
                          [0.2, 0.8],
                          [0.7, 0.3],
                          [0.1, 0.9],
                          [0.2, 0.8],
                          [0.6, 0.4],
                          [0.7, 0.3]]

computed_outputs_tulip = [[0.2, 0.8],
                          [0.4, 0.6],
                          [0.6, 0.4],
                          [0.2, 0.8],
                          [0.1, 0.9],
                          [0.6, 0.4],
                          [0.1, 0.9],
                          [0.2, 0.8],
                          [0.1, 0.9],
                          [0.8, 0.2],
                          [0.6, 0.4],
                          [0.2, 0.8],
                          [0.6, 0.4],
                          [0.05, 0.95],
                          [0.6, 0.4],
                          [0.3, 0.7],
                          [0.1, 0.9],
                          [0.2, 0.8],
                          [0.3, 0.7],
                          [0.3, 0.7],
                          [0.1, 0.9],
                          [0.1, 0.9],
                          [0.7, 0.3],
                          [0.3, 0.7],
                          [0.1, 0.9],
                          [0.3, 0.7]]
computed_outputs_rose = [[0.3, 0.7],
                         [0.1, 0.9],
                         [0.3, 0.7],
                         [0.1, 0.9],
                         [0.7, 0.3],
                         [0.1, 0.9],
                         [0.8, 0.2],
                         [0.3, 0.7],
                         [0.7, 0.3],
                         [0.1, 0.9],
                         [0.3, 0.7],
                         [0.6, 0.4],
                         [0.1, 0.9],
                         [0.05, 0.95],
                         [0.3, 0.7],
                         [0.6, 0.4],
                         [0.2, 0.8],
                         [0.3, 0.7],
                         [0.2, 0.8],
                         [0.6, 0.4],
                         [0.7, 0.3],
                         [0.2, 0.8],
                         [0.2, 0.8],
                         [0.6, 0.4],
                         [0.3, 0.7],
                         [0.2, 0.8]]
print("Loss binary class classification: ",
      loss_binary_class_classification_cross_entropy('daisy', computed_outputs_daisy))
print("\n")
print("Loss multi class classification: ", loss_multi_class_classification_cross_entropy())
print("\n")
print("Loss multi label classification: ", loss_multi_label_classification_cross_entropy())