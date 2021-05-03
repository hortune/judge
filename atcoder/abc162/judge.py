from random import randint
import os
while True:
    T = randint(1, 10)  + 1
    nums = [randint(-1000, 1000) for i in range(T)]
    print(nums)
    with open('INPUT', 'w') as fd:
        print(T, file=fd)
        print(*nums, file=fd)
    os.system('python f.py < INPUT > O2')
    os.system('python f_oracle.py < INPUT > O1')
    if open('O1').read() != open('O2').read():
        exit()
