import sys

def dfs(graph, start):
    visited = []
    stack = [start]

    while stack:
        n = stack.pop()
        if n not in visited:
            visited.append(n)
            tmp = list(set(graph[n]) - set(visited))
            tmp.sort(reverse = True)
            stack += tmp
    return visited

n, start = map(int, input().split())
graph = {}

for line in sys.stdin:
    a = int(line[0])
    b = int(line[2])
    graph.setdefault(a, [])
    graph.setdefault(b, [])
    graph[a].append(b)
    graph[b].append(a)

result = dfs(graph, start)
for i in result:
    print(i, end = ' ')
print("")