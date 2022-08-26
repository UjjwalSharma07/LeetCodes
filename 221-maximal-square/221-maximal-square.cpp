class Solution {
public:
    // recursion
    
    int solve(vector<vector<char>>& matrix, int i, int j,int& maxi) {
        //base case
        if(i>=matrix.size() || j >= matrix[0].size())
            return 0;
        
        int bottom = solve(matrix, i+1, j,maxi);
        int diagnol = solve(matrix, i+1, j+1,maxi);
        int right = solve(matrix, i, j+1,maxi);
        
        if(matrix[i][j] == '1') {
            int side = min(bottom, min(right, diagnol)) + 1;
            maxi = max(maxi, side);
            return side;
        }
        else
        {
            return 0;
        }
    }
    // memo
    int solveMem(vector<vector<char>>& matrix,int i,int j,vector<vector<int>>& dp,int &maxi){
        if(i>=matrix.size() || j>= matrix[0].size())
            return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int bottom = solveMem(matrix,i+1,j,dp,maxi);
        int diagonal = solveMem(matrix,i+1,j+1,dp,maxi);
        int right = solveMem(matrix,i,j+1,dp,maxi);
        
        if(matrix[i][j]=='1'){
            int side = min(bottom,min(diagonal,right))+1;
            maxi = max(maxi,side);
            return dp[i][j]=side;
        }
        else{
            return dp[i][j]= 0;
        }
    }
    int solveTab(vector<vector<char>>& matrix,int n,int m,int i,int j,int &maxi){
         
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=n-1;i >=0; i--){
            for(int j=m-1; j>=0; j--){
                int bottom = dp[i+1][j];
                int diagonal =dp[i+1][j+1];
                int right = dp[i][j+1];
        
                if(matrix[i][j]=='1'){
                    int side = 1+ min(bottom,min(diagonal,right));
                    maxi = max(maxi,side);
                    dp[i][j]=side;
                }
                else{
                   dp[i][j] = 0;
                }
            }
        }
        return dp[i][j];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        int n =matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       
        // solve(matrix,0,0);
        // solveMem(matrix,0,0,dp,maxi);
        solveTab(matrix,n,m,0,0,maxi);
        return maxi*maxi;
    }
};