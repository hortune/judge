n = input().strip()
n = list(map(int, n))

ans = 0
cum = 1
if n[0] == 1:
    ans = 9**(len(n)-1)
for idx, num in enumerate(n):
    if num:
        ans = max(ans, cum * (num - 1) * (9**(len(n) - idx - 1)))
    cum *= num

ans = max(cum, ans)
print(ans)
