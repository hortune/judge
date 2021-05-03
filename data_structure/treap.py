from random import randint
class Node:
    def __init__(self, key):
        self.key = key
        self.pri = randint(1, 100000000000)
        self.r = self.l = None

def merge(a, b):
    if a is None:
        return b

    if b is None:
        return a

    if a.pri > b.pri:
        a.r = merge(a.r, b)
        return a

    b.l = merge(a, b.l)
    return b

def split(s, k):
    if s is None:
        a = b = None
    elif s.key <= k:
        a = s
        a.r, b = split(s.r, k)
    else:
        b = s
        a, b.l = split(s.l, k)
    return a, b

def search_l(s, value):
    if s is None:
        return None

    if s.key <= value:
        return search_l(s.r, value)
    else:
        res = search_l(s.l, value)
        return res if res is not None else s.key

def search_se(s, value):
    if s is None:
        return None

    if s.key <= value:
        res = search_se(s.r, value)
        return res if res is not None else s.key
    else:
        res = search_se(s.l, value)
        return res

def insert(s, value):
    a, b = split(s, value)
    a = merge(a, Node(value))
    return merge(a, b)

def delete(s, value):
    # self new comer I guess

if __name__ == '__main__':
    root = None
    a = Node(15)
    root = merge(root, a)
    b = Node(20)
    root = merge(root, b)
    print(a, b)
    print(root)
    a, b = split(root, 17)
    print (a, b)
