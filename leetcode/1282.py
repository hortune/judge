class Solution:
    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        status = {}
        for idx, ele in enumerate(groupSize):
            if ele not in status:
                status[ele] = []
            status[ele].append(idx)
        ans = []
        for size, eles in status.items():
            for i in range(0, len(eles), size):
                ans.append(eles[i:i+size])
        return ans
