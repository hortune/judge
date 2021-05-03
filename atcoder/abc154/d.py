n, k = map(int, input().split())
nums = list(map(int, input().split()))

ans =  sum(nums[:k])
pre_sum = ans

for i in range(0, len(nums) - k):
    pre_sum -= nums[i]
    pre_sum += nums[i + k]
    ans = max(pre_sum, ans)
print((ans + k) / 2)
