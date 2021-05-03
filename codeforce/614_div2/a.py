T = int(input())

for _ in range(T):
    n, s, k = map(int, input().split())
    close = set(map(int, input().split()))
    l_near = -1000000
    r_near = n + 100000000000

    s_clone = s
    while s_clone > 0:
        if s_clone not in close:
            l_near = s_clone
            break
        s_clone -= 1

    s_clone = s
    while s_clone <= n:
        if s_clone not in close:
            r_near = s_clone
            break
        s_clone += 1
    print(min(abs(r_near-s), abs(l_near-s)))
