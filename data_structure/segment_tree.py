# Segment tree for range maximum
class Node:
    def __init__(self, num=0, left=None, right=None):
        self.num = num
        self.left = left
        self.right = right


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

    '''
    Single point update
    '''
    def update(self, update_index, num, node_index=1):
        node = self.seg_tree[node_index]
        if node.left == node.right == update_index:
            node.num = num
            return

        mid = (node.left + node.right) >> 1

        if node.left <= update_index <= mid:
            self.update(update_index, num, node_index*2)
        else:
            self.update(update_index, num, node_index*2 + 1)

        self.seg_tree[node_index].num = max(self.seg_tree[node_index*2].num,
                                            self.seg_tree[node_index*2+1].num)

    def query(self, left, right, node_index=1):
        node = self.seg_tree[node_index]

        if left == node.left and right == node.right:
            return node.num

        mid = (node.left + node.right) >> 1
        # Split the query
        if mid >= right:
            return self.query(left, right, node_index*2)
        elif left > mid:
            return self.query(left, right, node_index*2 + 1)
        else:
            return max(self.query(left, mid, node_index*2),
                       self.query(mid+1, right, node_index*2 + 1))


if __name__ == "__main__":
    seg_tree = SegmentTree(10)
    seg_tree.update(1, 2)
    seg_tree.update(2, 3)
    seg_tree.update(10, 1000)
    seg_tree.update(4, 500)
    print(seg_tree.query(1, 10))
