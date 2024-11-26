class Solution {
    public:
        vector<int> nums;
        int target;
        int n;
        int l_bound() {
            int s = 0;
            int e = n - 1;
            int ans = -1;
            while(s <= e) {
                int mid = s + (e - s) / 2;
                if(nums[mid] == target) {
                    ans = mid;
                    e = mid - 1;
                } else if(nums[mid] < target) {
                    s = mid + 1;
                } else e = mid - 1;
            }

            return ans;
        }
        int u_bound() {
            int s = 0;
            int e = n - 1;
            int ans = -1;
            while(s <= e) {
                int mid = s + (e - s) / 2;
                if(nums[mid] == target) {
                    ans = mid;
                    s = mid + 1;
                } else if(nums[mid] < target) {
                    s = mid + 1;
                } else e = mid - 1;
            }

            return ans;
        }
        vector<int> searchRange(vector<int>& nums, int target) {
            this->nums = nums;
            n = nums.size();
            this->target = target;

            return {l_bound(), u_bound()};
        }
};