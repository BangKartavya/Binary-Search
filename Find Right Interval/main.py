def cmp(i):
    return i[0]

class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        
        mp = {}
        
        for i in range(n):
            mp[tuple(intervals[i])] = i
        
        ans = [-1 for i in range(n)]
        
        intervals = sorted(intervals,key=cmp)
                
        for i in range(n):
            s = i
            e = n-1
            
            
            while(s <= e):
                mid = (s + e)//2
                
                if(intervals[i][1] <= intervals[mid][0]):
                    ans[mp[tuple(intervals[i])]] = mp[tuple(intervals[mid])]
                    e = mid-1
                else:
                    s = mid+1
            
        return ans
            