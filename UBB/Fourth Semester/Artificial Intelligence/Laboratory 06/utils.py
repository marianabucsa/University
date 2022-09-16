import csv


def read_csv(filename):
    file = open("data/" + filename)
    file_input = csv.reader(file)
    real_outputs = []
    computed_outputs = []
    if filename == "flowers.csv":
        for row in file_input:
            var1 = row[:1][0]
            var2 = row[1:][0]
            real_outputs.append(var1)
            computed_outputs.append(var2)
    else:
        if filename == "sports.csv":
            for row in file_input:
                var1 = row[:3]
                var2 = row[3:]
                real_outputs.append(var1)
                computed_outputs.append(var2)
    file.close()
    real_outputs.pop(0)
    computed_outputs.pop(0)
    return real_outputs, computed_outputs

