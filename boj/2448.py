import math
import sys
input = sys.stdin.readline
print = sys.stdout.write

arr = []
def make_star(x, y, h):
    if h == 3:
        arr[x][y] = '*'
        arr[x + 1][y - 1] = '*'
        arr[x + 1][y + 1] = '*'
        for i in range(5): arr[x + 2][y - 2 + i] = '*'
        return
    # 위
    make_star(x, y, h // 2)
    # 좌
    make_star(x + h // 2, y - h // 2, h // 2)
    # 우
    make_star(x + h // 2, y + h // 2, h // 2)

col = int(input())
k = int(math.log(col // 3, 2))
row = 5 * (2 ** k) + (2 ** k) - 1
arr = [[' ' for i in range(row)] for _ in range(col)]

make_star(0, row // 2, col)

for i in range(col):
    print(''.join(arr[i]) + '\n')

'''
3 = (5 * 1 + 0) * 3
6 = (5 * 2 + 1) * 6
12 = (5 * 4 + 3) * 12
24 = (5 * 8 + 7) * 24
48 = (5 * 16 + 15) * 48
.
.
.
3 * 2^k = (5 * 2^k + 2^k - 1) * n
'''