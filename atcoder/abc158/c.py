from math import floor
a, b = map(int, input().split())

a_ = a // 0.08
b_ = b // 0.1

ans = min(floor(a_), floor(b_))

while floor(ans * 0.08) != a or floor(ans * 0.1) != b:
    ans += 1
    if floor(ans * 0.08) > a or floor(ans * 0.1) > b:
        print('-1')
        exit()
print(ans)
