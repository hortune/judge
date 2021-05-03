import sys
input = sys.stdin.buffer.read
class GetInt:
    def __init__(self):
        self.nums = list(map(int, input().split()))
        self.n_idx = -1
    
    def get(self):
        self.n_idx += 1
        return self.nums[self.n_idx]

inp = GetInt()

T = inp.get()
fans = []
for _ in range(T):
    ans = 0
    A = []
    B = []
    n = inp.get()
    for i in range(n):
        a, b = inp.get(), inp.get()
        A.append(a)
        B.append(b)
    
    for i in range(n):
        B[i] = min(B[i], A[(i + 1) % n])
    
    for i in range(n):
        ans += A[i] - B[(i - 1 + n) % n]

    fans.append(str(ans + min(B)))
print('\n'.join(fans))