import sys; input = sys.stdin.readline

n = int(input())
l = [0] + list(map(int, input().split()))
mns = [[0] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if j < l[i]:
            mns[i][j] = mns[i - 1][j]
        else:
            mns[i][j] = max(mns[i - 1][j], mns[i - 1][l[i] - 1] + 1)

print(mns[n][n])