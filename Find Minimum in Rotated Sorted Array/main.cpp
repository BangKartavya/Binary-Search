class Solution {
private:
    vector<int> nums;
    int n;
    
    int pivot(int s,int e) {
        if(nums[s] <= nums[e]) return s;
        
        int mid = s + (e-s)/2;
        
        if(nums[mid] >= nums[s]) {
            return pivot(mid+1,e);
        }
        
        return pivot(s,mid);
    }
public:
    
    int findMin(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        
        return nums[pivot(0,n-1)];
    }
};