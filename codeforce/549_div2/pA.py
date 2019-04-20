n = int(input())
nums = list(map(int, input().split()))

target = nums[-1]

for ele in range(n-2, -1, -1):
    if target != nums[ele]:
        print(ele + 1)
        break
else:
    print(0)
