nums = list(map(int, input().strip()))
nums = nums[::-1]
nums.append(0)
ans = 0
for i in range(len(nums) - 1):
    if nums[i] > 5:
        ans += 10 - nums[i]
        nums[i+1] += 1
    elif nums[i] == 5:
        if nums[i + 1] >= 5:
            nums[i + 1] += 1
        ans += 5
    else:
        ans += nums[i]
ans += nums[-1]
print(ans)
