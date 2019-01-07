N, M = map(int, input().split())

money = []

for i in range(N) :
    money.append(int(input()))

min_val = max(money)
max_val = 100000
mid_val = 0

while min_val <= max_val :
    mid_val = (min_val + max_val) // 2
    k = mid_val
    cnt = 1
   
    for i in range(N) :
        if k < money[i] :
            cnt += 1
            k = mid_val - money[i]
        else :
            k -= money[i]

    if cnt > M :
        min_val = mid_val + 1
    elif cnt <= M :
        max_val = mid_val - 1

print(min_val)