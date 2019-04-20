n = int(input())
string = input().strip()
target = [ord('A'),ord('C'),ord('T'),ord('G')]

ans = 9488888
for i in range(n - 3):
    tmp_ans = 0
    for j in range(4):
        delta = abs(ord(string[i+j]) - target[j])
        tmp_ans += min(delta, 26-delta)
    ans = min(tmp_ans, ans)

print(ans)
