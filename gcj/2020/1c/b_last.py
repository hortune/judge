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
    done = 0
    cum = 0
    while done < 10: 
        for q, r in data:
            possible[0].discard(r[0])
            if q[0] == '-':
                continue
            if len(q) == len(r):
                for i in range(int(q[0]) + 1, 10):
                    possible[i].discard(r[0])

                # special case
                if q[0] == '1':
                    possible[1] = set([r[0]])
                    for i in range(1, len(q)):
                        if q[i] == '0':
                            possible[0] = set([r[i]])
                        else:
                            for j in range(int(q[i]) + 1, 10):
                                possible[j].discard(r[i])
                            break
        done = 0
        vis = {}
        for idx, ele in enumerate(possible):
            if len(ele) == 1:
                done += 1
                vis.add(list(ele)[0])

        for idx in range(len(possible)):
            if len(possible[idx]) > 1:
                possible[idx] = possible[idx] - vis

        for idx in range(len(possible)):
            if len(possible[idx]) == 1:
                cum += 1
            else:
                break

    done = 0
    vis = set()
    counter = 0
    ans = []
    dfs(possible, 0, vis=vis, ans=ans)
    print 'Case #{}: {}'.format(case, ''.join(ans))
