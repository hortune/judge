n, k = map(int, input().split())
nums = list(map(int, input().split()))

neg_nums = []
pos_nums = []
nums.sort()
for num in nums:
    if num < 0:
        neg_nums.append(num)
    else:
        pos_nums.append(num)
l = -1231232132131232112213
r = 12312321321312312312


def cost_k(m):
    cur_k = 0
    l_pos, r_pos = 0, len(pos_nums) - 1
    while l_pos < r_pos:
        if pos_nums[l_pos] * pos_nums[r_pos] <= m:
            cur_k += r_pos - l_pos
            l_pos += 1
        else:
            r_pos -= 1
    l_neg, r_neg = 0, len(neg_nums) - 1
    while l_neg < r_neg:
        if neg_nums[l_neg] * neg_nums[r_neg] <= m:
            cur_k += r_neg - l_neg
            r_neg -= 1
        else:
            l_neg += 1
    l_pos, l_neg = 0, 0
    while l_pos < len(pos_nums) and l_neg < len(neg_nums):
        if neg_nums[l_neg] * pos_nums[l_pos] <= m:
            cur_k += len(pos_nums) - l_pos
            l_neg += 1
        else:
            l_pos += 1
    return cur_k


while r - l > 1:
    m = (r + l) // 2
    # pos pos
    # neg neg
    # neg pos
    cur_k = cost_k(m)
    if cur_k < k:
        l = m
    else:
        r = m
print(r)
