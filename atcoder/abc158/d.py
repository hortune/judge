from collections import deque
rev = False
S = deque(list(input().strip()))

Q = int(input())

for _ in range(Q):
    q = input().split()
    if len(q) == 3 and q[1] == '1':
        if not rev:
            S.appendleft(q[2])
        else:
            S.append(q[2])
    elif len(q) == 3 and q[1] == '2':
        if rev:
            S.appendleft(q[2])
        else:
            S.append(q[2])
    else:
        rev = not rev
if not rev:
    print(''.join(list(S)))
else:
    print(''.join(list(S))[::-1])
