T = int(input())

class Node:
    def __init__(self):
        self.count = 0
        self.next = [None]*26


class TRIE:
    def __init__(self):
        self.root = Node()
    
    def add(self, string):
        cur = self.root
        for ele in string:
            if cur.next[ord(ele) - 65] is None:
                cur.next[ord(ele) - 65] = Node()
            cur = cur.next[ord(ele) - 65]
            cur.count += 1

def cmp_longest(str1, str2):
    i = 0
    length = min(len(str1), len(str2))
    while i < length:
        if str1[i] != str2[i]:
            break
        i += 1
    return i


def customhash(string):
    ans = 0
    for ele in string:
        ans *= 26
        ans += ord(ele) - ord('A')
    return ans

def dfs(node):
    if node.count < 2:
        return 0
    
    ans = 0
    for n_node in node.next:
        if n_node is not None:
            ans += dfs(n_node)
    node.count -= ans

    if node.count >= 2:
        node.count -= 2
        ans += 2
    return ans


for i in range(T):
    N = int(input())
    record = {}
    data = [input().strip()[::-1] for i in range(N)]
    data.sort()
    trie = TRIE()

    for dd in data:
        trie.add(dd)

    ans = sum([dfs(ele) for ele in trie.root.next if ele is not None])
    print("Case #{}:".format(i+1),ans)
