n = int(input())
amount = list(map(int,input().split()))
ans = 0
for index, a in enumerate(amount):
    ans += (index+1)*a
print(ans)
