n = int(input())
three = 0
five = 0

while True:
    if n >= 5:
        n -= 5
        five += 1
    else:
        if five == 0:
            if n % 3 != 0: print(-1)
            else: print(1)
            break
        else:
            for _ in range(five + 1):
                if n % 3 == 0:
                    three = n // 3
                    break
                n += 5
                five -= 1
            
            if n % 3 != 0:
                print(-1)
            else:
                print(three + five)
            break