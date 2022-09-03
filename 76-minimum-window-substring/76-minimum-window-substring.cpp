class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        int i=0;
        int j=0;
        int mini = INT_MAX;
        unordered_map<char,int>mp;
        for(auto it:t){
            mp[it]++;
        }
        int count =mp.size();
        while(j<s.length()){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
            while(count==0){
                if(mini>j-i+1){
                    mini = min(mini,j-i+1);
                    ans = s.substr(i,j-i+1);
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1)
                        count++;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};