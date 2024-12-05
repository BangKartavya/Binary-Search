class Solution:
    def lower_bound(self,temp: List[int],num: int) -> int:
        s: int = 0
        e: int = len(temp)-1

        while(s <= e):
            mid: int = s + (e-s)//2

            if(temp[mid] == num): return mid
            elif(temp[mid] > num): e = mid-1
            else: s = mid+1
        
        return s

    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        n: int = len(envelopes)
        envelopes.sort(key = lambda x: (x[0],-x[1]))


        temp: List[int] = []
        temp.append(envelopes[0][1])

        for i in range(1,n):
            if(envelopes[i][1] > temp[-1]):
                temp.append(envelopes[i][1])
            else:
                ind: int = self.lower_bound(temp,envelopes[i][1])
                temp[ind] = envelopes[i][1]
        
        return len(temp)
