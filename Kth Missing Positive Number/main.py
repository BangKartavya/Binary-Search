class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        s = 0
        e = len(arr) - 1
        
        while(s <= e):
            mid = s + (e-s)//2
            
            mis = arr[mid] - (mid+1)
            
            if(mis < k):
                s = mid+1
            else: e = mid-1
        
        return k + e + 1