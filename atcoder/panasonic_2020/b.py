H, W = map(int, input().split())


if H == 1 or W == 1:
    print(1)
else:
    more = (W + 1) // 2
    less = W // 2

    print((H//2)*less + ((H+1)//2) * more)
