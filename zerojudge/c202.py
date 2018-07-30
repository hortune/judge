from functools import reduce
from math import gcd
try:
    while True:
        n = int(input())
        nums = list(map(int,input().split()))
        print(reduce(gcd,nums))

except:
    pass
