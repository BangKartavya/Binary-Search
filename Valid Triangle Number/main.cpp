class Solution {
    private:
        vector<int> nums;
        int n;

        int lower(int s, int e, int target) {
            int low = s;
            while(s <= e) {
                int mid = s + (e - s) / 2;
                if(nums[mid] >= target) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            return e - low + 1;
        }

    public:
        int triangleNumber(vector<int>& nums) {
            int cnt = 0;
            n = nums.size();
            sort(begin(nums), end(nums));
            this->nums = nums;

            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    int lows = lower(j + 1, n - 1, nums[i] + nums[j]);
                    cnt += lows;
                }
            }
            return cnt;
        }
};