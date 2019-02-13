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

while True:
    n = int(input())
    if n == 0:
        break

    lo = 0; hi = 0; sum = 0; result = 0
    p_list = primes_up_to(n)

    while lo < len(p_list):
        if sum < n:
            sum += p_list[hi]
            if hi + 1 < len(p_list):
                hi += 1
        elif sum >= n:
            sum -= p_list[lo]
            lo += 1
        if sum == n:
            result += 1
            
    print(result)