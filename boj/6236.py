N, M = map(int, input().split())
money = []

for i in range(N):
    money.append(int(input()))

lo = max(money)
hi = 100000

while lo < hi:
    mid = (lo + hi) // 2
    k = mid
    cnt = 1
   
    for i in range(N):
        if k < money[i]:
            cnt += 1
            k = mid - money[i]
        else:
            k -= money[i]

    if cnt > M:
        lo = mid + 1
    else:
        hi = mid

print(lo)