import json
k = int(input())
# 1
# 2
# 3
# 10

# assume_valid
# list of num ??
def next_lunlun(k):
    k[0] += 1
    for i in range(len(k) - 1):
        if k[i] < 10:
            break
        k[i] -= 10
        k[i+1] += 1

    if k[-1] >= 10:
        k[-1] -= 10
        k.append(1)

    for i in range(len(k)-1, 0, -1):
        if abs(k[i] - k[i-1]) <= 1:
            continue
        elif k[i] > k[i-1]:
            k[i-1] = k[i] - 1
            for j in range(i-2, -1, -1):
                k[j] = max(k[j + 1] - 1, 0)
            break
        else:
            pivot = len(k) - 1
            for j in range(i, len(k) - 1):
                if k[j + 1] > k[j] or (k[j] < 9 and k[j+1] == k[j]):
                    pivot = j
                    break
            if pivot == len(k) - 1 and k[-1] == 9:
                for j in range(len(k)):
                    k[j] = 0
                k.append(1)
            else:
                k[pivot] += 1
                for j in range(pivot-1, -1, -1):
                    k[j] = max(k[j+1] -1 , 0)
            break

    return k

i = [0]
for idx in range(k):
    next_lunlun(i)
base = 0
for num in reversed(i):
    base *= 10
    base += num
print(base)
