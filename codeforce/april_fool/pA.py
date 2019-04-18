n = int(input())
nums = list(map(int,input().split()))

def solve(l, r):
    if r - l == 1:
        return 1
    l_ans, r_ans = solve(l, (l+r)//2), solve((l+r)//2, r)
    
    if l_ans == r_ans and l_ans == (r - l)//2 and nums[(l+r)//2-1] <= nums[(l+r)//2]:
        return l_ans + r_ans
    return max(l_ans, r_ans)


print(solve(0,n))
