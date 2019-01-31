import sys
import heapq
input = sys.stdin.readline

w = int(input())
n = int(input())
l = []
for i in range(n):
    a, b = map(int, input().split())
    l.append((b / a, a))

l.sort()
result = 0
while l:       
    a, b = l.pop()
    if w >= b:
        w -= b
        result += a * b
    else:
        result += a * w
        break
        
    if w == 0:
        break
print("%.2f" %result)