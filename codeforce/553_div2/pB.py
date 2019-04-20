n, m = list(map(int,input().split()))
res = 0
pair = None
row = -1
column = -1
for i in range(n):
    tmp = list(map(int, input().split()))
    
    if pair is None:
        has_pair = False
        for j in range(len(tmp)-1):
            if tmp[j] != tmp[j+1]:
                has_pair = True
                pair = (tmp[j], tmp[j+1])
                row = i
                column = j
                break
        if not has_pair:
            res ^= tmp[0]
    else:
        res ^= tmp[0]

if pair is None and res == 0:
    print("NIE")
else:
    selection = [1]*n
    if pair is not None:
        if pair[0] != res:
            selection[row] = column+1
        else:
            selection[row] = column+2
    print("TAK")
    print(" ".join(list(map(str,selection))))
