from random import randint
T = 100
print(T)


for i in range(T):
    n = randint(1,100000)
    k = randint(0, 1)
    print(n,k)
    print(" ".join([ str(randint(1,1000000000)) for i in range(n)]))
