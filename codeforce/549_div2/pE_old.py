from math import log, floor
import sys
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


n, m, q = list(map(int, sys.stdin.readline().split()))
perms = list(map(int, sys.stdin.readline().split()))
nums = list(map(int, sys.stdin.readline().split()))

logit = floor(log(n) // log(2)) + 1

current_max_index = [-1]*(n+1)
prevs = [[-1]*m for i in range(logit)]

prev_map = {perms[i]:perms[i-1] for i in range(n)}

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

for i in range(m):
    remain = n - 1
    idx = i
    while remain and idx != -1:
        ma = floor(log(remain) // log(2))
        idx = prevs[ma][idx]
        remain -= 2**ma
    prev_n.append(idx)
    

rmq = RMQ(prev_n)

ans = []
for i in range(q):
    l, r = list(map(int, sys.stdin.readline().split()))
    if rmq.query(l-1, r-1) >= l-1:
        ans.append("1")
    else:
        ans.append("0")
print("".join(ans))
