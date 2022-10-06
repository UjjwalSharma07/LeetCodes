class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        int len = mp[key].size();
        int low=0;
        int high = len-1;
        string ans="";
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mp[key][mid].first == timestamp){
                return mp[key][mid].second;
            }
            else if(mp[key][mid].first<timestamp){
                ans = mp[key][mid].second;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */