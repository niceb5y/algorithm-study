import sys
input = sys.stdin.readline
print = sys.stdout.write

class Tree():
    def __init__(self):
        self.left = None
        self.right = None
        self.data = 0
        self.subdata = 0

m, n = map(int, input().split())

root = Tree()
for i in range(m):
    l_m = list(map(int, input().split()))

    # make binary trie
    p = root
    for j, l in enumerate(l_m):
        if j == 0:
            continue

        if p != root:
            p.subdata += 1
            
        if l == 0:
            if p.left is None: 
                p.left = Tree()
            p = p.left
        else:
            if p.right is None:
                p.right = Tree()
            p = p.right
        
        if j == len(l_m) - 1:
            p.data += 1

for i in range(n):
    l_n = list(map(int, input().split()))

    # solve
    p = root
    result = 0
    for j, l in enumerate(l_n):
        if j == 0:
            continue

        if l == 0:
            if p.left is not None: 
                p = p.left
            else:
                print("%d\n" %result)
                break
        else:
            if p.right is not None:
                p = p.right
            else:
                print("%d\n" %result)
                break
        
        if p.data:
            result += p.data

        if j == len(l_n) - 1:
            if p.subdata:
                result += p.subdata
            print("%d\n" %result)
            break