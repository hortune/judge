T = int(input())
for _ in range(T):
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    has_neg = False
    has_pos = False
    gg = False
    pos_nums = [0] * len(A)
    neg_nums = [0] * len(A)
    for i in range(1, len(A)):
        pos_nums[i] = pos_nums[i - 1] + (A[i-1] > 0)
        neg_nums[i] = neg_nums[i - 1] + (A[i-1] < 0)

    for i in range(len(A) - 1, -1, -1):
        a = A[i]
        b = B[i]
        if a < b and pos_nums[i] == 0:
            gg = True
            break
        if a > b and neg_nums[i] == 0:
            gg = True
            break
    if gg:
        print('NO')
    else:
        print('YES')
