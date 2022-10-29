class Solution {
public:
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        return a.second>b.second;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>>days;
        
        for(int i=0; i<plantTime.size(); i++){
            days.push_back({plantTime[i],growTime[i]});
        }
        sort(begin(days),end(days),cmp);
        int ans = 0;
        int start=0;
        
        for(int i=0; i<plantTime.size(); i++){
            start+=days[i].first;
            ans = max(ans, start+days[i].second);
        }
        return ans;
    }
};