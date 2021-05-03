import sys
input = sys.stdin.readline
T = int(raw_input())
for case in range(1, T+1):
    U = int(raw_input())
    data = []
    visible = set()
    for i in range(10000):
        q, r = raw_input().split()
        for c in r:
            visible.add(c)
        data.append((q, r))
    
    assert len(visible) == 10
    possible = [set() for _ in range(10)]
    for c in visible:
        for idx in range(10):
            possible[idx].add(c)

    for q, r in data:
        if q[0] == '-':
            if len(r) > 1:
                possible[0].discard(r[0])
        if len(q) == 1:
            for i in range(int(q) + 1, 10):
                possible[i].discard(r)
        elif len(q) == len(r):
            higher = int(q[0])
            possible[0].discard(r[0])
            for i in range(int(q[0]) + 1, 10):
                possible[i].discard(r[0])
        elif len(r) != 1:
            possible[0].discard(r[0])
    ans = [None] * 10
    done = 0
    vis = set()
    while done != 10:
        for i in range(10):
            if len(possible[i]) == 1:
                char = list(possible[i])[0]
                vis.add(char)
                ans[i] = char
                possible[i] = set()
                done += 1
            elif len(possible[i]):
                possible[i] = possible[i] - vis
    print 'Case #{}: {}'.format(case, ''.join(ans))

