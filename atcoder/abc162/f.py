n = int(input())
nums = list(map(int, input().split()))

if n % 2 == 0:
    prefix = [0] * n
    suffix = [0] * n
    for i in range(0, n):
        prefix[i] += nums[i]
        if i - 2 >= 0:
            prefix[i] += prefix[i - 2]

    for i in range(n-1, -1, -1):
        suffix[i] += nums[i]
        if i + 2 < n:
            suffix[i] += suffix[i + 2]
    ans = max(prefix[-1], prefix[-2])

    for i in range(n):
        if i % 2 == 0 and  i + 2 < n:
            ans = max(ans, prefix[i] + suffix[i + 2])
        if i % 2 == 0 and  i + 3 < n:
            ans = max(ans, prefix[i] + suffix[i + 3])
        if i % 2 == 1 and i + 2 < n:
            ans = max(ans, prefix[i] + suffix[i + 2])
    print(ans)
else:
    dp = [[0] * n for i in range(3)] # -1, 0, +1
    # dp[delta][num], inclusive
    dp[2][0] = nums[0]
    dp[0][1] = 0
    dp[1][1] = max(nums[0], nums[1])
    dp[2][1] = 0
    dp[0][2] = 0
    dp[1][2] = max(nums[:3])
    dp[2][2] = nums[0] + nums[2]
    if n == 3:
        print(max(nums))
        exit()
    dp[0][3] = max(nums[:4]) # only choose one
    dp[1][3] = max(nums[0] + nums[3], nums[0] + nums[2], nums[1] + nums[3])
    dp[2][3] = 0
    dp[0][4] = max(nums[:5])
    dp[1][4] = max([nums[i] + nums[j] for i in range(5) for j in range(i+2, 5)])
    dp[2][4] = nums[0] + nums[2] + nums[4]

    for i in range(5, n):
        if (i + 1) % 2 == 0: # even
            dp[0][i] = max(dp[1][i - 1], dp[0][i - 2] + nums[i])
            dp[1][i] = max(dp[2][i - 1], dp[1][i - 2] + nums[i])  # 0
        else:
            # odd
            dp[0][i] = max(dp[0][i - 1], nums[i] + dp[0][i - 2])
            dp[1][i] = max(dp[1][i - 2] + nums[i], dp[1][i - 1], dp[2][i - 2])
            dp[2][i] = dp[2][i - 2] + nums[i] # ok
    print(max(dp[1][-1], dp[2][-3], dp[1][-2]))
    #print(dp)
