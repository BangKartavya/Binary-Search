class Solution {
private:
    vector<int> nums;
    int target;
    int n;
    
    int pivot(int s,int e) {
        if(nums[s] <= nums[e]) return s;
        
        int mid = s + (e-s)/2;
        
        if(nums[mid] >= nums[s]) {
            return pivot(mid+1,e);
        }
        else {
            return pivot(s,mid);
        }
    }
    
    int binarySearch(int s,int e) {
       while(s <= e) {
           int mid = s + (e-s)/2;
           
           if(nums[mid] == target) return mid;
           else if(nums[mid] < target) s = mid+1;
           else e = mid-1;
       }
       return -1;
    }
    
public:    
    int search(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;
        n = nums.size();
        
        int piv = pivot(0,n-1);
        
        int t1 = binarySearch(0,piv-1);
        int t2 = binarySearch(piv,n-1);
        
        if(t1 == -1) return t2;
        return t1;
        
    }
};