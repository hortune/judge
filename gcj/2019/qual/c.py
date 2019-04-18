from math import gcd
T = int(input())

for i in range(T):
    N, L = list(map(int, input().split()))
    nums = list(map(int, input().split()))
    primes = []
    print("Case #{}: ".format(i+1), end='')
    the_prime = None
    the_index = None

    for index in range(L-1):
        if nums[index] != nums[index+1]:
            the_prime = gcd(nums[index],nums[index+1])
            the_index = index
            break
    
    front = []
    cur_prime = the_prime

    for index in range(the_index, -1, -1):
        cur_prime = nums[index] / cur_prime
        front.append(cur_prime)

    front = front[::-1]
    front.append(the_prime)
    cur_prime = the_prime
    
    for index in range(the_index+1,L):
        cur_prime = nums[index] / cur_prime
        front.append(cur_prime)
    
    primes = front
    n_primes = list(set(primes))
    n_primes.sort()
    

    for index in range(L+1):
        print(chr(n_primes.index(primes[index]) + ord('A')), end='')
    
    print("")
