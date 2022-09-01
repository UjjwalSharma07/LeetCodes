class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        unordered_map<char,int>mp;
        for(auto i:p){
            mp[i]++;
        }
        int count = mp.size();
       
        int i=0;
        int j=0;
        int k = p.size();
        
        while(j<s.size()){
            
            // calculation part
            if(mp.find(s[j]) != mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
            // window size not achieved
            if(j-i+1<k){
                j++;
            }
            // window size achieved
            else if(j-i+1 == k){
                if(count == 0){
                    
                    ans.push_back(i);
                }
                if(mp.find(s[i])!= mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1){
                        count++;
                    }
                }
                // slide the window
                i++;
                j++;
            }  
        }
        
        return ans;
    }
};