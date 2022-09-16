def read_network(file_path):
    # read the network details
    # input: file_name  os path
    # output: returns network - nx graph
    f = open(file_path, "r")
    net = {}
    n = int(f.readline())
    net['noCities'] = n
    mat = []
    for i in range(n):
        mat.append([])
        line = f.readline()
        elems = line.split(",")
        for j in range(n):
            if i == j:
                mat[-1].append(0)
            else:
                mat[-1].append(int(elems[j]))
    net["mat"] = mat
    start = int(f.readline())
    net["startCity"] = start;
    end = int(f.readline())
    net["endCity"] = end;
    f.close()
    return net
