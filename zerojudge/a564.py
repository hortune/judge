try:
    while True:
        n = int(input())
        weight = list(map(int,input().split()))
        fathers = list(map(int,input().split()))
        dp = [[0]*2 for i in range(n)]

        for i in range(n-1, 0, -1):
            dp[i][0] += weight[i]
            dp[fathers[i-1]][1] += max(dp[i][0], dp[i][1])
            
            if fathers[i-1] != 0:
                dp[fathers[fathers[i-1]-1]][0] += max(dp[i][0], dp[i][1])

        dp[0][0] += weight[0]

        print(max(dp[0][0],dp[0][1]))
except:
    pass
"""
dp[i][0]: 此藍選的最大值
dp[i][1]: 此藍不選的最大值

dp[i][0] = w[i] + sum(grandson())
dp[i][1] = sum(sons)
"""

