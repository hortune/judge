def check_block(comb, H):
    block = 0
    pre = (comb & 1) > 0
    mapping = {0: 0}
    cut_num = 0
    for i in range(1, H):
        cur = ((1 << i) & comb) > 0
        if pre != cur:
            block += 1
            pre = cur
            cut_num += 1
        mapping[i] = block
    return mapping, cut_num

H, W, K = map(int, input().split())
graph = [input() for ele in range(H)]
#
ans = 1319203291031903
for comb in range(1<<(H-1)):
    mapping, cut_num = check_block(comb, H)
    pre = [0] * (cut_num + 1)
    gg = False
    # preprocess 
    for j in range(H):
        pre[mapping[j]] += (graph[j][0] == '1')
    for ele in pre:
        if ele > K:
            gg = True
            break
    if gg: continue

    for i in range(1, W):
        cum = pre[:]
        for j in range(H):
            cum[mapping[j]] += (graph[j][i] == '1')
        for ii in range(len(cum)):
            if cum[ii] - pre[ii] > K or cut_num > ans:
                gg = True
                break
            if cum[ii] > K:
                cut_num += 1
                for idx in range(len(cum)):
                    cum[idx] -= pre[idx]
                break
        pre = cum
        if gg: break

    if not gg:
        ans = min(ans, cut_num)
print(ans)
