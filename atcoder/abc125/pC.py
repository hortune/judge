def gcd(a, b):
    while b:
        a %= b
        a, b = b, a
    return a


n = int(input())
nums = list(map(int, input().split()))

prefix_gcd = []

prefix_gcd.append(nums[0])

for i in nums[1:]:
    prefix_gcd.append(gcd(i,prefix_gcd[-1]))

postfix_gcd = []
postfix_gcd.append(nums[-1])

for j in range(n-2,-1,-1):
    postfix_gcd.append(gcd(nums[j],postfix_gcd[-1]))

postfix_gcd = postfix_gcd[::-1]

ans = 1

for i in range(n):
    # del i
    if i == 0:
        ans = max(ans,postfix_gcd[i+1])
    elif i == n-1:
        ans = max(ans,prefix_gcd[i-1])
    else:
        ans = max(ans, gcd(prefix_gcd[i-1], postfix_gcd[i+1]))
print(ans)
