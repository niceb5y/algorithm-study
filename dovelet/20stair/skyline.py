import sys
input = sys.stdin.readline

n = int(input())
left = 5001
right = -1
skyline = [0] * 5001
for i in range(n):
    a, b, c = map(int, input().split())

    for j in range(a, b + 1):
        if skyline[j] < c:
            skyline[j] = c

    if a < left:
        left = a
    if b > right:
        right = b

tmp1 = left
tmp2 = skyline[left]
for i in range(left, right + 1):
    if skyline[i] > tmp2:
        print(tmp1, i, tmp2)
        tmp1 = i
        tmp2 = skyline[i]

    elif skyline[i] < tmp2:
        print(tmp1, i - 1, tmp2)
        tmp1 = i - 1
        tmp2 = skyline[i]
        
    if i == right:
        print(tmp1, i, tmp2)

def getSkyline(self, buildings):
    events = sorted([(L, -H, R) for L, R, H in buildings] + list({(R, 0, None) for _, R, _ in buildings}))
    res, hp = [[0, 0]], [(0, float("inf"))]
    for x, negH, R in events:
        while x >= hp[0][1]: 
            heapq.heappop(hp)
        if negH: 
            heapq.heappush(hp, (negH, R))
        if res[-1][1] + hp[0][0]: 
            res += [x, -hp[0][0]],
    return res[1:]

----------------------------------------------
class Solution(object):
    def getSkyline(self, buildings):
    """
    :type buildings: List[List[int]]
    :rtype: List[List[int]]
    """
    def addsky(pos, hei):
        if sky[-1][1] != hei:
            sky.append([pos, hei])

    sky = [[-1,0]]
    
    # possible corner positions
    position = set([b[0] for b in buildings] + [b[1] for b in buildings])
    
    # live buildings
    live = []
    
    i = 0
        
    for t in sorted(position):
        
        # add the new buildings whose left side is lefter than position t
        while i < len(buildings) and buildings[i][0] <= t:
            heappush(live, (-buildings[i][2], buildings[i][1]))
            i += 1
            
        # remove the past buildings whose right side is lefter than position t
        while live and live[0][1] <= t:
            heappop(live)
        
        # pick the highest existing building at this moment
        h = -live[0][0] if live else 0
        addsky(t, h)

    return sky[1:]


https://briangordon.github.io/2014/08/the-skyline-problem.html
https://fatc.club/2017/03/01/501
https://www.geeksforgeeks.org/the-skyline-problem-using-divide-and-conquer-algorithm/

8
1 5 11
2 7 6
3 9 13
12 16 7
14 25 3
19 22 18
23 29 13
24 28 4