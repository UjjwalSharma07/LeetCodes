class Solution {
    
    vector<int>LPS(string s){
        vector<int>pi(s.length(),0);
        pi[0] = 0;
        for(int i=1; i<s.length(); i++){
            int j =pi[i-1];

            while(j>0 && s[i] != s[j])
                j=pi[j-1];
            if(s[i]==s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    
    int solve(string s,vector<int>&dp){
        
        int n = s.size();
        
        if(dp[n] != -1){
            return dp[n];
        }
        vector<int>pre = LPS(s);
        bool flag = false;
        int ans =0;
        
        for(int j=1; j<n; j++){
            int val = (j+1)/2;
            
            if(j%2 == 1 && pre[j] == val){
                flag = true;
                ans = max(ans,1+solve(s.substr(pre[j]),dp));
            }     
        }
        if(flag == false){
            return 1;
        }
        return dp[n] = ans;
    }
    
    public:
        int deleteString(string s) {
            vector<int>dp(4100,-1);
            return solve(s,dp);
        }
};