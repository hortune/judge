T = int(input())

for i in range(T):
    counter = {}
    string = input().strip()
    for char in string:
        counter[char] = counter.get(char, 0) + 1
    chars = list(counter.keys())
    chars.sort()
    if len(chars) == 2 and abs(ord(chars[0]) - ord(chars[1])) == 1:
        print("No answer")
    elif len(chars) == 3 and abs(ord(chars[0]) - ord(chars[1])) == 1 \
                         and abs(ord(chars[1]) - ord(chars[2])) == 1:
        print("No answer")
    elif len(chars) == 3:
        if abs(ord(chars[0]) - ord(chars[1])) == 1:
            print(counter[chars[0]] * chars[0] +
                  counter[chars[2]] * chars[2] +
                  counter[chars[1]] * chars[1])
        else:
            print(counter[chars[2]] * chars[2] +
                  counter[chars[0]] * chars[0] +
                  counter[chars[1]] * chars[1])
    else:
        ans = []
        if len(chars) > 1:
            for idx in range(1, len(chars), 2):
                ans.append(chars[idx]*counter[chars[idx]])
        for idx in range(0, len(chars), 2):
            ans.append(chars[idx]*counter[chars[idx]])
        print("".join(ans))
