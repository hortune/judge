S, T = input().split()
a, b = map(int, input().split())
u = input().strip()
if u == S:
    a -= 1
if u == T:
    b -= 1
print(a,b)
