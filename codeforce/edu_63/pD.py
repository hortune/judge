# dp[i][0] : 後綴最大值
# dp[i][0] : 前綴最小值

n, m = map(int, input().split())
dp = [[[-9487948794879487]*3 for j in range(3)] for i in range(n+1)]
nums = list(map(int, input().split()))
dp[0][0][0] = 0
dp[0][1][0] = 0

for i in range(1,n+1):
    dp[i][0][0] = dp[i-1][0][0]

    dp[i][1][0] = max(dp[i-1][1][0] + nums[i-1],  # 包自己的最大後綴 
                      dp[i-1][0][0] + nums[i-1]) 

    dp[i][2][0] = max(dp[i-1][2][0],              # 包或不包後綴 
                      dp[i][1][0])
    
    dp[i][1][1] = max(dp[i-1][1][0] + nums[i-1]*m, # 包自己的最大後綴 
                      dp[i-1][1][1] + nums[i-1]*m, # 且正在翻轉
                      nums[i-1]*m)
    
    dp[i][1][2] = max(dp[i-1][1][1] + nums[i-1],
                      dp[i][1][1],
                      dp[i-1][1][2] + nums[i-1])

    dp[i][2][2] = max(dp[i][2][0], 
                      dp[i][1][2],
                      dp[i-1][2][2],
                      dp[i][0][0])
    """
    print(i)
    print(dp[i][0][0], dp[i][0][1], dp[i][0][2])
    print(dp[i][1][0], dp[i][1][1], dp[i][1][2])
    print(dp[i][2][0], dp[i][2][1], dp[i][2][2])
    """
print(dp[n][2][2])
