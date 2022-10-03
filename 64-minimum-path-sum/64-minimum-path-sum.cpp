class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i == grid.size()-1 && j==grid[0].size()-1 ){
            return grid[i][j];
        }
        if(dp[i][j] != -1){
           return dp[i][j];
        }
        int up = INT_MAX;
        int left  = INT_MAX;
        
        if(i<grid.size()-1){
            up = solve(i+1,j,grid,dp);
        }
        if(j<grid[0].size()-1){
            left = solve(i,j+1,grid,dp);
        }
        return dp[i][j] = min(up,left)+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,grid,dp);  
    }
};