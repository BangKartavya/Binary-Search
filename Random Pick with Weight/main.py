class Solution:

    def __init__(self, w: List[int]):
        self.bucket: list[int] = [w[0]]
        self.n = len(w)
        for i in range(1,self.n):
            self.bucket.append(self.bucket[i-1] + w[i])

    def pickIndex(self) -> int:
        random_number: int = random.randint(0,32767)%self.bucket[self.n-1]

        s: int = 0
        e: int = self.n-1

        while(s < e):
            mid: int = s + (e-s)//2

            if(random_number >= self.bucket[mid]):
                s = mid+1
            else:
                e = mid
        
        while(s < self.n and self.bucket[s] <= random_number):
            s+=1
        
        return s




# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()