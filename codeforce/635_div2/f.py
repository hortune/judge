import sys
from math import floor

def c_print(*s):
    print(*s)
    sys.stdout.flush()

def get_res():
    return list(map(int, input().split()))


n = int(input())
c, p = get_res()

ans = [-1] * (n + 1)
prod = [-1] * (n + 1)
added = [0] * (n + 1)
for i in range(1, n+1):
    print('+', i)
    added[i] += 1
    tc, tp = get_res()
    if tc != c:
        num = (1 + floor((1 + 8 * (tc - c)) ** 0.5 + 0.1)) // 2
        ans[i] = num

    if tp != p:
        prod[i] = tp - p 
