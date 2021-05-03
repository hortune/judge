import sys
input = sys.stdin.readline

def preprocess():
    num_len = [0]
    s_num_len = [0]
    cur_len = 1
    next_num = 10

    for i in range(1, 50000):
        if i == next_num:
            cur_len += 1
            next_num *= 10
        num_len.append(num_len[-1] + cur_len)
        s_num_len.append(cur_len)

    return num_len, s_num_len

def query(num, num_len, s_num_len):
    i = 1
    while num_len[i] <= num:
        num -= num_len[i]
        i += 1
    if num == 0:
        return str(i-1)[-1]

    i = 1
    while s_num_len[i] <= num:
        num -= s_num_len[i]
        i += 1
    if num == 0:
        return str(i-1)[-1]

    return str(i)[num-1]


    
        

if __name__ == '__main__':
    num_len, s_num_len = preprocess()
    n = int(input())
    ans = []
    for i in range(n):
        num = int(input())
        ans.append(query(num, num_len, s_num_len))
    print('\n'.join(ans))
