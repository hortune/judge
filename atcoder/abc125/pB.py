n = int(input())
V = list(map(int, input().split()))
C = list(map(int, input().split()))

ans = 0

for i, j in zip(V,C):
    ans += max(0, i-j)
print(ans)
