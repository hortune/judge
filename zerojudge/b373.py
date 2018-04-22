from functools import cmp_to_key
from sys import stdin
class tree_array:
    def __init__(self,n):
        self.array = [0]*(n+1)

    def sum(self, end):
        ret = 0
        while end > 0:
            ret += self.array[end]
            end -= (end & (-end))
        return ret

    def update(self, pos, value):
        while pos < (len(self.array)):
            self.array[pos] += value
            pos += (pos&(-pos))


all_input = list(map(int,stdin.read().split()))
n = all_input[0]

nums = list(enumerate(all_input[1:]))

nums.sort(key = cmp_to_key(lambda x,y : -1 if x[1] >= y[1] else 1))

k = tree_array(n)
ans = 0
for pos, value in nums:
    ans += k.sum(pos+1)
    k.update(pos+1,1)

print(ans)
