class Solution {
public:
    static bool cmp(pair<int,int>a,pair<int,int>b){
        if(a.second==b.second){
            return a>b;
        }
        else
            return a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        vector<pair<int,int>>v;
        
        for(auto i:mp){
            v.push_back(i);
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans;
        for(auto i:v){
            while(i.second>0){
                ans.push_back(i.first);
                i.second--;
            }
        }
        return ans;
    }
};