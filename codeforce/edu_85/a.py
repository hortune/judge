T = int(input())
for _ in range(T):
    n = int(input())
    prev = 0
    gg = 0
    ggg = False
    for i in range(n):
        a, b = map(int, input().split()) 
        if not(prev <= a and gg <= b and b <= a and a - prev >= b - gg):
            ggg = True
        prev = a
        gg = b
    if ggg:
        print('NO')
    else:
        print('YES')

