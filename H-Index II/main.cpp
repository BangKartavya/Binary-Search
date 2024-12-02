class Solution {
    private:
        vector<int> arr;
        int n;

        bool possible(int citation_count) {
            int s = 0;
            int e = n - 1;

            int ans = -1;

            while(s <= e) {
                int mid = s + (e - s) / 2;

                if(arr[mid] < citation_count) {
                    s = mid + 1;
                } else if(arr[mid] >= citation_count) {
                    ans = mid;
                    e = mid - 1;
                }
            }

            if(ans == -1) return false;

            return (n - ans) >= citation_count;
        }

    public:
        int hIndex(vector<int>& citations) {
            n = citations.size();
            this->arr = citations;
            int s = 0;
            int e = n;
            int ans = -1;

            while(s <= e) {
                int mid = s + (e - s) / 2;

                if(possible(mid)) {
                    ans = mid;
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }

            return ans;
        }
};