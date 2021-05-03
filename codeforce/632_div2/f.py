n = int(input())
vis = [True] * (n + 1)
ans = []

count = n
deleted = [False] * (n + 2)
ans = [12312312312312] * (n + 2) 

for i in range(n, 1, -1):
    for j in range(2 * i, n+1, i):
        if not deleted[j]:
            deleted[j] = True
            count -= 1
    ans[count] = i - 1

for j in 
