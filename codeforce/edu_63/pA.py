n = int(input())
string = input()

cur_max = 0
max_idx = -1
for i in range(n):
    if ord(string[i]) < cur_max:
        print("YES")
        print(max_idx+1, i+1)
        exit()
    if ord(string[i]) > cur_max:
        cur_max, max_idx = ord(string[i]), i
print("NO")
