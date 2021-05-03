from math import log, exp
T = int(input())
jie = [1, 1]
for i in range(2, 601):
    jie.append(i * jie[-1])

for idx in range(1, T+1):
    W, H, L, U, R, D = map(int, input().split())
    if L == 1 and U == 1:
        print('Case #{}: {}'.format(idx, 0))
    elif R == W and D == H:
        print('Case #{}: {}'.format(idx, 0))
    elif L == 1 and R == W:
        print('Case #{}: {}'.format(idx, 0))
    elif U == 1 and D == H:
        print('Case #{}: {}'.format(idx, 0))
    else:
        delta = 1
        up = 0
        counter = 0
        cur = 1
        init = True
        cur_low = 1
        while (L - delta) > 0 and (D + delta) <= H:
            if init:
                for i in range(L + D - 2, max(D + delta - 1, 0), -1):
                    cur *= i
                for i in range(W + H - (L + D), max(H - (D + delta), 0), -1):
                    cur_low *= i
                for j in range(2, L - delta):
                    cur //= j
                for j in range(2, W - (L - delta) + 1):
                    cur_low //= j
                up = cur * cur_low
                init = False
            else:
                cur *= max(L - delta, 1)
                cur //= max(D + delta - 1, 1)
                cur_low //= max(W - (L - delta) + 1, 1)
                cur_low *= max(H - (D + delta), 1)
                up += cur * cur_low
            delta += 1

        delta = 1
        down = 0
        counter = 0
        cur = 1
        cur_low = 1
        init = True
        while (R + delta) <= W and (U - delta) > 0:
            if init:
                for i in range(R + U - 2, max(R + delta - 1, 0), -1):
                    cur *= i
                for i in range(W + H - (R + U), max(W - (R + delta), 0), -1):
                    cur_low *= i
                for j in range(2, U - delta):
                    cur //= j
                for j in range(2, H - (U - delta) + 1):
                    cur_low //= j
                down = cur * cur_low
                init = False
            else:
                cur *= max(U - delta, 1)
                cur //= max(R + delta - 1, 1)
                cur_low *= max(W - (R + delta) + 1, 1)
                cur_low //= max(H - (U - delta), 1)
                down += cur * cur_low
            delta += 1
        print('jie', jie[W-1], jie[H-1], jie[W + H - 2])
        print("Case #{}: {}".format(idx, (up + down) / (jie[W + H - 2] / (jie[W - 1] * jie[H - 1]))))
        """
        up_sum = up * pow(10, 7) // pow(2, L + D - 2)
        down_sum = down * pow(10, 7) // pow(2, R + U - 2)
        up_sum
        print('Case #{}: {}.{:07d}'.format(idx, (up_sum + down_sum) // pow(10, 7),
                                            (up_sum + down_sum) % pow(10, 7)))
        """
