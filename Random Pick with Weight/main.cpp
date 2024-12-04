class Solution {
    private:
        vector<int> bucket;
        int n;

    public:
        Solution(vector<int>& w) {
            bucket.push_back(w[0]);
            n = w.size();
            for(int i = 1; i < n; i++) {
                bucket.push_back(bucket[i - 1] + w[i]);
            }
        }

        int pickIndex() {
            int random_number = rand() % bucket[n - 1];
            return upper_bound(begin(bucket), end(bucket), random_number) - bucket.begin();
        }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */