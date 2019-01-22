import sys

# bfs
'''
graph = {1:[2,3], 2:[3,4] ... etc}

def bfs(graph, start):
    visited = []
    queue = [start]

    while queue:
        n = queue.pop(0)
        if n not in visited:
            visited.append(n)
            queue += list(set(graph[n]) - set(visited))
    return visited
'''

# dfs
'''
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
'''

# dfs_recursive
'''
def dfs_recursive(graph, vertex, visited = []):
    if vertex not in visited:
        visited.append(vertex)

        l = list(set(graph[vertex]) - set(visited))
        l.sort()

        for node in l:
            dfs_recursive(graph, node, visited)
    return visited
'''

# list sort
'''
l.sort() -> 오름차순
l.sort(reverse = True) -> 내림차순
l[::-1] -> 리스트 reverse
'''

# list - list
'''
list(set(l1) - set(l2))
'''

# list input
# 갯수 1 2 3 일 때 갯수 제외하고 리스트에 저장
'''
_, *l = map(int, input().split())
'''

# input until EOF
'''
#1
for line in sys.stdin:
    pass

#2
#sys.stdin.readline() 은 EOF 안 받음

while True:
    try:
        input()
    except EOFError:
        break
'''

# dictionary add value with list
'''
d = dict() or d = {}

#1
from collections import defaultdict
d = defaultdict(list)
d[idx].append(value)

#2
d = {}
if idx in graph:
    d[idx].append(value)
else:
    d[idx] = [value]

#3
d = {}
d.setdefault(idx, [])
d[idx].append(value)
'''

# 2D array
'''
#initialize
matrix = [[0] * m for i in range(m)] 

#1
for i in range(n) :
    matrix.append(list(map(int, input().split())))

#2
for i in range(n) :
    matrix.append([int(i) for i in input().split()])

#3
matrix = [[int(j) for j in input().split()] for i in range(n)]

#4
for i in range(n) :
    row = input().split()
    for i in range(len(row)) :
        row[i] = int(row[i])
    matrix.append(row)
'''

# memory check
'''
import tracemalloc
tracemalloc.start()

# ... run your application ...

snapshot = tracemalloc.take_snapshot()
top_stats = snapshot.statistics('lineno')

print("[ Top 10 ]")
for stat in top_stats[:10]:
    print(stat)
'''

# 소수 판별
'''
def is_prime(n):
    square = 0

    for i in range(1, n + 1):
        if i * i > n:
            square = i
            break
     
    for i in range(2, square + 1):
        if n % i == 0: return False

    return True
'''

# 에라토스테네스의 체
'''
def primes_up_to(n:int) -> [int]:
    seive = [False, False] + [True] * (n - 1)
    for i,e in enumerate(seive):
        if e:
            for j in range(2 * i, n + 1, i) :
                seive[j] = False
    return [x for (x, y) in enumerate(seive) if y]
'''

# recursion limit
'''
from sys import setrecursionlimit as SRL
SRL(150000)
'''