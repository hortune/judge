from bisect import bisect_left


N = int(input())
ans = [0]
for i in range(70):
    ans.append(2*ans[-1]+1)

def get_upper_bound(num):
    return bisect_left(ans,num)


def get_ans(k,bound):
    last_len = (bound - 1) // 2
    if k == last_len or k == 0:
        return False
    elif k < last_len:
        return get_ans(k,last_len)
    else:
        return not get_ans(bound - 1 - k , last_len)

for case in range(1,N+1):
    num = int(input())
    upper_index = get_upper_bound(num)
    print("Case #%d:" % case, int(get_ans(num-1, ans[upper_index])))
