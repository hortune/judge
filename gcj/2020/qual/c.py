T = int(input())
for case in range(T):
    n = int(input())
    intervals = []
    scan_line = []
    for i in range(n):
        s, e = map(int, input().split())
        scan_line.append((s, 1, i))
        scan_line.append((e, 0, i))
    scan_line.sort()
    empty = [True] * 2
    ans = [0] * n
    gg = False
    for ele in scan_line:
        t, m, idx = ele
        if m == 0:
            empty[ans[idx]] = True
        else:
            if sum(empty) == 0:
                gg = True
                break
            if empty[0]:
                ans[idx] = 0
                empty[0] = False
            else:
                ans[idx] = 1
                empty[1] = False
    if gg:
        print('Case #{}:'.format(case + 1), 'IMPOSSIBLE')
    else:
        print('Case #{}:'.format(case + 1), ''.join(list(map(lambda x: "JC"[x], ans))))
