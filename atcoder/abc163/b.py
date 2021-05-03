n, m = map(int, input().split())
nums = list(map(int, input().split()))
total = sum(nums)
if n - total >= 0:
    print(n - total)
else:
    print(-1)
