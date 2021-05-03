n = int(input())
nums = list(map(int,input()))

ans = 0
for idx, ele in enumerate(nums):
    if ele % 2 == 0:
        ans += idx + 1
print(ans)
