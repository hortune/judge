n, k = map(int, input().split())
cums = [0] * (n + 1)
cums[0] = 1
MOD = 1000000007
for i in range(1, n + 1):
    cums[i] = ((n + n - i + 1) * i) // 2 - ((i - 1) * i) // 2 + 1
ans = 0
for i in range(k, n + 1):
    ans = (ans + cums[i]) % MOD
ans = (ans + 1) % MOD
print(ans)
