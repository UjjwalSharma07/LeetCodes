class Solution {
public:
    int beautySum(string s) {
        unordered_map<char,int>mp;
        
        int ans=0;
        
        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                mp[s[j]]++;
                int maxi = INT_MIN;
                int mini = INT_MAX;
                
                for(auto it:mp){
                    if(it.second>maxi)
                        maxi = it.second;
                    if(it.second<mini)
                        mini = it.second;
                }
                ans+=maxi-mini;
            }
            mp.clear();
        }
        return ans;
    }
};