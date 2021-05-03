if __name__ == '__main__':
    n, dist = map(int, input().split())
    light = input()
    right_cover = 0
    left_most = [-1]*(n)
    for idx, ele in enumerate(light):
        if ele == '1':
            for i in range(max(right_cover, idx-dist), min(idx + dist + 1, n)):
                left_most[i] = idx
            right_cover = idx + dist + 1
    dp = [0]*(2*n+1)
    for idx in range(n-1, -1, -1):
        dp[idx] = dp[idx+1] + idx + 1
        if left_most[idx] != -1:
            left = left_most[idx]
            dp[idx] = min(dp[idx+1] + left + 1, dp[idx])
    print(dp[0])
