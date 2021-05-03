vis = [False] * 1000001
cur = 1

nums = []

add = 1000
while cur < 1000000:
    while cur < 1000000 and vis[cur]:
        cur += 1
    vis[cur] = True
    n_cur = cur + 1
    while n_cur < 1000000 and (vis[n_cur] or vis[n_cur ^ cur]):
        n_cur += 1
    vis[n_cur] = True
    vis[cur ^ n_cur] = True
    nums.append((cur, n_cur, cur ^ n_cur))
    print(bin(cur), bin(n_cur), bin(cur ^ n_cur), bin(cur + (cur ^ n_cur)))
    add -= 1
    if add == 0:
        break

#print(nums)
