T = int(input())
for _ in range(T):
    n, x = map(int, input().split())
    nums = list(map(int, input().split()))
    nums.sort(key=lambda x: -x)
    i = 0
    cum = 0
    while i < len(nums) and nums[i] >= x:
        cum += nums[i] - x
        i += 1
    while i < len(nums) and cum >= x - nums[i]:
        cum -= (x - nums[i])
        i += 1
    print(i)
