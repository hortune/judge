n = int(input())
nums = list(map(int, input().split()))

num_count = {}
for num in nums:
    num_count[num] = num_count.get(num, 0) + 1

total = 0
for num, ele in num_count.items():
    total += (ele * (ele - 1)) // 2

ans = []

for num in nums:
    ans.append(total - num_count[num] + 1)
print("\n".join(list(map(str, ans))))
