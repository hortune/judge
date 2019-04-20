# 注意array cache順序 QQ
from math import log, floor
import sys
"""
class RMQ:
    '''
    maximum version rmq

    query: max([l, r])
    '''
    
    def __init__(self, nums):
        size = floor(log(len(nums)) // log(2)) + 1
        self.nums = [nums]
        
        for i in range(1, size):
            last = self.nums[-1]

            delta = 1 << (i-1)
            self.nums.append([max(last[j], last[j + delta])
                              for j in range(len(nums) - 2 * delta + 1)]) 
    
    def query(self, l, r):
        delta = floor(log(r - l + 1) // log(2))
        
        return max(self.nums[delta][l], self.nums[delta][r-2**delta+1])
"""

n, m, q = map(int, sys.stdin.readline().split())
perms = list(map(int, sys.stdin.readline().split()))
nums = list(map(int, sys.stdin.readline().split()))

logit = floor(log(n) // log(2)) + 1

current_max_index = [-1]*(n+1)
prevs = [[-1]*m for i in range(logit)]


prev_map = [-2]*(n+1)

for i, j in zip(perms[1:]+[perms[0]], perms):
    prev_map[i] = j

# Update the one step case

for idx, ele in enumerate(nums):
    prevs[0][idx] = current_max_index[prev_map[ele]]
    current_max_index[ele] = idx

# Update the n_step table

for i in range(1, logit):
    for idx, ele in enumerate(nums):
        if prevs[i-1][idx] != -1:
            prevs[i][idx] = prevs[i-1][prevs[i-1][idx]]

prev_n = []

# Create the update sequence

use = [i for i in range(n.bit_length()) if 1 & (n - 1) >> i]
max_pre = -1
ran = [-1] * (m+2)
for i in range(m):
    t = i 
    for dim in use:
        t = prevs[dim][t]
        if t == -1:
            break
    max_pre = max(t, max_pre)
    ran[i] = max_pre

"""
for i in range(m):
    remain = n - 1
    idx = i
    while remain and idx != -1:
        ma = floor(log(remain) // log(2))
        idx = prevs[ma][idx]
        remain -= 2**ma
    prev_n.append(idx)
""" 

#rmq = RMQ(prev_n)

ans = [None]*q
for i in range(q):
    l, r = map(int, sys.stdin.readline().split())
    ans[i] = str(int(l - 1 <= ran[r-1]))
print("".join(ans))
