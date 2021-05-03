T = int(input())

def solve(x, y):
    x = bin(x)

for idx in range(1, T+1):
    x, y = map(int, input().split())
    if x % 2 == 1 and y % 2 == 1:
        print("Case #{}: {}".format(idx, "IMPOSSIBLE"))
    elif x % 2 == 0 and y % 2 == 0:
        print("Case #{}: {}".format(idx, "IMPOSSIBLE"))
    else:
        if x % 2 != 0:
            res1 = solve(abs(-x + 1), abs(y))
            res2 = solve(abs(-x - 1), abs(y))
        else:
            res1 = solve(abs(-x), abs(-y + 1))
            res2 = solve(abs(-x), abs(-y - 1))

        if res1 is None and res2 is None:
            print("Case #{}: {}".format(idx, "IMPOSSIBLE"))
        elif res1 is None:
            print("Case #{}: {}".format(idx, res2))
        elif res2 is None:
            print("Case #{}: {}".format(idx, res1))
        elif len(res1) < len(res2):
            print("Case #{}: {}".format(idx, res1))
        else:
            print("Case #{}: {}".format(idx, res2))
