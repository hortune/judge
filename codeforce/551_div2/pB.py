m, n, h = list(map(int, input().split()))
fronts = list(map(int, input().split()))
rows = list(map(int, input().split()))

nums = []

for i in range(m):
    row = []
    for idx, j in enumerate(list(map(int, input().split()))):
        if j == 1:
            row.append(min(fronts[idx], rows[i]))
        else:
            row.append(0)
    nums.append(row)
for ele in nums:
    print(*ele)
