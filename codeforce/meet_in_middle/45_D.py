# sort by the end

n = int(input())
intervals = [list(map(int, input().split())) for i in range(n)]
intervals =  list(enumerate(intervals))

intervals.sort(key=lambda x: (x[1][1], x[1][0]))
ans = [0] * n
vis = set()
for idx, (l, _) in intervals:
    while l in vis:
        l += 1
    vis.add(l)
    ans[idx] = l
print(' '.join(list(map(str, ans))))
