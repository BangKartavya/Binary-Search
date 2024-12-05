bool cmp(vector<int>& a,vector<int>& b) {
    if(a[0] < b[0]) return true;
    else if(a[0] == b[0]) {
        if(a[1] > b[1]) return true;
    }

    return false;
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(begin(envelopes),end(envelopes),cmp);

        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        for(int i = 0;i<n;i++) {
            if(envelopes[i][1] > temp.back()) {
                temp.push_back(envelopes[i][1]);
            }
            else {
                int ind = lower_bound(begin(temp),end(temp),envelopes[i][1]) - begin(temp);
                temp[ind] = envelopes[i][1];
            }
        }

        return temp.size();
    }
};