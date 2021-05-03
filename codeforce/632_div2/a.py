T = int(input())
for i in range(T):
    n, m = map(int, input().split())
    if n == 1:
        print('BWB' + (m - 3) * 'B')
    elif m == 1:
        print('\n'.join(['B', 'W', 'B']))
        for _ in range(n - 3):
            print('B')
    elif m == 2 and n == 2:
        print('BW\nBB')
    else:
        print('W' + (m - 1) * 'B')
        for i in range(n - 1):
            print('B' * m)
