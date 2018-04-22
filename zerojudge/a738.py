try:
    def gcd(a,b):
        while b != 0:
            a %= b
            a, b = b, a
        return a
    while True:
        a, b = list(map(int,input().split()))
        print(gcd(a,b))
except:
    pass
