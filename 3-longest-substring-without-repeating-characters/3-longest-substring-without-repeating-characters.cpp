class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        
        int i=0;
        int j=0;
        int maxi = INT_MIN;
        while(j<s.length()){
            mp[s[j]]++;
            
            if(j-i+1 == mp.size()){
                maxi = max(maxi,j-i+1);
            }
            else{
                while(j-i+1 > mp.size()){
                    mp[s[i]]--;
                    if(mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return maxi==INT_MIN?0:maxi;
    }
};