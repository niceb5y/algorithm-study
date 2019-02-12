import sys
input = sys.stdin.readline

n = int(input())
if n * (n + 1) % 4 != 0:
    print(0)
else:
    arr = [1] + [0] * (n * (n + 1) // 2)
    idx = 0
    for i in range(1, n + 1):
        pre_idx = idx
        idx += i
        for j in range(pre_idx + 1):
            arr[idx - j] += arr[pre_idx - j]
            
    print(arr[(n * (n + 1)) // 4] // 2)