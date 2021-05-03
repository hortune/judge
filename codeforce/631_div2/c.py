n, m = map(int, input().split())
nums = list(map(int, input().split()))
ans = []

if sum(nums) < n:
    print(-1)
    exit()
delta = sum(nums) - n
cur_sum = 1
for idx, num in enumerate(nums):
    if n - idx - num + 1 <= 0:
        print(-1)
        exit()

pre_budget = 0
for idx, num in enumerate(nums):
    if delta and pre_budget:
        cur_sum -= min(pre_budget, delta)
        delta -= min(pre_budget, delta)
    ans.append(cur_sum)
    pre_budget = num - 1
    cur_sum += num
print(' '.join(list(map(str, ans))))
