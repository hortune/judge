num1 = list(map(int, input()))[::-1]
num2 = list(map(int, input()))[::-1]
for i in range(len(num1) - 1, 1, -1):
    num1[i - 1] += num1[i]
    num1[i - 2] += num1[i]

for i in range(len(num2) - 1, 1, -1):
    num2[i - 1] += num2[i]
    num2[i - 2] += num2[i]

if len(num1) == 1:
    num1.append(0)
if len(num2) == 1:
    num2.append(0)

if num1[0] == num2[0] and num1[1] == num2[1]:
    print('=')
else:
    num1[0] -= num2[0]
    num1[1] -= num2[1]
    if num1[0] <= 0 and num1[1] <= 0:
        print('<')
    elif num1[0] >= 0 and num1[1] >= 0:
        print('>')
    elif num1[0] < 0:
        right = -2 * num1[0] - num1[1]
        if right <= 0 or (right ** 2) < 5 * (num1[1] ** 2):
            print('>')
        else:
            print('<')
    else:
        left = 2 * num1[0] + num1[1]
        if left <= 0 or (left ** 2) < 5 * (num1[1] ** 2):
            print('<')
        else:
            print('>')
