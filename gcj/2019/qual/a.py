T = int(input())

for i in range(T):
    string = list(map(int, input().strip()))
    print("Case #{}: ".format(i+1), end="")
    first = True
    for ele in string:
        if ele != 4:
            print(ele, end='')
        else:
            print(2, end='')
    print(" ",end='')
    for ele in string:
        if ele == 4:
            print(2, end='')
            first = False
        elif not first:
            print(0, end='')
    print("")
    
