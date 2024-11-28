class Solution {
    private:
        vector<int> nums;
        int n;

    public:
        int findMin(vector<int>& nums) {
            this->nums = nums;
            n = nums.size();

            int s = 0;
            int e = n - 1;

            while(s <= e) {
                int mid = s + (e - s) / 2;

                if(nums[mid] < nums[e]) {
                    e = mid;
                } else if(nums[mid] > nums[e]) {
                    s = mid + 1;
                } else e--;
            }

            return nums[s];
        }
};