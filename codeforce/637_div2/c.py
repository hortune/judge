T = int(input())
for _ in range(T):
    n = int(input())
    nums = list(map(int, input().split()))
    nnums = list(enumerate(nums, 1))
    nnums.sort(key=lambda x: x[1])
    vis = [False] * 1000002
    pre = -1
    vis[n+1] = True
    gg = False
    for idx, num in nnums:
        if pre == -1:
            vis[idx] = True
        else:
            if idx != pre + 1:
                gg = True
                break
            else:
                vis[idx] = True
        pre = -1 if vis[idx + 1] else idx
    if gg:
        print('No')
    else:
        print('Yes')

