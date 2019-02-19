import sys; input = sys.stdin.readline

n = int(input())
onej = list(map(int, input().split()))
twoj = [0] * n
thrj = [0] * n

thrj[2] = onej[2]
twoj[2] = onej[0] + onej[2]
onej[2] = onej[1] + onej[2]
twoj[1] = onej[1]
onej[1] += onej[0]

for i in range(3, n):
    thrj[i] = onej[i] + max(onej[i - 3], twoj[i - 3], thrj[i - 3])
    twoj[i] = onej[i] + max(onej[i - 2], twoj[i - 2], thrj[i - 2])
    onej[i] += max(twoj[i - 1],  thrj[i - 1])
    
print(max(onej[n - 1], onej[n - 2], twoj[n - 1]))