import sys
input = sys.stdin.readline
def dfs(possible, idx, vis, ans):
    if len(ans) == 10:
        return True
    for ele in possible[idx]:
        if ele not in vis:
            ans.append(ele)
            vis.add(ele)
            if dfs(possible, idx+1, vis, ans):
                return True
            vis.remove(ele)
            ans.pop()
    return False
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
        elif len(q) == 1:
            for i in range(int(q) + 1, 10):
                possible[i].discard(r)
        elif len(q) == len(r):
            possible[0].discard(r[0])
            for i in range(int(q[0]) + 1, 10):
                possible[i].discard(r[0])
            # special case
            if q[0] == '1':
                for i in range(1, len(q)):
                    if q[i] == '0':
                        possible[0] = set([r[i]])
                    else:
                        for j in range(int(q[i]) + 1, 10):
                            possible[j].discard(r[i])
                        break
        elif len(r) != 1:
            possible[0].discard(r[0])
    done = 0
    vis = set()
    counter = 0
    ans = []
    dfs(possible, 0, vis=vis, ans=ans)
    print 'Case #{}: {}'.format(case, ''.join(ans))

