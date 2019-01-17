n, c = map(int, input().split())
l = []

for i in range(n):
    l.append(int(input()))
l.sort()

lo = 0
hi = l[-1] - l[0]
max_v = -1

while lo < hi:
    mid = (lo + hi) // 2
    cow = 1
    idx = 0

    for i in range(1, n):
        if (l[i] - l[idx]) >= mid:
            cow += 1
            idx = i

    if cow >= c:
        if (mid > max_v):
            max_v = mid
        lo = mid + 1
    else:
        hi = mid
        
print(max_v)