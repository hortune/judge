# 注意 MOD負
from math import log, floor
MOD = floor(1e9 + 7)
def sum_of(n):
    if n == 0:
        return 0
    # find the largest i such that 1 + 2 + 4 ..... + 2^(i-1) <= n
    i = floor(log(n+1) / log(2))

    # the last term of first set
    # 1 3 5 7 9 ... 
    # 1 + 4 + 16 ...
    len_1 = (4**((i + 1) // 2 ) - 1) // 3
    len_2 = 2*(4**(i // 2) - 1) // 3

    if i % 2 == 0:
        len_1 += n - 2**i + 1
    else:
        len_2 += n - 2**i + 1
    len_1 %= MOD
    len_2 %= MOD
    sum_of_1 = ((1 + 1 + 2*(len_1-1)) * len_1) // 2
    sum_of_2 = ((2 + 2 + 2*(len_2-1)) * len_2) // 2
    return (sum_of_1 + sum_of_2) % MOD

n, m = list(map(int, input().split()))

print((sum_of(m) - sum_of(n-1) + MOD) % MOD)

