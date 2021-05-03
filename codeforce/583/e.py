n = int(input())
dists = list(map(int, input().split()))
dists = list(enumerate(dists))
# Sort from large to small
dists.sort(key=lambda x: -x[1])

dist = [[2*idx + 1] for idx, _ in dists]

for cur_idx, (idx, w) in enumerate(dists):
    if cur_idx + w == len(dist):
        dist.append([2*idx + 2])
    else:
        dist[cur_idx + w - 1].append(2*idx + 2)

for idx in range(len(dist)):
    if idx != 0:
        print(dist[idx][0], dist[idx-1][0])
    for i_idx in range(1, len(dist[idx])):
        print(dist[idx][i_idx], dist[idx][0])
