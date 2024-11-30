class Solution {
    public:
        int arrangeCoins(int n) {
            long long int s = 1;
            long long int e = n;
            int ans = -1;
            while(s <= e) {
                long long int mid = s + (e - s) / 2;

                if(mid * (mid + 1) / 2 <= n) {
                    ans = mid;
                    s = mid + 1;
                } else e = mid - 1;
            }
            return ans;
        }
};