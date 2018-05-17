
def bs(nums,k):
    r = len(nums)
    l = 0
    m = (r + l)//2

    while r - l >= 1:
        print(r,m,l)
        if k > nums[m]:
            r, m, l = r,(r+m)//2 ,m+1
        elif k < nums[m]:
            r, m, l = m,(l+m)//2 ,l
        else:
            return m+1
    return 0


n, k = list(map(int,input().split()))
q = list(map(int,input().split()))
query = list(map(int,input().split()))


ans = []
for i in query:
    ans.append(str(bs(q,i)))

print("\n".join(ans))
