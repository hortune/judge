total, N = map(int, input().split())
nums = list(map(int, input().split()))
if N == 1:
    print(0)
else:
    ans = total - (total - nums[-1] + nums[0])
    prev = nums[0]
    for num in nums[1:]:
        ans = min(total-(num - prev), ans)
        prev = num
    print(ans)
