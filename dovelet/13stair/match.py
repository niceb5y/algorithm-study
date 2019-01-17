s = input()
l = []
l_r = []

for i in range(len(s)) :
    if s[i] == '(' :
        l.insert(0, i)

    if s[i] == ')' :
        if len(l) == 0 :
            print("not match")
            exit()

        if l[0] > i :
            print("not match")
            exit()

        l_r.append((l.pop(0), i))

if len(l) != 0 :
    print("not match")
    exit()

for a, b in l_r :
    print("%d %d" %(a, b))
