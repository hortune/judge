C = int(input())
for c in range(C):
    input() # for white space
    dp_base = [False] * 20001
    budget = int(input())
    n_flavor = int(input())
    flavors = [int(input().split()[1]) for _ in range(n_flavor)]
    n_option = int(input())
    options = [int(input().split()[1]) for _ in range(n_option)]

    ans = -123123123
    for flavor in flavors:
        dp_base[flavor] = True
        if abs(ans - budget) > abs(flavor - budget) or\
           (abs(ans - budget) == abs(flavor - budget) and flavor < ans):
            ans = flavor

    if n_option > 1:
        for i in range(n_option):
            for j in range(i+1, n_option):
                dp = [False] * 20001
                for ele in range(20000, options[i] - 1, -1):
                    dp[ele] = dp_base[ele-options[i]] | dp_base[ele]
                for ele in range(20000, options[j] - 1, -1):
                    dp[ele] = dp[ele-options[j]] | dp[ele]
                for ele in range(20001):
                    if dp[ele] and (
                       abs(ans - budget) > abs(ele - budget) or\
                       (abs(ans - budget) == abs(ele - budget) and ele < ans)):
                        ans = ele
    else:
        for i in range(n_option):
            dp = [False] * 20001
            for ele in range(20000, options[i] - 1, -1):
                dp[ele] = dp_base[ele-options[i]] | dp_base[ele]
            for ele in range(20001):
                if dp[ele] and (
                   abs(ans - budget) > abs(ele - budget) or\
                   (abs(ans - budget) == abs(ele - budget) and ele < ans)):
                    ans = ele
                    ans = ele
    print('Case #{}: {}'.format(c+1, ans))
