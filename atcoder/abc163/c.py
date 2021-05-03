n = int(input())
nums = list(map(int, input().split()))

childs = [0] * n
for num in nums:
    childs[num - 1] += 1
print('\n'.join(list(map(str, childs))))
