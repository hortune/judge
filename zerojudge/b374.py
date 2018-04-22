from functools import cmp_to_key
n = int(input())
nums = list(map(int,input().split()))


count = {}
for num in nums:
    count[num] = count[num]+1 if num in count else 1

ans = sorted(list(count.items()),key= cmp_to_key( \
            lambda x,y : -1 if x[1] > y[1] else \
                        1 if x[1] != y[1] else \
                    1 if x[0] > y[0] else -1))

max_y = ans[0][1]

for x, y in ans:
    if y < max_y:
        break
    print("{} {}".format(x,y))
