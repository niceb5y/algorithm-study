import sys
input = sys.stdin.readline

n = int(input())
left = 5001
right = -1
skyline = [0] * 5001
for i in range(n):
    a, b, c = map(int, input().split())

    for j in range(a, b + 1):
        if skyline[j] < c:
            skyline[j] = c

    if a < left:
        left = a
    if b > right:
        right = b

tmp1 = left
tmp2 = skyline[left]
for i in range(left, right + 1):
    if skyline[i] > tmp2:
        print(tmp1, i, tmp2)
        tmp1 = i
        tmp2 = skyline[i]

    elif skyline[i] < tmp2:
        print(tmp1, i - 1, tmp2)
        tmp1 = i - 1
        tmp2 = skyline[i]
        
    if i == right:
        print(tmp1, i, tmp2)