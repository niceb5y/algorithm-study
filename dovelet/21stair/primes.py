import sys
from collections import defaultdict
input = sys.stdin.readline

def primes_up_to(n:int) -> [int]:
    seive = [False, False] + [True] * (n - 1)
    for i,e in enumerate(seive):
        if e:
            for j in range(2 * i, n + 1, i):
                seive[j] = False
    return [x for (x, y) in enumerate(seive) if y]

# boj 1644
# 9967
while True:
    n = int(input())
    if n == 0:
        break
    
    p_list = primes_up_to(n)
    arr = defaultdict(list)
    arr[0] = [[0]]
    
    for i, p in enumerate(p_list):
        for j in list(arr.keys()):
            if j >= n:
                break
            for k in arr[j]:
                if k[-1] != 0 and p_list.index(p) - p_list.index(k[-1]) > 1:
                    continue
                if p not in k:
                    arr[j + p].append(k + [p])
    print(len(arr[n]))