class Solution {
public:
    int solve(string& s,int i,vector<int>& dp){
        if(s[i] == '0')
            return 0;
        if(i >= s.size()-1)
            return 1;
        
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = 0;
        // for single digit
            ans += solve(s,i+1,dp);
        // for double digit
        if(s[i] == '2' && s[i+1]<='6' || s[i] == '1' && s[i+1] <= '9'){
            ans += solve(s,i+2,dp);
        }
        return dp[i] = ans;
    }
    int numDecodings(string s) {
        int n = 101;
        vector<int>dp(n,-1);
        return solve(s,0,dp);
    }
};