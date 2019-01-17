def is_prime(n):
    square = 0

    for i in range(1, n + 1):
        if i * i > n:
            square = i
            break
     
    for i in range(2, square + 1):
        if n % i == 0: return False

    return True
 
def search_prime(n):
    global n_list, q, cnt

    # 천의 자리
    for i in range(1, 10):
        num = n % 1000 + i * 1000
        if num == n: continue
        
        if (n_list[num] > cnt + 1):
            q.append(num)
            n_list[num] = cnt

    # 백의 자리
    for i in range(10):
        num = (n // 1000) * 1000 + n % 100 + i * 100
        if num == n: continue
        
        if (n_list[num] > cnt + 1):
            q.append(num)
            n_list[num] = cnt

    # 십의 자리
    for i in range(10):
        num = n - n % 100 + n % 10 + i * 10
        if num == n: continue
        
        if (n_list[num] > cnt + 1):
            q.append(num)
            n_list[num] = cnt

    # 일의 자리
    for i in range(1, 10):
        num = n - n % 10 + i
        if num == n: continue
        
        if (n_list[num] > cnt + 1):
            q.append(num)
            n_list[num] = cnt

tasecase = int(input())

for _ in range(tasecase):
    start, end = map(int, input().split())
    n_list = [0 for i in range(10000)]
    q = [start]
    cnt = 0

    for i in range(1000, 10000):
        if is_prime(i) == True:
            n_list[i] = 0xfffffff
        else:
            n_list[i] = -1
    n_list[start] = 0

    flag = False
    while len(q) > 0:
        n = q.pop(0)
        cnt = n_list[n] + 1

        if (n == end):
            flag = True
            break

        search_prime(n)

    if flag == True:
        print(n_list[n])
    else:
        print("Impossible")