nums1 = list(map(int,input().split()))
nums2 = list(map(int,input().split()))


def find_s(nums, m):
    i, j = 0, len(nums)
    while j - i > 1:
        if nums[(j - i)//2]
    return 

def find_median(nums1,nums2):

    r = max(nums1[-1],nums2[-1])
    l = min(nums1[0],num2[0])
    m = (r + l) / 2

    while True: 
        samount = find_s(nums1,m) + find_s(nums2,m)
        lamount = find_l(nums1,m) + find_l(nums2,m)
        if abs(lamount - samount) < 2:
            break
        
        if lamount < samount:
            l, m, r = l, (m + l)/2, m
        else:
            l, m, r = m, (m + r)/2, r
    return s1,e1,s2,e2

Q = find_median(nums1,nums2)
