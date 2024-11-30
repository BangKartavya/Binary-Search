class Solution {
    public:
        int findKthPositive(vector<int>& arr, int k) {
            int s = 0;
            int e = arr.size() - 1;

            while(s <= e) {
                int mid = s + (e - s) / 2;

                int mis = arr[mid] - (mid + 1);

                if(mis < k) {
                    s = mid + 1;
                } else e = mid - 1;
            }

            return k + e + 1;
        }
};