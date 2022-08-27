class Solution {
public:
    // recursion
    int solve(string a,string b,int i,int j){
        if(i==a.length())
            return b.length()-j;
        if(j==b.length())
            return a.length()-i;
        
        int ans =0;
        if(a[i]==b[j]){
            ans = solve(a,b,i+1,j+1);
        }
        else{
            int insert = solve(a,b,i,j+1);
            int del = solve(a,b,i+1,j);
            int replace = solve(a,b,i+1,j+1);
            
            ans = min(insert,min(del,replace))+1;
        }
        return ans;
    }
    // memo
    int solveMem(string a,string b,int i,int j,vector<vector<int>>& dp){
         
        if(i==a.length())
            return b.length()-j;
         
        if(j==b.length())
            return a.length()-i;
         
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int ans =0;
        if(a[i]==b[j]){
            ans = solveMem(a,b,i+1,j+1,dp);
        }
        else{
            int insert = solveMem(a,b,i,j+1,dp);
            int del = solveMem(a,b,i+1,j,dp);
            int replace = solveMem(a,b,i+1,j+1,dp);
            
            ans = min(insert,min(del,replace))+1;
        }
        return dp[i][j] = ans;
    }
    
    // tabulation
    
    int solveTab(string a,string b){
        vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));
        
        for(int j=0; j<b.length(); j++){
            dp[a.length()][j] = b.length()-j;
        }
        for(int i=0; i<a.length(); i++){
            dp[i][b.length()] = a.length()-i;
        }
        
        for(int i=a.length()-1; i>=0; i--){
            for(int j= b.length()-1; j>=0; j--){
                int ans =0;
                
                if(a[i]==b[j]){
                    ans = dp[i+1][j+1];
                }
                else{
                    int insert = dp[i][j+1];
                    int del = dp[i+1][j];
                    int replace = dp[i+1][j+1];
            
                    ans = min(insert,min(del,replace))+1;
                }
                    dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
        
        return solveTab(word1,word2);
        // return solveMem(word1,word2,0,0,dp);
        
        // return solve(word1,word2,0,0);
    }
};