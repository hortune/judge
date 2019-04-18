T = int(input())

for i in range(T):
    N = int(input())
    path = input().strip()
    print("Case #{}: ".format(i+1), end='')
    for ele in path:
        if ele == 'S':
            print('E', end='')
        else:
            print('S', end='')
    print("")
