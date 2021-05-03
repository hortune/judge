def check_delete_height(i, nums):
    if 2 * i >= len(nums) or (nums[2*i] == 0 and nums[2*i + 1] == 0):
        return int.bit_length(i)
    if nums[2*i] == 0:
        return check_delete_height(2*i + 1, nums)
    if nums[2*i + 1] == 0:
        return check_delete_height(2*i, nums)
    if nums[2*i + 1] > nums[2*i]:
        return check_delete_height(2*i + 1, nums)
    return check_delete_height(2*i, nums)


def f(i, nums, count):
    if 2 * i >= len(nums) or (nums[2*i] == 0 and nums[2*i + 1] == 0):
        if nums[i // 2] != nums[i]:
            nums[i] = 0
    else:
        if nums[2*i] > nums[2*i + 1]:
            nums[i] = nums[2 * i]
            f(2 * i, nums, count)
        else:
            nums[i] = nums[2 * i + 1]
            f(2 * i + 1, nums, count)
        count[nums[i]] = i

    


T = int(input())
for i in range(T):
    n, m = map(int, input().split())
    nums = list(map(int, input().split()))
    nums.insert(0, 0)
    counts = [0] * len(nums)
    for idx, num in enumerate(nums):
        counts[num] = idx
    ans = []
    for i in range(len(counts)-1, 0, -1):
        if check_delete_height(counts[i], nums) > m:
            counts[nums[i]] = 0
            f(counts[i], nums, counts)
            ans.append(i)
    print(len(nums) * (len(nums) + 1) // 2 - sum(ans))
    print(' '.join(map(str, ans)))
