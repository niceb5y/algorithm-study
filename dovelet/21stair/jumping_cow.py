import sys
input = sys.stdin.readline

l = []
for _ in range(int(input())):
    l.append(int(input()))

flag = True
result = 0
for i in range(len(l) - 1):
    if l[i] - l[i + 1] > 0 and flag == True:
        result += l[i]
        flag = False
    elif l[i] - l[i + 1] < 0 and flag == False:
        result -= l[i]
        flag = True
    if i == len(l) - 2 and flag == True:
        result += l[i + 1]

print(result)