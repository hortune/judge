n, m = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort()
valid = [True]*len(nums)
l, r = 0, 1

ans = 0
while r < len(nums):
    if not valid[l]:
        l += 1
        r = max(l+1, r)
    elif (not valid[r]) or (nums[r] - nums[l]) < m:
        r += 1
    else:
        ans += 1
        valid[l] = False
        valid[r] = False
print(ans)
