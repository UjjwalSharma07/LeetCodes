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
    int solveTab(string a,string b,int N,int M){
        
        vector<vector<int>>dp(N+1,vector<int>(M+1,0));
        
        for(int n=1; n<N+1; n++){
            for(int m=1; m<M+1; m++){
                if(a[n-1]==b[m-1]){
                   dp[n][m] = 1+dp[n-1][m-1];
                }
                else{
                   dp[n][m] = max(dp[n-1][m],dp[n][m-1]);
                }
            }
        }
        return dp[N][M];
    }
    int minInsertions(string s) {
        string a = s;
        reverse(s.begin(),s.end());
        string b = s;
        int n=a.size();
        int m=b.size();
        
        
        //memo
        
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int ans = solveTab(a,b,n,m);
        return n-ans;
    }
};