def gcd(a,b):
    while b:
        a %= b
        a,b = b,a
    return a

n = int(input())

for _ in range(n):
    k = list(map(int,input().split()[1:]))

    if len(k) == 0:
        print(k[0])
    else:
        ans = k[0]
        for i in k[1:]:
            ans = gcd(ans,i)
        print(ans)
