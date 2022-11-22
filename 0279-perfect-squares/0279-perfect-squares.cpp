class Solution {
public:
    int solve(int n){
        if(n==0)
            return 0;
        
        int ans= INT_MAX;
        for(int i=1; i*i<=n; i++){
            ans = min(ans,1+solve(n-i*i));
        }
        return ans;
    }
    
    // memo
     int solveMem(int n,vector<int>& dp){
        if(n==0)
            return 0;
         
        if(dp[n]!=-1)
            return dp[n];
         
        int ans= INT_MAX;
        for(int i=1; i*i<=n; i++){
            ans = min(ans,1+solveMem(n-i*i,dp));
        }
        return dp[n]= ans;
    }
    // Tabulation
    int solveTab(int N){
         vector<int>dp(N+1,0);
        
         for(int n=1; n<=N; n++){
             int ans= INT_MAX;
             for(int i=1; i*i<=n; i++){
                ans = min(ans,1+dp[n-i*i]);
             }
             dp[n]= ans;
         }
        return dp[N];
    }
    int numSquares(int n) {
        
       // vector<int>dp(n+1,-1);
       // return solveMem(n,dp);
        
        return solveTab(n);
    }
};