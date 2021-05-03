def bf(candidate, record, all_record, depth):
    if depth == 3:
        all_record.append(''.join(record + [record[0]]))
    else:
        for i in range(len(candidate)):
            if candidate[i]:
                record.append(chr(ord('a') + i))
                candidate[i] = False
                bf(candidate, record, all_record, depth+1)
                candidate[i] = True
                record.pop()
all_record = []
bf([True, True, True], [], all_record, 0)
n = int(input())
first = input().strip()
second = input().strip()
print('YES')
"""
if first[0] == first[1] and second[0] == second[1]:
    print('abc'*n)
elif first[0] != first[1] and second[0] != second[1]:
    union = set(first + second)
    if len(union) == 2:
        for i in 'abc':
            if i not in union:
                break
        print(first[0] * n + i * n + first[1] * n)
    else:
"""
has_ans = False
for cand in all_record:
    if first not in cand and second not in cand:
        print(cand[:3]*n)
        has_ans = True
        break

if not has_ans:
    if first[0] == second[0]:
        print(first[1]*n + second[1]*n + first[0]*n)
    elif first[1] == second[1]:
        print(first[1]*n + second[0]*n + first[0]*n)
    else:
        for c in 'abc':
            if c not in first:
                break
        print(first[0]*n + c*n + first[1]*n)
