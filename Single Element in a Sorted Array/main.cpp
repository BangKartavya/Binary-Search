class Solution {
    private:
        vector<int> nums;
        int n;

    public:
        int singleNonDuplicate(vector<int>& nums) {
            this->nums = nums;
            n = nums.size();

            if(n == 1) return nums[0];

            int s = 0;
            int e = n - 1;

            while(s < e) {
                int mid = s + (e - s) / 2;

                if(mid % 2 == 1) {
                    mid--;
                }

                if(nums[mid] != nums[mid + 1]) {
                    e = mid;
                } else s = mid + 2;
            }

            return nums[e];
        }
};