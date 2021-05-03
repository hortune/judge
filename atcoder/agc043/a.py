h, w = map(int, input().split())
mapping = [input().strip() for i in range(h)]
dp = [[123012302103120310]*w for i in range(h)]

for i in range(h):
    for j in range(w):
        if i == 0 and j == 0:
            dp[i][j] = int('#' == mapping[i][j])
 
        if j != 0:
            if mapping[i][j] == '#' and mapping[i][j-1] != '#':
                dp[i][j] = min(dp[i][j-1] + 1, dp[i][j])
            else:
                dp[i][j] = min(dp[i][j-1], dp[i][j])
        if i != 0:
            if mapping[i][j] == '#' and mapping[i-1][j] != '#':
                dp[i][j] = min(dp[i-1][j] + 1, dp[i][j])
            else:
                dp[i][j] = min(dp[i-1][j], dp[i][j])
print(dp[-1][-1])
