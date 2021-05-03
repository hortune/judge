T = int(input())
for idx in range(T):
    string = input().strip()
    ans = []
    cur_left = 0
    for char in string:
        num = int(char)
        if num > cur_left:
            ans.append('(' * (num - cur_left))
            cur_left = num
        elif num < cur_left:
            ans.append(')' * (cur_left - num))
            cur_left = num
        ans.append(char)
    ans.append(')' * cur_left)
    print('Case #{}:'.format(idx+1), ''.join(ans))
