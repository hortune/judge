n = input()

print(len(n) - max(len(n) - 2 * n.count('a') + 1, 0))
