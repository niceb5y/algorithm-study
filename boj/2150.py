from collections import defaultdict
from sys import setrecursionlimit as SRL
import heapq
import sys
SRL(150000)
input = sys.stdin.readline

stack = []
global scc, graph, r_graph, visited

def dfs(v):
    visited[v] = True
    for i in graph[v]:
        if visited[i]:
            continue
        dfs(i)
    stack.append(v)

def r_dfs(v, idx):
    visited[v] = True
    heapq.heappush(scc[idx], v)
    for i in r_graph[v]:
        if visited[i]:
            continue
        r_dfs(i, idx)

v, e = map(int, input().split())
graph = defaultdict(set)
r_graph = defaultdict(set)
visited = [False] * (v + 1)

for i in range(e):
    x, y = map(int, input().split())
    graph[x].add(y)
    r_graph[y].add(x)

for i in range(1, v + 1):
    if visited[i]:
        continue
    dfs(i)

visited = [False] * (v + 1)
scc = []
idx = 0
while stack:
    v = stack.pop()
    if visited[v]:
        continue
    scc.append(list())
    r_dfs(v, idx)
    idx += 1
scc.sort()

print(idx)
for i in scc:
    while i:
        print(heapq.heappop(i), end = ' ')
    print(-1)