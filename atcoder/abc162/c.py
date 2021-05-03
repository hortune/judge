from math import gcd
k = int(input())
anss = []
ans = 0
res = [[[0] * 201 for i in range(201)] for j in range(201)]
for k in range (1, 201):
    for j in range(1, 201):
        for q in range(1, 201):
            res[k][j][q] = gcd(gcd(k, j), q)
for k in range(1, 201):
    ans = 0
    print(k)
    for i in range(1, k+1):
        for j in range(1, k+1):
            for q in range(1, k+1):
                ans += res[i][j][q]
    anss.append(ans)

print(anss)
