from math import floor, sqrt
n = floor(sqrt(2e9))
prime_table = [1]*(n+1)
prime_table[2] = 1
primes = []

for i in range(2,len(prime_table)):
    if prime_table[i]:
        primes.append(i)
        q = 2*i
        while q <= n:
            prime_table[q] = 0
            q += i

try:
    while True:
        n = int(input())
        ans = 0
        
        for prime in primes:
            while n % prime == 0:
                n //= prime
                ans += prime

        if n != 1:
            ans += n
        print(ans)
except:
    pass
