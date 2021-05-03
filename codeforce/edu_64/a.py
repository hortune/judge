n = int(input())
choice = list(map(int, input().split()))
num = 0
inf = 9129312939123
trans = [[inf, 3, 4], [3, inf, inf], [4, inf, inf]]
for i in range(1, n):
    num += trans[choice[i-1]-1][choice[i]-1]
    if i > 1 and choice[i] == 2 and choice[i-1] == 1 and choice[i-2] == 3:
        num -= 1

if num >= inf:
    print('Infinite')
else:
    print('Finite')
    print(num)
