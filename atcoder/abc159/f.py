N, S = map(int,input().split())
nums = list(map(int, input().split()))
records = [0]*(S + 1)

records[0] = 1
ans = 0
for num in nums:
    for i in range(S, num-1, -1):
        records[i] += records[i-num]
    ans += records[-1]
print(ans)
records = [0]*(S + 1)
records[0] = 1
for num in reversed(nums):
    for i in range(S, num-1, -1):
        records[i] += records[i-num]
    ans += records[-1]
print(ans)
