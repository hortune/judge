n = int(input())
nums = list(enumerate(list(map(int, input().split()))))

ans = 0
cur_state = []

for i, num in nums:
    if len(cur_state) == 0:
        cur_state.append((i, num))
    else:
        cur_max = 0
        delta = 0
        max_idx = i
        for j in range(i - 1, -1, -1):
            if cur_state[j][0] >= j:
                delta += cur_state[j][1]
            else:
                delta -= cur_state[j][1]
            delta += num
            if delta > cur_max:
                max_idx = j
                cur_max = delta
        ans += cur_max
        print('res', delta, j)
        cur_state.insert(max_idx, (i, num))
print(cur_state)
print(ans)
