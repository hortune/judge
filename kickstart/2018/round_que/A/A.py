T = int(input())
for _T in range(T):
    Q = int(input())
    bus_stop = [[0] * 2 for i in range(5002)]
    bus_ans = [0] * 5002


    buses = list(map(int,input().split()))
    
    for i in buses[::2]:
        bus_stop[i][0] += 1
    
    for j in buses[1::2]:
        bus_stop[j+1][1] += 1
    

    for i in range(5001):
        bus_ans[i] += bus_stop[i][0] - bus_stop[i][1]
        bus_ans[i + 1] = bus_ans[i]

    ans = []

    N = int(input())
    ans = [str(bus_ans[int(input())]) for i in range(N) ]
    print("Case #%d:" % (_T+1)," ".join(ans))

    if _T != T-1:
        input()
