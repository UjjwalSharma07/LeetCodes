class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>mp,m1;
        for(auto i:nums){
            mp[i]++;
        }
        for(auto i:nums){
            if(mp[i]==0){
                continue;
            }
            mp[i]--;
            if(m1[i-1]>0){
                m1[i-1]--;
                m1[i]++;
            }
            else if(mp[i+1]!=0 && mp[i+2]!=0){
                mp[i+1]--;
                mp[i+2]--;
                m1[i+2]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};