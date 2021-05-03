import sys
input = sys.stdin.readline
T = int(input())
fans = []
for _ in range(T):
    ans = 0
    A = []
    B = []
    n = int(input())
    for i in range(n):
        a, b = map(int, input().split())
        A.append(a)
        B.append(b)
    
    for i in range(n):
        B[i] = min(B[i], A[(i + 1) % n])
    
    for i in range(n):
        ans += A[i] - B[(i - 1 + n) % n]
    fans.append(str(ans + min(B)))
print('\n'.join(fans))
