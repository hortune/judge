n, m = map(int, input().split())
state = [0]*(n+2)
counter = 0
for i in range(m):
    x, y = map(int, input().split())
    origin = ((state[y] | state[y-1]) == 3) + ((state[y] | state[y+1]) == 3)
    # change state
    state[y] ^= (1<<(x-1))
    new = ((state[y] | state[y-1]) == 3) + ((state[y] | state[y+1]) == 3)
    counter += new - origin
    print('Yes' if counter == 0 else 'No')
