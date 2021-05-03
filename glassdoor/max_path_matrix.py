#https://www.glassdoor.com/Interview/Coding-question-find-the-maximum-path-in-a-matrix-QTN_3674661.htm
# https://tutorialspoint.dev/data-structure/matrix-archives/maximum-path-sum-matrix

def find_max_sum(matrix):
    if len(matrix) == 0:
        return 0
    dp = [[0]*len(matrix[0]) for i in range(2)]
    cur = True
    for i in range(len(matrix)):
        last = not cur
        for j in range(len(matrix[0])):
            dp[cur][j] = max(dp[last][min(j+1, len(matrix[0]) - 1)],
                          dp[last][max(j-1, 0)],
                          dp[last][j]) + matrix[i][j]
        cur = last
    return max(dp[not cur])

if __name__ == "__main__":
    mat = [[10, 10, 2, 0, 20, 4],
           [1, 0, 0, 30, 2, 5],
           [0, 10, 4, 0, 2, 0],
           [1, 0, 2, 20, 0, 4]]
    assert(find_max_sum(mat) == 74)

    mat = [[1, 2, 3],
           [9, 8, 7],
           [4, 5, 6]]
    assert(find_max_sum(mat) == 17)
