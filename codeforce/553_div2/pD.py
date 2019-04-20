# 思考 (5,5)的移動，發現沒差...
# 所以用delta去sort

n = int(input())
nums = []
for i in range(n):
    nums.append(list(map(int, input().split())))

nums.sort(key=lambda x : x[1] - x[0])
ans = 0

for idx, ele in enumerate(nums):
    ans += idx*ele[0] + (n - idx - 1) * ele[1]
print(ans)
