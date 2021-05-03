T = int(input())
for _ in range(T):
    d, m = map(int, input().split())
    dp = [0] * 31
    dp[1] = 1
    dp[0] = 1
    bit = int.bit_length(d)
    for i in range(2, bit + 1):
        delta = min(d, (1 << i) - 1) - (1 << (i - 1)) + 1
        for j in range(i):
            dp[i] = (dp[i] + delta * dp[j]) % m
    ans = sum(dp[1:]) % m
    print(ans)
