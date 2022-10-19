class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        
        for(auto i:nums){
            mp[i]++;
        }
        int pair=0;
        int left=0;
        for(auto i:mp){
            pair+=i.second/2;
        }
        for(auto i:mp){
            left+=i.second%2;
        }
        return {pair,left};
    }
};