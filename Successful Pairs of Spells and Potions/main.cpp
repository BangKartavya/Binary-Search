class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = potions.size();
        sort(begin(potions),end(potions));

        for(auto i: spells) {
            int s = 0;
            int e = n-1;

            while(s<=e) {
                int mid = s + (e-s)/2;

                if((long long int)potions[mid]*(long long int)i >= success) {
                    e = mid-1;
                }
                else s = mid+1;
            }

            ans.push_back(n-e-1);
        }

        return ans;
    }
};