class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>= grid.size() || j>= grid[0].size() || grid[i][j] == 0)
            return 0;
        
        int temp = grid[i][j];
        grid[i][j] = 0;
        int maxi = INT_MAX;
        
        maxi = temp+ max({dfs(i+1,j,grid),dfs(i-1,j,grid),dfs(i,j+1,grid),dfs(i,j-1,grid)});
        grid[i][j] = temp;
        
        return maxi;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans = max(ans,dfs(i,j,grid));
            }
        }
        return ans;
    }
};