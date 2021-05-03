a, b, c = map(int, input().split())

right = (c - a - b) ** 2
left = 4 * a * b

if c < a + b:
    print('No')
    exit()

if right > left:
    print("Yes")
else:
    print("No")
