import sys
input = sys.stdin.readline
print = sys.stdout.write

def is_hansu(n):
    l = list(str(n))
    diff = 0
    for i in range(len(l) - 1):
        tmp = int(l[i]) - int(l[i + 1])
        if i == 0:
            diff = tmp
        elif tmp != diff:
            return False
    return True

n = int(input())
cnt = 0
for i in range(1, n + 1):
    if is_hansu(i):
        cnt += 1
print("%d\n" %cnt)