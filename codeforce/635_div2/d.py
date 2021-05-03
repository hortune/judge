import sys
input = sys.stdin.buffer.readline
from bisect import bisect_left
loss = lambda x, y, z: (x - y) **2 + (x - z)**2 + (y - z)**2


T = int(input())
for _ in range(T):
    nr, ng, nb = map(int, input().split())
    rs = list(map(int, input().split()))
    gs = list(map(int, input().split()))
    bs = list(map(int, input().split()))
    rs.sort()
    gs.sort()
    bs.sort()
    rgbs = [rs, gs, bs]
    alls = []
    for r in rs:
        alls.append((r, 0))
    for g in gs:
        alls.append((g, 1))
    for b in bs:
        alls.append((b, 2))
  
    occur = [False] * 3
    p = [0, 0, 0]
    alls.sort()
    ans = 12318239218391283912312231
    for num, c in alls:
        occur[c] = True
        p[c] = num
        if all(occur):
            #ans = min(ans, (p[0] - p[1]) ** 2 + (p[2] - p[1]) ** 2 + (p[2] - p[0]) ** 2)
            nc = (c + 1) % 3
            ncc = (c + 2) % 3
            s_num = bisect_left(rgbs[ncc], (p[nc] + p[c]) / 2)
            if s_num < len(rgbs[ncc]):
                ans = min(ans, loss(p[nc], p[c], rgbs[ncc][s_num]))
            if s_num > 0:
                ans = min(ans, loss(p[nc], p[c], rgbs[ncc][s_num - 1]))

            s_num = bisect_left(rgbs[nc], (p[ncc] + p[c]) / 2)
            if s_num < len(rgbs[nc]):
                ans = min(ans, loss(p[ncc], p[c], rgbs[nc][s_num]))
            if s_num > 0:
                ans = min(ans, loss(p[ncc], p[c], rgbs[nc][s_num - 1]))
    print(ans)

