import sys; input = sys.stdin.readline

n = int(input())
arr = [0] * 25
pre_y = 0

for i in range(n):
    x, y = map(int, input().split())
    for j in range(pre_y + 1, y):
        arr[j] = arr[pre_y]
    arr[y] = max(arr[x] + 1, arr[y - 1], arr[y])
    pre_y = y
print(arr[pre_y])