import sys
input = sys.stdin.readline

class Tree():
    global l_p
    def __init__(self):
        self.left = None
        self.right = None
        self.data = 0

    def traverseInorder(self, root):
        if root is not None:
            self.traverseInorder(root.left)
            if root.data > 0:
                l_p[root.data - 1] += 1
            self.traverseInorder(root.right)

    def traversePreorder(self, root):
        if root is not None:
            if root.data > 0:
                l_p[root.data - 1] += 1
            self.traversePreorder(root.left)
            self.traversePreorder(root.right)

    def traversePostorder(self, root):
        if root is not None:
            self.traversePreorder(root.left)
            self.traversePreorder(root.right)
            if root.data > 0:
                l_p[root.data - 1] += 1

m, n = map(int, input().split())
l_m = []
l_n = []
l_p = [0] * n

for i in range(m):
    l_m.append(list(map(int, input().split())))
for i in range(n):
    l_n.append(list(map(int, input().split())))

# make binary tree
root = Tree()
for i, l in enumerate(l_n):
    p = root
    for j in range(len(l)):
        if j == 0:
            continue

        if l[j] == 0:
            if p.left is None: 
                p.left = Tree()
            p = p.left    
        else:
            if p.right is None:
                p.right = Tree()
            p = p.right
        
        if j == len(l) - 1:
            p.data = i + 1

# solve
for i, l in enumerate(l_m):
    p = root
    for j in range(len(l)):
        if j == 0:
            continue
                    
        if l[j] == 0:
            if p.left is not None: 
                p = p.left
            else:
                continue
        else:
            if p.right is not None:
                p = p.right
            else:
                continue
        
        if p.data > 0:
            l_p[p.data - 1] += 1

        if j == len(l) - 1:
            if p.left is not None:
                p.left.traverseInorder(p.left)
            if p.right is not None:
                p.right.traverseInorder(p.right)
            break

for i in l_p:
    print(i)