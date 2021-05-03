import os
from random import randint
while True:
    with open('INPUT', 'w') as fd:
        print(10, file=fd)
        for i in range(2, 11):
            print(randint(1, i - 1), i, file=fd)
    os.system('python d.py < INPUT')
