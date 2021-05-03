# 3, 4, -1, 5, -11, 11
n = int(input())
nums = list(map(int, input().split()))
pre_sum = [0] * len(nums)
pre = 0
for idx, num in enumerate(nums):
    pre += num
    pre_sum[idx] = pre

count = {}
for idx, num in enumerate(pre_sum):
    if num != 0:
        count[num] = count.get(num, [])
    else:
        count[num] = count.get(num, [-1])
    count[num].append(idx)

intervals = []

for num in count:
    if len(count[num]) > 1:
        for i in range(len(count[num]) - 1):
            intervals.append((count[num][i] + 1, count[num][i + 1]))

intervals.sort(key=lambda x: x[1])
cur_inter = 0
ans = 0
for i in range(n):
    while cur_inter < len(intervals) and i > intervals[cur_inter][0]:
        cur_inter += 1

    if cur_inter == len(intervals):
        ans += n - i
    else:
        ans += intervals[cur_inter][1] - i
print(ans)

