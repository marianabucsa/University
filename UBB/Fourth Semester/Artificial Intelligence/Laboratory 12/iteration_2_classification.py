from fer import FER
from sklearn.metrics import accuracy_score

from utils import DataManagement


def run_classification_emotions():
    data = DataManagement()
    computed_output = []
    detector = FER()
    for el in data.test_input:
        emotion, score = detector.top_emotion(el)
        if emotion == 'angry':
            computed_output.append(0)
        if emotion == 'disgust':
            computed_output.append(1)
        if emotion == 'fear':
            computed_output.append(2)
        if emotion == 'happy':
            computed_output.append(3)
        if emotion == 'sad':
            computed_output.append(4)
        if emotion == 'surprise':
            computed_output.append(5)
        if emotion == 'neutral':
            computed_output.append(6)
    print("Accuracy:", accuracy_score(data.test_output, computed_output))