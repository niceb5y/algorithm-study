import sys
n, start = map(int, input().split())
l = [[] for _ in range(n + 1)]
visited = [True] * (n + 1)

for line in sys.stdin:
    a = int(line[0])
    b = int(line[2])
    l[a].append([b, True])
    l[b].append([a, True])

for i in l:
    i.sort()
stack = [start]
while stack:
    v = stack[len(stack) - 1]
    if visited[v]:
        print(v, end = ' ')
    visited[v] = False
    for i, tmp in enumerate(l[v]):
        a, b = tmp
        if b == True and a not in stack:
            stack.append(a)
            l[v][i] = (a, False)
            for j, k in enumerate(l[a]):
                x, y = k
                if x == v:
                    l[a][j] = (v, False)
                    break
            break
    
        if i == len(l[v]) - 1:
            stack.pop()