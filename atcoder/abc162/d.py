n = int(input())
string = input().strip()
r = string.count('R')
g = string.count('G')
h = string.count('B')

ans = r * g * h

if ans == 0:
    print(ans)
else:
    for i in range(n):
        j = 1
        while i + 2 * j < n:
            if string[i] != string[i + j] and string[i + j] != string[i + 2*j] and string[i] != string[i+2*j]:
                ans -= 1
            j += 1
    print(ans)
