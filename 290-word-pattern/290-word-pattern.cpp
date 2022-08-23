class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        vector<string>temp;
        stringstream ss(s);
        string word;
        
        while(ss>>word){
            temp.push_back(word);
        }
        
        if(pattern.size()!=temp.size())
            return false;
        
        unordered_map<char,string>mp;
        set<string>st;
        
        for(int i=0; i<pattern.size(); i++){
            if(mp.find(pattern[i])!=mp.end()){
                if(mp[pattern[i]]!=temp[i])
                    return false;
            }
             else{
                 if(st.count(temp[i])>0)
                     return false;
                 mp[pattern[i]] = temp[i];
                 st.insert(temp[i]);
             }   
        }
        return true;
    }
};