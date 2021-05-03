N, P = map(int, input().split())
num = input().strip()
ans = 0
if P == 2:
    for idx, nu in enumerate(num):
        if nu in '24680':
            ans += idx + 1
elif P == 5:
    for idx, nu in enumerate(num):
        if nu in '50':
            ans += idx + 1
else:
    nnum = [0] * N
    base = 1
    for i in range(N-1, -1, -1):
        nnum[i] = (int(num[i]) * base) % P
        base = (base * 10) % P
    for i in range(1, N):
        nnum[i] = (nnum[i] + nnum[i-1]) % P
    dp = [0] * P
    for i in range(N):
        if nnum[i] == 0:
            ans += 1 + dp[nnum[i]]
        else:
            ans += dp[nnum[i]]
        dp[nnum[i]] += 1
print(ans)
