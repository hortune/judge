from math import floor, pow
import sys
def get_res():
    while True:
        a = input().strip()
        if a != "":
            return int(a)

def send_query(n):
    print('?',n)
    sys.stdout.flush()
    return get_res()

MOD = floor(1e6 + 3)
primes = [2,3,5,7,11,13,17,19,23,29]
gaussian_arr = [[pow(j,i)%MOD for i in range(1,11)] for j in primes]

nums = []
constant = send_query(0)

if not constant:
    print('! 0')
    sys.stdout.flush()
    exit()

for prime in primes:
    nums.append((send_query(prime)-constant + MOD) % MOD)
    if not nums[-1]:
        print('!',prime)
        sys.stdout.flush()
        exit()

def ext_euclid(a, b):
     if b == 0:
         return 1, 0, a
     else:
         x, y, q = ext_euclid(b, a % b) # q = gcd(a, b) = gcd(b, a%b)
         x, y = y, (x - (a // b) * y)
         return x, y, q

def inv(n):
    res, _, _ = ext_euclid(n,MOD)
    return res

# Gaussian elimination

for i in range(10):
    # make the root 1
    mul = inv(gaussian_arr[i][i])
    for j in range(10):
        gaussian_arr[i][j] = (gaussian_arr[i][j] * mul) % MOD
    nums[i] = (nums[i] * mul) % MOD

    for row in range(i+1, 10):
        mul = gaussian_arr[row][i]
        for column in range(i, 10):
            gaussian_arr[row][column] = (((gaussian_arr[row][column] - 
                                        mul * gaussian_arr[i][column]) % MOD)
                                        + MOD) % MOD
        nums[row] = (((nums[row] - nums[i]*mul) % MOD) + MOD) % MOD

for i in range(9, -1, -1):
    # make the root 1
    
    for row in range(i-1, -1, -1):
        mul = gaussian_arr[row][i]
        for column in range(10):
            gaussian_arr[row][column] = (((gaussian_arr[row][column] - 
                                        mul * gaussian_arr[i][column]) % MOD)
                                        + MOD) % MOD
        nums[row] = (((nums[row] - nums[i]*mul) % MOD) + MOD) % MOD

# Validate

for num in range(MOD):
    sum_of_num = constant
    gg = num
    for i in range(1,11):
        sum_of_num += nums[i-1]*gg
        gg = (gg*num) % MOD
    
    if sum_of_num % MOD == 0:
        print('!',num)
        sys.stdout.flush()
        exit()
print('!',-1)
sys.stdout.flush()
