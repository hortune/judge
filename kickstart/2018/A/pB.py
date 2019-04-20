def binary_search(ele, array):
    l, r = 0, len(array)
    
    while r - l > 1:
        mid = (r + l) // 2
        if array[mid] >= ele:
            r = mid
        else:
            l = mid
    
    if array[l] >= ele:
        return l
    else:
        return l + 1

T = int(input())

for idx in range(T):
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    nums.sort()
    
    E = [sum(nums) / n]
    
    prefix_sum = []
    sum_num = 0
    for num in nums:
        sum_num += num
        prefix_sum.append(sum_num)

    for i in range(1, k+1):
        index = binary_search(E[-1], nums) # find the first larger_equal to nums
        if index > 0:
            partition = prefix_sum[-1] - prefix_sum[index - 1]
        else:
            partition = prefix_sum[-1]

        E.append(index / n  * E[-1] +  partition / n)

    print("Case #{}: {:.8f}".format(idx+1, E[-1]))
