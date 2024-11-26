class Solution {
    public:
        int countNegatives(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();

            int cnt = 0;
            int i = 0;
            for(int j = m - 1; j >= 0; j--) {
                for(int k = i; k < n; k++) {
                    if(grid[k][j] < 0) {
                        cnt += n - k;
                        break;
                    }
                    if(grid[k][j] > 0) {
                        i++;
                    }
                }
            }

            return cnt;
        }
};