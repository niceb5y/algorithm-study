s = list(input())
s.reverse()
q_mark = s.index('?')

check = 0
for i in range(len(s)) :
    if s[i] == '?' :
        continue
    elif s[i] == 'X' :
        check += check + 10 * (i + 1)
    else :
        check += int(s[i]) * (i + 1)

length = 0
if q_mark == 0 : length = 11
else : length = 10

for i in range(length) :
    if (check + (q_mark + 1) * i) % 11 == 0 :
        if (i == 10) : print("X")
        else : print(i)
        break
        
    if i == length - 1 : print(-1)