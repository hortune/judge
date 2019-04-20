from heapq import heapify, heappush, heappop
from collections import deque

n = int(input())
in_counts = [0]*n
c_counts = [False]*n
parents = [0]*n
childs = [[] for i in range(n)]

for i in range(n):
    parent, c = list(map(int, input().split()))
    parents[i] = parent - 1
    c_counts[i] = 1 - c
    if parent > 0:
        in_counts[parent - 1] += c_counts[i]
        childs[parent - 1].append(i)

queue = []
for i in range(n):
    if not c_counts[i] and in_counts[i] == 0:
        queue.append(i+1)

queue.sort()
if len(queue):
    print(" ".join(list(map(str, queue))))
else:
    print(-1)
