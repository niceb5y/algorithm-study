import sys
from collections import defaultdict
input = sys.stdin.readline

n, m = map(int, input().split())
d = defaultdict(set)
for _ in range(m):
    cnt, *l = map(int, input().split())
    for i in range(cnt - 1):
        d[l[i + 1]].add(l[i])

result = []
v = set(range(1, n + 1))
while v:
    unvisited = v - set(d)

    if unvisited:
        tmp_v = unvisited.pop()
        result.append(tmp_v)
        v.remove(tmp_v)
        for i in list(d):
            if tmp_v in d[i]:
                d[i].remove(tmp_v)

            if not d[i]:
                d.pop(i)
    else:
        print(0)
        break

if not v:
    for i in result:
        print(i)
'''
6 3
3 1 4 3
4 6 2 5 4
2 2 3

1
6
2
5
4
3
'''