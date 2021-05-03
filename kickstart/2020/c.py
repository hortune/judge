T = int(input())
MOD = 10**9
for idx in range(1, T+1):
    program = input().strip()
    stack = []
    status = [0, 0]
    stack.append(status)
    mapping = {'N':(0, -1), 'S':(0, 1), 'E':(1, 0), 'W':(-1, 0)}
    for c in program:
        if c in 'NSEW':
            stack.append(mapping[c])
        elif c in '23456789(':
            stack.append(c)
        else:
            x, y = 0, 0
            while stack[-1] != '(':
                dx, dy = stack[-1]
                x += dx
                y += dy
                stack.pop()
            stack.pop()
            x *= int(stack[-1])
            y *= int(stack[-1])
            stack.pop()
            stack.append((x, y))
    x, y = 0, 0
    while len(stack):
        dx, dy = stack[-1]
        x += dx
        y += dy
        stack.pop()
    x = ((x % (MOD)) + MOD) % MOD
    y = ((y % (MOD)) + MOD) % MOD
    print("Case #{}: {} {}".format(idx, x+1, y+1))
