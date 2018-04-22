from collections import deque

n = int(input())
k = [input() for _ in range(n)]

q = deque([(1,1,1)])
vis = [[False]*n for _ in range(n)]
target = (n-2,n-2)

ans = -1
while len(q) != 0:
    x, y, c = q.popleft()
    if (not vis[x][y]) and k[x][y] == ".":
        if x == y and y == n-2:
            ans = c
            break
        vis[x][y] = True
        
        if x > 0:
            q.append((x-1,y,c+1))
        if x < n-1:
            q.append((x+1,y,c+1))
        if y > 0:
            q.append((x,y-1,c+1))
        if y < n-1:
            q.append((x,y+1,c+1))
print(ans if ans >= 0 else "No solution!")
