from sys import stdout
n = int(input())

# scan row
# query row

def query(x1,y1,x2,y2):
    print("? {} {} {} {}".format(x1,y1,x2,y2))
    stdout.flush()
    while True:
        res = input().strip()
        if res:
            return int(res)
row = []
for i in range(n):
    res = query(i+1,1,i+1,n)
    if res % 2 == 1:
        row.append(i+1)

# query column
column = []
for i in range(n):
    res = query(1,i+1,n,i+1)
    if res % 2 == 1:
        column.append(i+1)

if len(row) == 2 and len(column) == 2:
    ans = []
    for r in row:
        for col in column:
            res = query(r,col,r,col)
            if res == 1:
                ans.append((r,col))
    print("! {} {} {} {}".format(*ans[0],*ans[1]))
    stdout.flush()
elif len(row) == 2:
    l, r = 1, n+1
    while r - l > 1:
        mid = (r + l) // 2
        res = query(1,l,row[0],mid-1)
        if res % 2 == 1:
            r = mid
        else:
            l = mid
    print("! {} {} {} {}".format(row[0],l,row[1],l))
    stdout.flush()
elif len(column) == 2:
    l, r = 1, n+1
    while r - l > 1:
        mid = (r + l) // 2
        res = query(l,1,mid-1,column[0])
        if res % 2 == 1:
            r = mid
        else:
            l = mid
    print("! {} {} {} {}".format(l,column[0],l,column[1]))
    stdout.flush()
else:
    print("GGGGGGGGGGGGGG")
