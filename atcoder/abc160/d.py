n, x, y = map(int, input().split())
ans = [0]*n
x, y = min(x, y), max(x, y)

for i in range(1, n):
    for j in range(i+1, n+1):
        # calculate dist(i, j)
        dist = j - i
        dist = min(dist, abs(j - y) + abs(x - i) + 1)
        dist = min(dist, abs(j - x) + abs(y - i) + 1)
        ans[dist] += 1
print("\n".join(list(map(str, ans[1:]))))
