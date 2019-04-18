import math

class RMQ:
    def __init__(self, array):
        self.log_num = round(math.log(len(array))/math.log(2)) + 1
        self.rmqs = [[0]*self.log_num for i in range(len(array))]
        self.array = array
        self._preprocess()

    def _preprocess(self):
        for i in range(len(self.array)):
            self.rmqs[i][0] = self.array[i]

        for i in range(1, self.log_num):
            for j in range(len(self.array)):
                length =  (1<<i)
                
                if length + j - 1  < len(self.array):
                    self.rmqs[j][i] = max(
                        self.rmqs[j + length // 2][i - 1],
                        self.rmqs[j][i-1]
                        )
    
    def query(self, i, j): 
        length = round(math.log(j - i ) / math.log(2))
        return max(self.rmqs[i][length], self.rmqs[j - (1 << length)][length])


if __name__ == '__name__':
    rmq = RMQ([1,5,3,2,5,6,7,2])
    print(rmq.query(1,3))
