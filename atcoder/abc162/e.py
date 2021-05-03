N, K = map(int, input().split())
MOD = 1000000007
ans = 0
dp = [0] * (K + 1)
for i in range(K, 0, -1):
    div = K // i
    amount = (pow(div, N, MOD)) % MOD
    for j in range(2, div + 1, 1):
        amount = (amount - dp[j * i] + MOD) % MOD
    dp[i] = amount
    ans = (ans + amount * i) % MOD
print(ans)
