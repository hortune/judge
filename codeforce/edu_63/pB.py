# Two possibility
# 1. erase all eight
# 2. erase the back one, make the eight cannot be at the first


n = int(input())
string = input()

num = string.count('8')

if num <= (n - 11) // 2:
    print("NO")
    exit()


# The eight that was not erased

quota = (n - 11) // 2

i = 0
quota += 1
while quota:
    if string[i] == '8':
        quota -= 1
    i += 1

last_eight = i - 1
quota =(n-11) // 2
if (last_eight - quota) <= quota:
    print("YES")
else:
    print("NO")
