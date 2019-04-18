"""
"""

def backtrack(last_one, total, state, ans, nn):
    if len(ans) == total:
        return True
    
    if last_one != -1:
        l_m, l_n  = last_one // nn, last_one % nn
    else:
        l_m, l_n = -1, -9487

    for i in range(total):
        m, n = i // nn, i % nn
        if m + n  == l_m + l_n or \
                m - n == l_m - l_n  or \
                l_m == m or \
                l_n == n or \
                state[m][n]:
            continue

        ans.append((m+1, n+1))
        state[m][n] = 1
        if backtrack(i, total, state, ans, nn):
            return True
        ans.pop()
        state[m][n] = 0
    return False


def solve(m,n):
    clean = [[0]*n for i in range(m)]
    ans = []
    if backtrack(-1, m*n, clean, ans, n):
        return True, ans
    return False, ans

"""
for i in range(2,6):
    for j in range(i,6):
        print(i,j,solve(i,j))

"""
T = int(input())

for i in range(T):
    m, n = list(map(int, input().split()))

    if (m, n) in [(2,2), (2,3), (2,4), (3,3), (3,2), (4,2)]:
        print("Case #{}: IMPOSSIBLE".format(i+1))
        continue
    
    print("Case #{}: POSSIBLE".format(i+1))
    res, ans = solve(m,n)
    for ele in ans:
        print(*ele)
