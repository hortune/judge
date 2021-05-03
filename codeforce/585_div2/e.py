# Num of the element
import sys
input = sys.stdin.readline
N_Color = 20
INT_max = 10**30
R = {(1 << i):i for i in range(20)}

def calc(locs):
    # calc move all j in front of i cost
    dp = [[0]*N_Color for i in range(N_Color)]
    for i in range(N_Color):
        for j in range(N_Color):
            x, y = locs[i], locs[j]
            idx = 0
            if i == j or len(x) == 0 or len(y) == 0: continue
            for ele in y:
                while idx < len(x) and x[idx] < ele:
                    idx += 1
                dp[j][i] += idx
    return dp

def solve(swap_cost):
    dp = [INT_max] * ((1<<N_Color))
    dp[0] = 0
    # Push is faster than pull, for the renumerate issue
    for perm in range(0, (1<<N_Color)-1):
        perm_bak = perm
        used = [i for i in range(N_Color) if (1<<i) & perm]
        not_used = [i for i in range(N_Color) if not (1<<i) & perm]
        for ele in not_used:
            n_method = 0
            for use_ele in used:
                n_method += swap_cost[ele][use_ele]
            dp[perm | (1<<ele)] = min(n_method + dp[perm], dp[perm | (1<<ele)])
        """
        while perm & (-perm):
            color = perm & (-perm)
            perm -= color
            sub_perm_bak = sub_perm = perm_bak - color
            n_method = 0
            while sub_perm & (-sub_perm):
                color_new = sub_perm & (-sub_perm)
                n_method += swap_cost[R[color_new]][R[color]]
                sub_perm -= color_new
            dp[perm_bak] = min(n_method + dp[sub_perm_bak], dp[perm_bak])
        """
    return dp[(1<<N_Color) - 1]

if __name__ == "__main__":
    n = int(input())
    nums = list(map(int, input().split()))
    locs = [[] for i in range(N_Color)]

    for idx, ele in enumerate(nums):
        locs[ele-1].append(idx)

    swap_cost = calc(locs)
    #print(swap_cost)
    ans = solve(swap_cost)
    
    print(ans)
