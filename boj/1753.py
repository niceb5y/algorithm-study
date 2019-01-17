import sys
import heapq

MAX_NUM = 0x7fffffff
input = sys.stdin.readline
print = sys.stdout.write

v, e = map(int, input().split())
k = int(input())

mat = [[] for _ in range(v + 1)]

for _ in range(e):
    a, b, c = map(int, input().split())
    mat[a].append((b, c))

dist = [MAX_NUM] * (v + 1)
dist[k] = 0
pq = []

heapq.heappush(pq, (0, k))

while pq:
    cost, here = heapq.heappop(pq)

    if cost > dist[here]:
        continue
    
    for i, i_cost in mat[here]:
        if dist[i] > dist[here] + i_cost:
            dist[i] = dist[here] + i_cost 
            heapq.heappush(pq, (dist[i], i))

for i in range(1, v + 1):
    if dist[i] == MAX_NUM:
        print("INF\n")
    else:
        print("%d\n" %dist[i])