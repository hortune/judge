from math import gcd

n, m = map(int,input().split())
ns = list(map(int, input().split()))
ps = list(map(int, input().split()))


gcds = ns[1]-ns[0]
for i in range(1,n-1):
    gcds = gcd(gcds, ns[i+1] - ns[i])


for idx, p in enumerate(ps):
    if gcds % p == 0:
        print("YES")
        print(ns[0], idx+1)
        exit()
print("NO")
