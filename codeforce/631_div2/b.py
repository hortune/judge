T = int(input())
for _ in range(T):
    n = int(input())
    nums = list(map(int, input().split()))
    m_num = max(nums)
    count = [0] * (n + 1)
    gg = False
    for i in range(m_num):
        count[nums[i]] += 1
        if count[nums[i]] > 1:
            gg = True

    count = [0] * (n + 1)
    for i in range(m_num, n):
        count[nums[i]] += 1
        if count[nums[i]] > 1 or nums[i] > n - m_num:
            gg = True

    count = [0] * (n + 1)
    gg1 = False
    for i in range(n - m_num):
        count[nums[i]] += 1
        if count[nums[i]] > 1 or nums[i] > n - m_num:
            gg1 = True

    count = [0] * (n + 1)
    for i in range(n - m_num, n):
        count[nums[i]] += 1
        if count[nums[i]] > 1:
            gg1 = True
    if m_num ==  n - m_num and not gg:
        print(1)
        print(m_num, m_num)
        continue
    print(2 - gg - gg1)
    if not gg:
        print(m_num, n - m_num)
    if not gg1:
        print(n - m_num, m_num)
