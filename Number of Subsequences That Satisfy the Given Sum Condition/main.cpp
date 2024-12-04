class Solution {
private:
    const int MOD = 1e9 + 7;

    int binExpo(int a, int b) {
        int res = 1;

        while(b > 0) {
            if(b%2 == 1) {
                res = ((long long int)(res%MOD)*(long long int)(a%MOD))%MOD;
                b--;
            }
            else {
                a = ((long long int)(a%MOD)*(long long int)(a%MOD))%MOD;
                b/=2;
            }
        }

        return res;
    }

public:
    int numSubseq(vector<int>& nums, int target) {
        sort(begin(nums),end(nums));
        int n = nums.size();
        
        int ans = 0;

        for(int i = 0;i<n;i++) {
            int cnt = 0;

            if(2 * nums[i] > target) break;

            int s = i+1;
            int e = n-1;

            while(s <= e) {
                int mid = s + (e-s)/2;

                if(nums[i] + nums[mid] <= target) {
                    cnt = mid;
                    s = mid+1;
                }
                else {
                    e = mid-1;
                }
            }
            ans = (ans + binExpo(2,cnt-i)%MOD)%MOD;
        }
        return ans;
    }
};