T = int(input())
for _ in range(T):
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))

    initial = 0

    for i in range(1, k-1):
        if nums[i+1] < nums[i] > nums[i-1]:
            initial += 1

    ans = initial
    l = 0
    for i in range(1, n - k + 1):
        if nums[i+1] < nums[i] > nums[i - 1]:
            initial -= 1
        if nums[i + (k - 1)] < nums[i + k - 2] > nums[i + (k - 3)]:
            initial += 1
        if initial > ans:
            ans = initial
            l = i
    print(ans + 1, l + 1)
