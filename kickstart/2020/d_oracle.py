from random import randint
import sys
T = 10
print(T)
jie = [1, 1]
for i in range(2, 301):
    jie.append(jie[-1] * i)
m_num = 10
for idx in range(1, T+1):
    W = randint(1, m_num)
    H = randint(1, m_num)
    L = randint(1, W)
    U = randint(1, H)
    R = randint(L, W)
    D = randint(U, H)
    print(W, H, L, U, R, D)
    dp = [[0] * W for _ in range(H)]
    dp[0][0] = 1
    L -= 1
    U -= 1
    R -= 1
    D -= 1
    for i in range(H):
        for j in range(W):
            if not ( L <= j <= R  and U <= i <= D):
                if i > 0:
                    dp[i][j] += (1 - (L <= j <= R and U <= i - 1 <= D)) * dp[i-1][j]
                if j > 0:
                    dp[i][j] += (1 - (L <= j - 1 <= R and U <= i <= D)) * dp[i][j-1]
    print(W, H, L, U, R, D, file=sys.stderr)
    print('Oracle Case #{}: {}'.format(idx, dp[-1][-1]), file=sys.stderr)
    #print(f'Oracle Case #{idx}: {dp[-1][-1] / jie[U + D]}', file=sys.stderr)
