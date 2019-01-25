import sys
print = sys.stdout.write

def make_num(n):
    result = n
    for i in str(n):
        result += int(i)
    return result

arr = [True] * 10001
for i in range(1, 10001):
   result = make_num(i)
   if result < 10001:
    arr[result] = False

for i in range(1, 10001):
    if arr[i]:
        print("%d\n" %i)