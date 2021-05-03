import sys
from collections import deque

input = sys.stdin.buffer.readline
n, k = map(int, input().split())
childs = [[] for i in range(n+1)]
for i in range(n-1):
    a, b = map(int, input().split())
    childs[a].append(b)
    childs[b].append(a)

vis = set()
depths = [0] * (n + 1)
depths[0] = -1
Q = deque([(1, 0)])
descendents = [0] * (n + 1)
fathers = [i for i in range(n + 1)]
while len(Q):
    node, depth = Q[0]
    Q.popleft()
    depths[node] = depth
    vis.add(node)
    for child in childs[node]:
        if child not in vis:
            Q.append((child, depth + 1))
            fathers[child] = node

Q = deque([])
for i in range(2, n + 1):
    if len(childs[i]) == 1:
        Q.append(i)

childs_num = [len(child)-1 for child in childs]
while len(Q):
    top = Q[0]
    Q.popleft()
    father = fathers[top]
    if father == top:
        continue
    descendents[father] += 1 + descendents[top]
    childs_num[father] -= 1
    if childs_num[father] == 0:
        Q.append(father)
# depths and descendents

res = [i - j for i, j in zip(depths, descendents)]
print(sum(sorted(res[1:])[-k:]))
