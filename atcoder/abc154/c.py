n = int(input())
nums = list(map(int, input().split()))
if len(nums) == len(set(nums)):
    print('YES')
else:
    print('NO')
