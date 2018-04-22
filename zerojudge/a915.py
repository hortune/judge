from functools import cmp_to_key
c_cmp = cmp_to_key(lambda x, y: 1 if x[0] > y[0] else \
            -1 if x[0] != y[0] else \
            1 if x[1] > y[1] else -1)

n = int(input())

k = [list(map(int,input().split())) for _ in range(n)]


k.sort(key=c_cmp)
print("\n".join("{} {}".format(*a) for a in k))
