class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            vector<int> temp;
            int n = nums.size();
            temp.push_back(nums[0]);

            for(int i = 1; i < n; i++) {
                auto lb = lower_bound(begin(temp), end(temp), nums[i]);
                if(lb != temp.end()) {
                    temp[lb - temp.begin()] = nums[i];
                } else temp.push_back(nums[i]);
            }

            return temp.size();
        }
};