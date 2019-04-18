class BIT:
    def __init__(self, array):
        self.bit = [0]*(len(array)+1)
        self._preprocess(array)

    def _preprocess(self, array):
        for index, value in enumerate(array):
            self.add(index+1, value)

    def add(self, index, value):
        
        while index < len(self.bit):
            self.bit[index] += value
            index += (index & (-index))

    def sum(self, index):
        
        ans = 0
        
        while index > 0:
            ans += self.bit[index]
            index -= index & (-index)

        return ans


if __name__ == "__main__":
    bit = BIT([1,2,3,4,5])
    assert(bit.sum(3) == sum([1,2,3]))

    bit.add(3,50)
    assert(bit.sum(5) == sum([1,2,3,4,5]) + 50)
