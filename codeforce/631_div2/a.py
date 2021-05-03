T = int(input())
for _ in range(T):
    m, n = map(int, input().split())
    pool = set(list(map(int, input().split())))
    
    n_num = 0
    while n >= 0:
        n_num += 1
        if n_num not in pool:
            n -= 1
    print(n_num - 1)
