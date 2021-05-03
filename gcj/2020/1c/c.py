T = int(input())
for case in range(1, T+1):
    n, d = map(int, input().split())
    nums = list(map(int, input().split()))
    nums.sort()
    # check how many
    counter = {}
    for num in nums:
        counter[num] = counter.get(num, 0) + 1
    
    if d == 3:
        ans = 2
        nums = sorted(list(counter.keys()))
        has_two = False
        for num in nums:
            if counter[num] == 3:
                ans = min(0, ans)
            elif num % 2 == 0 and num // 2 in counter:
                ans = min(1, ans)
            elif has_two:
                ans = min(1, ans)
            elif counter[num] == 2:
                has_two = True
        print('Case #{}: {}'.format(case, ans))
    else:
        ans = 1
        for num in counter:
            if counter[num] == 2:
                ans = min(0, ans)
        print('Case #{}: {}'.format(case, ans))
