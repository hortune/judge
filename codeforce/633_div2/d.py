import sys
input = sys.stdin.buffer.readline

n = int(input())
childs = [set() for i in range(n + 1)]
marker = [False] * (n + 1)

for i in range(n - 1):
    a, b = map(int, input().split())
    childs[a].add(b)
    childs[b].add(a)


for i in range(1, n + 1):
    if len(childs[i]) == 1:
        father = list(childs[i])[0]
        marker[father] = True

fans = sum(marker) + n - 1 - sum([len(child) == 1 for child in childs])

has_odd = False
root = None
for i in range(1, n + 1):
    if len(childs[i]) == 1:
        root = i
        break
bfs = [(root, 0, -1)]
while len(bfs):
    node, dist, dad = bfs[-1]
    bfs.pop()
    for child in childs[node]:
        if child == dad:
            continue
        bfs.append((child, dist+1, node))

    if len(childs[node]) == 1 and dad != -1:
        has_odd |= dist % 2

print(3 if has_odd else 1, fans)
