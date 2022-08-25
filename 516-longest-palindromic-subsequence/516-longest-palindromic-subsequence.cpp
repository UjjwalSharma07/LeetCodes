class Solution {
public:
    int LCA(string a,string b,int n, int m){
        if(n==0 || m==0)
            return 0;
        if(a[n-1]==b[m-1]){
            return 1+LCA(a,b,n-1,m-1);
        }
        else{
            return max(LCA(a,b,n-1,m),LCA(a,b,n,m-1));
        }
    }
    // Memo
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
    
    int longestPalindromeSubseq(string s) {
        
// longest palindrome subsequence == lonegst common subsequense( input string , reverse of input string)
        
        string a = s;
        reverse(s.begin(),s.end());
        string b=s;
        int n = a.size();
        int m = b.size();
        
        // return LCA(a,b,n,m);
        
        //memo
        
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return solveTab(text1,text2,n,m,dp);
        
        // tabulation
        return solveTab(a,b,n,m);
    }
};