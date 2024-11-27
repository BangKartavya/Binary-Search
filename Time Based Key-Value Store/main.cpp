class TimeMap {
private:
   unordered_map<string,vector<pair<int,string>>> mp;
public:
    struct comp_pair_int {
        bool operator()(const pair<int,string> &a, const int & b) {
            return (a.first < b);
        }
        bool operator()(const int & a,const pair<int,string> &b) {
            return (a < b.first);
        }
    };
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.count(key) == 0) return "";
        
        int i = upper_bound(mp[key].begin(),mp[key].end(),timestamp,comp_pair_int()) - mp[key].begin()-1;
        if(i >= 0 && i < mp[key].size()) return mp[key][i].second;
        
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */