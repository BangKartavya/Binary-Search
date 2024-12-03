class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        s: int = 0
        e: int = len(arr)-k

        while(s < e):
            mid: int = s + (e-s)//2

            if(x - arr[mid] > arr[mid+k]-x):
                s = mid+1
            else:
                e = mid
        
        return arr[s:s+k]
        