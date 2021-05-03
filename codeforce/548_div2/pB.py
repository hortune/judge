n = int(input())
nums = list(map(int, input().split()))

cur = 1e18
ans = 0
for idx in range(n-1, -1, -1):
    cur = min(cur-1, nums[idx])
    cur = max(0, cur)
    ans += cur
print(ans)
