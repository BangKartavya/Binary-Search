class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        n: int = len(nums)

        s: int = 0
        e: int = n-1

        while(s < e):
            mid: int = s + (e-s)//2

            if(mid%2 == 1):
                mid -= 1
            
            if(nums[mid] != nums[mid+1]):
                e = mid
            else:
                s = mid+2
        
        return nums[e]