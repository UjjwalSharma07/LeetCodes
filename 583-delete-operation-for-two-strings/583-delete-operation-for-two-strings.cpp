class Solution {
public:
    int solveMem(string a,string b,int n,int m,vector<vector<int>>& dp){
        
        if(n==0 || m==0)
            return 0;
        
        if(dp[n][m] != -1){
            return dp[n][m];
        }
        
        if(a[n-1]==b[m-1]){
            return dp[n][m] = 1+solveMem(a,b,n-1,m-1,dp);
        }
        else{
            return dp[n][m] = max(solveMem(a,b,n-1,m,dp),solveMem(a,b,n,m-1,dp));
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans= solveMem(word1,word2,n,m,dp); 
        
        int o1 = n-ans;
        int o2 = m-ans;
        
        return o1+o2;
    }
};