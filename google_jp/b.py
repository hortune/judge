def dfs(node, childs, vis):
    vis[node] = True
    ff_p,  f_dist = node, 0
    for child in childs[node]:
        if not vis[child]:
            f_p, dist = dfs(child, childs, vis)
            if dist >= f_dist:
                ff_p, f_dist = f_p, dist + 1
    return ff_p, f_dist

T = int(input())
for case in range(T):
    input() # for space
    N = int(input())
    nodes = [[] for i in range(51)]
    for i in range(N-1):
        x, y = map(int, input().split())
        # create edge
        nodes[x].append(y)
        nodes[y].append(x)
    vis = [False]*(N+1)
    farthest_point, dist = dfs(1, nodes, vis)
    vis = [False]*(N+1)
    _, ans = dfs(farthest_point, nodes, vis)
    print("Case #{}: {}".format(case, (ans + 1) // 2))
