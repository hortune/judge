"""
l = gk + a + b
start location
- a

l = gk + a - b
start location
- a

l = gk - a - b
start location
a


l = gk - a + b
start location
a + q*l  mod k 


a - qa + b mod k

lcm(- a + b, k) // k

count the four possibility
"""

n, k = list(map(int, input().split()))
a, b = list(map(int, input().split()))



# First Case 
# l = gk + a + b
# start = -a

start = -a

# solve -a + q*(a + b)  mod k
ans = -1
for i in range(k):
