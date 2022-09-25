class Solution {
public:
    bool solve(string s1,string s2,unordered_map<string,bool>& dp){
        
        if(s1.compare(s2) == 0)
            return true;
        
        if(s1.length()<= 1 )
            return false;
        
        string key = s1;
        key.push_back(' ');
        key.append(s2);
        
        if(dp.find(key) != dp.end())
            return dp[key];
        
        bool flag = false;
        int n = s1.length();
        
        for(int i=1; i<=n-1; i++){
           if((solve(s1.substr(0, i), s2.substr(n-i, i),dp)&&solve(s1.substr(i, n-i), s2.substr(0, n-i),dp))||((solve(s1.substr(0, i), s2.substr(0, i),dp)&&solve(s1.substr(i, n-i), s2.substr(i, n-i),dp))))
        {
            flag = true;
            break;
        }        
        }
        return dp[key] = flag;
    }
    bool isScramble(string s1, string s2) {
        if(s1.length() != s2.length())
            return false;
        
        if(s1 == "" && s2 == ""){
            return true;
        }
        unordered_map<string,bool>dp;
        dp.clear();
        return solve(s1,s2,dp);
    }
};