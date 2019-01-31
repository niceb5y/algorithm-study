from collections import defaultdict
import sys
input = sys.stdin.readline

stack = []
global scc_no, graph, r_graph, visited

def dfs(v):
    visited[v] = True
    for i in graph[v]:
        if visited[i]:
            continue
        dfs(i)
    stack.append(v)

def r_dfs(v, idx):
    visited[v] = True
    scc_no[v] = idx
    for i in r_graph[v]:
        if visited[i]:
            continue
        r_dfs(i, idx)

n = int(input())

graph = defaultdict(set)
r_graph = defaultdict(set)
visited = [False] * (n + 1)

for i in range(1, n + 1):
    l = list(map(int, input().split()))
    l.pop()
    for j in l:
        graph[i].add(j)
        r_graph[j].add(i)

for i in range(1, n + 1):
    if visited[i]:
        continue
    dfs(i)

visited = [False] * (n + 1)
scc_no = [0] * (n + 1)
idx = 0
while stack:
    v = stack.pop()
    if visited[v]:
        continue
    r_dfs(v, idx)
    idx += 1

ind = [0] * idx
outd = [0] * idx
if idx == 1:
    print("1\n0")
else:
    for i in range(1, n + 1):
        for j in graph[i]:
            if scc_no[i] != scc_no[j]:
                outd[scc_no[i]] += 1
                ind[scc_no[j]] += 1

    ind_0_cnt = 0
    outd_0_cnt = 0
    for i in range(idx):
        if ind[i] == 0: ind_0_cnt += 1
        if outd[i] == 0: outd_0_cnt += 1
    print(ind_0_cnt)
    print(max(ind_0_cnt, outd_0_cnt))

# 들어오는 노드가 없는 SCC 갯수가 문제 1정답
# 들어오는 노드가 없는 SCC에는 공급하면, 이어지는 SCC에 차례대로 공급된다

# 들어오는 노드가 없는 SCC 갯수와 나가는 노드가 없는 SCC 갯수 중 큰 쪽이 문제2 정답
# 나가는 노드가 없는 SCC와 들어오는 노드가 없는 SCC를 이으면 하나의 싸이클이 되어 SCC가 된다.
# 하나의 SCC가 남을 때까지 연결하면 되므로 둘 중 큰 쪽이 정답
# 이미 하나의 SCC가 남아있는 경우에는 예외처리