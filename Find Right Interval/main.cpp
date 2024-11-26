bool cmp(vector<int>& v1, vector<int>& v2) {
    return v1[0] <= v2[0];
}

class Solution {
    public:
        vector<int> findRightInterval(vector<vector<int>>& intervals) {
            map<vector<int>, int> mp;
            int n = intervals.size();

            for(int i = 0; i < n; i++)
                mp[intervals[i]] = i;

            sort(begin(intervals), end(intervals), cmp);

            vector<int> ans(n, -1);

            for(int i = 0; i < n; i++) {
                int s = i;
                int e = n - 1;

                while(s <= e) {
                    int mid = s + (e - s) / 2;

                    if(intervals[i][1] <= intervals[mid][0]) {
                        ans[mp[intervals[i]]] = mp[intervals[mid]];
                        e = mid - 1;
                    } else s = mid + 1;
                }
            }

            return ans;
        }
};