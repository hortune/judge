import sys
T = int(input())
for idx in range(T):
    n = int(input())
    
    ans = []
    for i in range(8):
        gg = [ num for num in range(1,n+1) if num & (1 << i)]
        ng = [ num for num in range(1,n+1) if not (num & (1 << i))]
        if not len(gg) or not len(ng):
            break
        print(len(gg),len(ng),*gg,*ng)
        sys.stdout.flush()
        ans.append(int(input()))
    print(-1,max(ans))
    sys.stdout.flush()
