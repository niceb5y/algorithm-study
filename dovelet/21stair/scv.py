import sys
input = sys.stdin.readline

n = int(input())
arr = [[int(i) for i in input().split()] for _ in range(n)]

for i in range(n):
    for j in range(n):
        if i == j == 0: continue
        elif i == 0: arr[i][j] = arr[i][j] + arr[i][j - 1]
        elif j == 0: arr[i][j] = arr[i][j] + arr[i - 1][j]
        else: arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]) + arr[i][j]
print(arr[n - 1][n - 1])