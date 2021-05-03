n, m = map(int, input().split())
print(min(n % m, abs((n % m) - m)))
