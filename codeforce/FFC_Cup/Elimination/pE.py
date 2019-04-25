# 線段樹題
# (same), (flip), (positive), (update)

class Node:
    def __init__(self, num=0, left=None, right=None, setnum=0):
        self.state = num
        self.left = left
        self.right = right
        self.setnum = 0

class SegmentTree:
    '''
    SegmentTree:
        maximum segment tree
    '''
    def __init__(self, n):
        self.seg_tree = [Node() for i in range(4*(1 << n.bit_length()) + 1)]
        self.n = n
        self.build(1, 1, n)

    def build(self, index, left, right):
        node = self.seg_tree[index]

        node.left = left
        node.right = right

        if left != right:
            mid = (left + right) >> 1
            self.build(2*index, left, mid)
            self.build(2*index+1, mid+1, right)

    def push_down(self, index):
        node = self.seg_tree[index]
        if node.setnum:
            self.seg_tree[2*index].setnum = node.setnum
            self.seg_tree[2*index+1].setnum = node.setnum
            node.setnum = 0
            
            self.seg_tree[2*index].state = 0 
            self.seg_tree[2*index+1].state = 0
            return
        
        self.seg_tree[2*index].state ^= node.state
        self.seg_tree[2*index+1].state ^= node.state
        node.state = 0

    '''
    Region flip
    '''
    def flip(self, left, right, node_index=1):
        node = self.seg_tree[node_index]
        if node.left == left and node.right == right:
            node.state ^= 1
            return

        mid = (node.left + node.right) >> 1
        
        self.push_down(node_index)
        if left > mid:
            self.flip(left, right, node_index*2+1)
        elif mid >= right:
            self.flip(left, right, node_index*2)
        else:
            self.flip(left, mid, node_index*2)
            self.flip(mid+1, right, node_index*2 + 1)

    '''
    Region set
    '''
    def setnum(self, left, right, num, node_index=1):
        node = self.seg_tree[node_index]
        if node.left == left and node.right == right:
            node.setnum = num
            node.state = 0
            return
        
        self.push_down(node_index)

        mid = (node.left + node.right) >> 1
        
        if left > mid:
            self.setnum(left, right, num, node_index*2+1)
        elif mid >= right:
            self.setnum(left, right, num, node_index*2)
        else:
            self.setnum(left, mid, num, node_index*2)
            self.setnum(mid+1, right, num, node_index*2 + 1)

    def query(self, index, node_index=1):
        node = self.seg_tree[node_index]

        if node.left == index == node.right:
            return node.state, node.setnum

        mid = (node.left + node.right) >> 1
        self.push_down(node_index)

        # Split the query
        if mid >= index:
            return self.query(index, node_index*2)
        else:
            return self.query(index, node_index*2 + 1)

n, m = map(int,input().split())

base = 100006
shift = 1
seg_tree = SegmentTree(base*2 + 1)
nums = list(map(int, input().split()))
for idx in range(m):
    x, y = input().split()
    y = int(y)
    if x == '<':
        if y > 0:
            seg_tree.flip(0 + shift, y-1 + shift)
            seg_tree.setnum(y + shift, base, 1)
        else:
            seg_tree.setnum(abs(y) + 1 + shift, base, 1)  # 1 positive
    else:
        if y < 0:
            seg_tree.flip(0 + shift, abs(y)-1 + shift)
            seg_tree.setnum(abs(y) + shift, base, 2)
        else:
            seg_tree.setnum(y + 1 + shift, base, 2) # 2 negative
ans = []
for num in nums:
    flip, setnum = seg_tree.query(abs(num) + shift)
    print(num, flip, setnum)
    if setnum == 2:
        ans.append(-abs(num)*(1-2*flip))
    elif setnum == 1:
        ans.append(abs(num)*(1-2*flip))
    else:
        ans.append(num*(1-2*flip))
print(" ".join(map(str,ans)))
