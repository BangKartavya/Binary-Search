MOD: int = 1_000_000_007
class Solution:
    def binExpo(self, a: int, b: int):
        res: int = 1

        while(b > 0):
            if(b%2 == 1):
                res = ((res%MOD)*(a%MOD))%MOD
                b-=1
            else:
                a = (a%MOD * a%MOD)%MOD
                b/=2
        
        return res

    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        n: int = len(nums)

        ans: int = 0

        for i in range(n):
            if(nums[i]*2 > target): break

            s: int = i+1
            e: int = n-1
            cnt: int = 0

            while(s <= e):
                mid: int = s + (e-s)//2

                if(nums[i] + nums[mid] <= target):
                    cnt = mid
                    s = mid+1
                else:
                    e = mid-1
        
            ans = (ans + self.binExpo(2,cnt-i)%MOD)%MOD
        
        return ans
