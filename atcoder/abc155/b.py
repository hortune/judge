n = int(input())
nums = list(map(int, input().split()))
res = True
for num in nums:
    if num % 2 == 0 and num % 3 != 0 and num % 5 != 0:
        res = False
if res:
    print('APPROVED')
else:
    print('DENIED')
