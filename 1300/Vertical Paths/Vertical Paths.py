cases = int(input(''))

problems = []

for i in range(0, cases):
    num_nodes = int(input(''))
    nodes = input('').split(' ')
    problems.append((num_nodes, nodes))

def dfs(curr, visited, ht, path):
    if ht[curr] == []:
        visited.append(curr)
        path.insert(0, curr)
        return visited, path
    else:
        visited, path = dfs(ht[curr][0], visited, ht, path)
        visited.append(curr)
        path.insert(0, curr)
        return visited, path



for num, nodes in problems:
    root = None
    ht = {}
    for i in range(0, num):
        if int(nodes[i])-1 == i:
            root = nodes[i]
        ht[str(i+1)] = []

    for node_ind in range(0, num):
        if nodes[node_ind] == str(node_ind+1):
            continue
        ht[nodes[node_ind]].append(str(node_ind+1))

    order = []
    visited = []
    paths = 0
    actual_paths = []

    queue = []
    queue.append(root)
    while bool(queue) == True:
        curr = queue.pop()
        order.append(curr)
        for i in ht[curr]:
            queue.append(i)

    for node in order:
        if node not in visited:
            unpack = dfs(node, visited, ht, [])
            visited = unpack[0]
            actual_paths.append(unpack[1])
            paths += 1

    print(paths)
    for a_path in actual_paths:
        print(len(a_path))
        print(' '.join(a_path))
    


    