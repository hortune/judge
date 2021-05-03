n = int(input())
nums = list(map(int, input().split()))

total = 0
smallest = 9999999999999999999999999999999
counter = 0
for i in range(n):
    total += abs(nums[i])
    smallest = min(smallest, abs(nums[i]))
    if nums[i] < 0:
        counter += 1

if counter % 2 == 0:
    print(total)
else:
    print(total - 2*smallest)
