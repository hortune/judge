T = int(input())
for case in range(1, T+1):
    M, N, seq = input().split()
    M = int(M)
    N = int(N)
    ans = None
    for time, move in enumerate(seq, 1):
        if move == 'S':
            N -= 1
        elif move == 'N':
            N += 1
        elif move == 'E':
            M += 1
        else:
            M -= 1

        if (abs(M) + abs(N)) <= time:
            ans = time
            break

    if ans is None:
        print('Case #{}:'.format(case), "IMPOSSIBLE")
    else:
        print('Case #{}: {}'.format(case, ans))
