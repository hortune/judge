from math import floor
n, k = map(int, input().split())

childs = [[] for i in range(n+1)]

for i in range(n - 1):
    i, j, color = map(int, input().split())
    childs[i].append((j, color))
    childs[j].append((i, color))



# (node, parent, color)
# 找不包含的
stack = [(1, 0, 1)]
record = [0]*(n+1)
vis = [False]*(n+1)
ans = 0
MOD = floor(1e9 + 7)
while len(stack):
    node, parent, fcolor = stack[-1]
    if not vis[node]:
        vis[node] = True
        for child, color in childs[node]:
            if child != parent:
                stack.append((child, node, color))
    else:
        stack.pop()
        record[node] = 1
        for child, color in childs[node]:
            if child != parent and color == 0:
                record[node] += record[child]
        if fcolor:
            ans = (ans + pow(record[node],k,MOD)) % MOD
print((pow(n,k,MOD) -  ans + MOD) % MOD)
