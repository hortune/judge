N, A, B = map(int, input().split())

a = N // (A + B)
print(a * A + (min(N % (A+B), A)))
