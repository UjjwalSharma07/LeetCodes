class Solution {
public:
    // recusrion
    
    int solve(string a,string b,int n,int m){
        if(n==0 || m==0)
            return 0;
        
        if(a[n-1]==b[m-1]){
            return 1+solve(a,b,n-1,m-1);
        }
        else{
            return max(solve(a,b,n-1,m),solve(a,b,n,m-1));
        }
    }
    
    // memo
    
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
    // tabulation
    
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
    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.size();
        int m=text2.size();
        
//         return solve(text1,text2,n,m); 
        
        //memo
        
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return solveTab(text1,text2,n,m,dp);
        
        return solveTab(text1,text2,n,m);
    }
};