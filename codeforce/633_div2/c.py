T = int(input())
for i in range(T):
    n = int(input())
    nums = list(map(int, input().split()))
    pre_max = nums[0]
    ans = 0
    for i in range(1, n):
        ans = max(ans, max(pre_max - nums[i], 0))
        pre_max = max(nums[i], pre_max)
    print(int.bit_length(ans))
