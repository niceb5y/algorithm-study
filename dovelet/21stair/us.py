import sys
input = sys.stdin.readline

def lower_bound(arr, num):
    lo = 0; hi = len(arr) - 1
    while lo < hi:
        mid = (lo + hi) // 2
        if arr[mid] < num:
            lo = mid + 1
        else:
            hi = mid
    return lo

n = int(input())
l = list(map(int, input().split()))
arr = [l[0]]
arr2 = [(0, l[0])]

for i in range(1, n):
    if l[i] > arr[-1]:
        arr.append(l[i])
        arr2.append((len(arr) - 1, l[i]))
    else:
        idx = lower_bound(arr, l[i])
        arr[idx] = l[i]
        arr2.append((idx, l[i]))
        
arr2.reverse()
pos = len(arr) - 1
result = []
for i in arr2:
    if pos == -1:
        break
    x, y = i
    if x == pos:
        result.insert(0, y)
        pos -= 1

print(len(arr))
for i in result:
    print(i, end = ' ')