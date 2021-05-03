n = int(input())
strings = [input().strip() for i in range(n)]
counter = {}

for string in strings:
    counter[string] = counter.get(string, 0) + 1

res = sorted(list(counter.items()), key=lambda x: -x[1])

result2 = []

for string, count in res:
    if count == res[0][1]:
        result2.append(string)
    else:
        break
result2.sort()
print('\n'.join(result2))
