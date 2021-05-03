# https://www.glassdoor.com/Interview/Giving-you-an-array-you-need-to-find-the-subarray-which-the-sum-is-maximum-QTN_3695459.htm
def max_sub_sum(array):
    max_value = array[0]
    prefix_min = 0
    prefix_sum = 0
    for num in array:
        prefix_sum += num
        prefix_min = min(prefix_min, prefix_sum)
        max_value = max(max_value, prefix_sum - prefix_min)
    return max_value

if __name__ == '__main__':
    assert(max_sub_sum([1,2,3,4]) == 10)
    assert(max_sub_sum([3, -2, 4, 4]) == 9)
    assert(max_sub_sum([3, -4, 2, 2]) == 4)
