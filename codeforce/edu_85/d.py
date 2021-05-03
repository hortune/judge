from math import floor
T = int(input())

for _ in range(T):
    n, l, r = map(int, input().split())
    o_r = r
    ans = []
    if l == n * (n - 1) + 1:
        print(1)
        continue
    i = 1
    while l > 0:
        if l <= 2 * (n - i):
            for j in range(i + 1, n + 1):
                l -= 1
                r -= 1
                if l <= 0 and r >= 0:
                    ans.append(i)
                l -= 1
                r -= 1
                if l <= 0 and r >= 0:
                    ans.append(j)
        else:
            l -= 2 * (n - i)
            r -= 2 * (n - i)
        i += 1
    while r > 0 and i < n:
        for j in range(i + 1, n + 1):
            r -= 1
            if r >= 0:
                ans.append(i)

            r -= 1
            if r >= 0:
                ans.append(j)
        i += 1
    if r > 0:
        ans.append(1)
    print(' '.join(list(map(str, ans))))
