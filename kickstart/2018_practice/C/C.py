T = int(input())


for case in range(1,T+1):
    N = int(input())
    nameList = []
    for _ in range(N):
        a,b = input(),input()
        if a not in nameList:
            nameList.append(a)
        
        if b not in nameList:
            nameList.append(b)
        
        a, b = nameList.index(a), nameList.index(b)
        
