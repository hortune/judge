n = int(input())
for idx in range(n):
    num = input()
    split_num = list(map(int,num))
    ans = 0
    for i, ele in enumerate(split_num):
        if ele % 2 == 1:
            if ele == 9 and i != len(split_num) - 1:
                ans = int(num[i:]) - int("{}".format(ele-1) + "8"*(len(split_num) - i - 1))
                break
            elif i != len(split_num) -1:
                res1 = int(num[i:]) - int("{}".format(ele-1) + "8"*(len(split_num) - i - 1))
                res2 = 10**(len(split_num) - i - 1) - int(num[i+1:])
                ans = min(res1,res2)
                break
            else:
                ans = 1
    print("Case #{}:".format(idx+1),ans)
