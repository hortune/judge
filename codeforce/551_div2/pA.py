m, n = list(map(int,input().split()))
num = []
for i in range(m):
    num.append(list(map(int,input().split())))

index, ans = -1, 214748364712
for idx, ele in enumerate(num):
    if ele[0] >= n and ele[0] < ans:
        index, ans = idx, ele[0]
    elif n >= ele[0]:
        if (n - ele[0]) % ele[1] == 0:
            index, ans = idx, n
        else:
            res = (((n - ele[0]) // ele[1]) + 1 )* ele[1] + ele[0]
            if res < ans:
                index, ans = idx, res
print(index+1)
