string = input()

if string[-1] == 'a':
    if string.count('a') == len(string):
        print(string)
    else:
        print(':(')
else:
    start = string.rfind('a') + 1

    counter = 0
    total = string.count(string[-1])
    back = string.count(string[-1],start)
    if total % 2 != 0 or back < total / 2:
        print(":(")
    else:
        index = start
        while total / 2 != back - counter:
            if string[index] == string[-1]:
                counter += 1
            index += 1
        first_start = len(string) - 1
        second_start = index - 1
        ans = True
        while second_start >= 0 and first_start >= index:
            while string[second_start] == 'a' and second_start > 0:
                second_start -= 1
            if string[second_start] != string[first_start]:
                ans = False
                break
            second_start -= 1
            first_start -= 1
        if ans:
            if first_start >= index:
                print(':(')
            elif string[:second_start+1].count('a') != second_start + 1:
                print(':(')
            else:
                print(string[:index])
        else:
            print(':(')
        
