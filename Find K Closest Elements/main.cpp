class Solution {
    public:
        vector<int> findClosestElements(vector<int>& arr, int k, int x) {
            int n = arr.size();

            int s = 0;
            int e = n - k;

            while(s < e) {
                int mid = s + (e - s) / 2;
                // ans -> [mid.....mid+k-1]
                if(x - arr[mid] > arr[mid + k] - x) {
                    s = mid + 1;
                } else e = mid;
            }

            vector<int> ans(arr.begin() + s, arr.begin() + s + k);
            return ans;
        }
};