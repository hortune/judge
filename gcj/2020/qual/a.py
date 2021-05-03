T = int(input())
for idx in range(T):
    n = int(input())
    matrix = []
    for i in range(n):
        matrix.append(list(map(int, input().split())))
    trace = 0
    for i in range(n):
        trace += matrix[i][i]
    rep_row = 0
    for i in range(n):
        count = [0] * (n + 1)
        for j in range(n):
            if count[matrix[i][j]]:
                rep_row += 1
                break
            count[matrix[i][j]] += 1

    rep_col = 0
    for i in range(n):
        count = [0] * (n + 1)
        for j in range(n):
            if count[matrix[j][i]]:
                rep_col += 1
                break
            count[matrix[j][i]] += 1
    print('Case #{}: {} {} {}'.format(idx+1, trace, rep_row, rep_col))
