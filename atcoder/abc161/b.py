n, m = map(int, input().split())
nums = list(map(int, input().split()))

can = 0
total = sum(nums)
for num in nums:
    if num * 4 * m  >= total:
        can += 1
if can >= m:
    print('Yes')
else:
    print('No')
