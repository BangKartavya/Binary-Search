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

    def lengthOfLIS(self, nums: List[int]) -> int:
        temp: List[int] = []
        temp.append(nums[0])
        n: int = len(nums)

        for i in range(1,n):
            if(nums[i] > temp[-1]): temp.append(nums[i])
            else:
                ind: int = self.lower_bound(temp,nums[i])
                temp[ind] = nums[i]
        
        return len(temp)