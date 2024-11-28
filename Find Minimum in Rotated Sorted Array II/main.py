class Solution:
    def findMin(self, nums: List[int]) -> int:
        n = len(nums)
        
        s = 0
        e = n-1
        
        while(s <= e):
            mid = s + (e-s)//2;
            
            if(nums[mid] < nums[e]): e = mid
            elif(nums[mid] > nums[e]): s = mid+1
            else: e -= 1
                
        return nums[s]