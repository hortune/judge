from heapq import heapify, heappush, heappop
X, Y, A, B, C = map(int, input().split())
ps = list(map(int, input().split()))
qs = list(map(int, input().split()))
rs = list(map(int, input().split()))


rs.sort(key=lambda x: -x)
hp = []
hq = []
for p in ps:
    heappush(hp, p)
    if len(hp) > X:
        heappop(hp)

for q in qs:
    heappush(hq, q)
    if len(hq) > Y:
        heappop(hq)

for r in rs:
    if len(hq) < Y:
        heappush(hq, r)
    elif len(hp) < X:
        heappush(hp, r)
    elif hp[0] < hq[0]:
        heappush(hp, r)
        heappop(hp)
    else:
        heappush(hq, r)
        heappop(hq)

print(sum(hq) + sum(hp))
