import sys
input = sys.stdin.readline
INT_MAX = 10**18

class SegTree:
    def __init__(self, idx, l, r):
        self.idx = idx
        self.l = l
        self.r = r
        self.mid = (l+r) // 2
        self.record = [0] * 10
        self.value = 0
        if self.l != self.r:
            mid = (l + r) // 2
            self.left = SegTree(idx*2, l, mid)
            self.right = SegTree(idx*2 + 1, mid + 1, r)

    def query(self, l, r):
        if self.l == l and self.r == r:
            return self.value, self.record

        if r <= self.mid:
            return self.left.query(l, r)
        elif self.mid < l: 
            return self.right.query(l, r)
        else:
            lv, lr = self.left.query(l, self.mid)
            rv, rr = self.right.query(self.mid+1, r)
            tmp_ans = INT_MAX
            if lv:
                tmp_ans = min(lv, tmp_ans)

            if rv:
                tmp_ans = min(rv, tmp_ans)
            nr = []
            for i, j in zip(lr, rr):
                if i and j:
                    tmp_ans = min(i+j, tmp_ans)
                    nr.append(min(i, j))
                elif i:
                    nr.append(i)
                elif j:
                    nr.append(j)
                else:
                    nr.append(0)
            return 0 if tmp_ans == INT_MAX else tmp_ans, nr

    def edit(self, idx, value):
        if self.l == idx and self.r == idx:
            t_value = value
            for i in range(10):
                self.record[i] = value if t_value % 10 else 0
                t_value //= 10
            self.value = 0
            return

        if idx <= self.mid:
            self.left.edit(idx, value)
        else:
            self.right.edit(idx, value)
        lv, lr = self.left.query(self.l, self.mid)
        rv, rr = self.right.query(self.mid+1, self.r)
        tmp_ans = INT_MAX
        if lv:
            tmp_ans = min(lv, tmp_ans)

        if rv:
            tmp_ans = min(rv, tmp_ans)

        for idx, (i, j) in enumerate(zip(lr, rr)):
            if i and j:
                tmp_ans = min(i+j, tmp_ans)
            self.record[idx] = INT_MAX
            if i:
                self.record[idx] = min(self.record[idx], i)
            if j:
                self.record[idx] = min(self.record[idx], j)
            if self.record[idx] == INT_MAX:
                self.record[idx] = 0
        self.value = 0 if tmp_ans == INT_MAX else tmp_ans

if __name__ == '__main__':
    n, q = map(int, input().split())
    nums = list(map(int, input().split()))
    seg_tree = SegTree(1, 1, n)
    for idx, num in enumerate(nums):
        seg_tree.edit(idx+1, num)
    
    for _ in range(q):
        t, l, r = map(int, input().split())
        if t == 1:
            seg_tree.edit(l, r)
        else:
            ans, _ = seg_tree.query(l, r)
            print(ans if ans else -1)
