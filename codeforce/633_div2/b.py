T = int(input())
for i in range(T):
    n = int(input())
    nums = list(map(int, input().split()))
    nums.sort()
    ans = []
    if len(nums) % 2 == 0:
        for i in range(len(nums) // 2):
            ans.append(nums[len(nums) // 2 + i])
            ans.append(nums[len(nums) // 2 - i - 1])
    else:
        ans.append(nums[len(nums) // 2])
        for i in range(len(nums) // 2):
            ans.append(nums[len(nums) // 2 + i + 1])
            ans.append(nums[len(nums) // 2 - i - 1])
    print(' '.join(list(map(str, ans))))
