class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        
        n: int = len(nums1)
        m: int = len(nums2)

        if(n > m): return self.findMedianSortedArrays(nums2,nums1)

        s: int = 0
        e: int = n
        l: int = (n+m+1)//2

        while(s <= e):
            mid1: int = s + (e-s)//2
            mid2: int = l - mid1

            l1 = float('-inf')
            l2 = float('-inf')
            r1 = float('inf')
            r2 = float('inf')

            if(mid1 < n): r1 = nums1[mid1]
            if(mid2 < m): r2 = nums2[mid2]

            if(mid1 - 1 >= 0): l1 = nums1[mid1-1]
            if(mid2 - 1 >= 0): l2 = nums2[mid2-1]

            if(l1 > r2): e = mid1-1
            elif(l2 > r1): s = mid1+1
            elif(l1 <= r2 and l2 <= r1):
                if((n+m)%2==0):
                    return (max(l1,l2) + min(r1,r2))/2
                else:
                    return max(l1,l2)
        
        return -1
