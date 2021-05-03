n = int(input())
nums = [list(map(int,input().split())) for i in range(n)]


first = True
record = {}
target = None
for x, y, h in nums:
    if h != 0:
        target = x, y, h

if target is not None:
    x, y, h = target
    for i in range(0,101):
        for j in range(0, 101):
            if abs(x - i) + abs(x - j) + h >= 1:
                record[(i,j)] = abs(x - i) + abs(y - j) + h
    
    for x, y, h in nums:
        for (i, j) in list(record.keys()):
            if max(record[(i, j)] - abs(x-i) - abs(y-j), 0) != h:
                record.pop((i,j))
    key = list(record.keys())[0]

    print(key[0],key[1], record[key])
else:
    for x, y, h in nums:
        record[(x,y)] = True
    ndone = True
    for i in range(101):
        for j in range(101):
            if (i, j) not in record and ndone:
                print(i, j, 1)
                ndone = False
