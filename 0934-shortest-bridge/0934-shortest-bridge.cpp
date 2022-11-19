class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j,set<pair<int,int>>& path){
        if(i<0 || i>=grid.size() || j<0 || j>= grid[0].size() || grid[i][j]!= 1 || path.count({i,j}))
            return;
        
        path.insert({i,j});
        grid[i][j] = 2;
        
        dfs(grid,i+1,j,path);
        dfs(grid,i-1,j,path);
        dfs(grid,i,j+1,path);
        dfs(grid,i,j-1,path);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        int island = 0;
        
        set<pair<int,int>>path1,path2;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    if(island == 0){
                        dfs(grid,i,j,path1);
                        island++;
                    }
                    else{
                        dfs(grid,i,j,path2);
                    }
                }
            }
        }
        int ans = INT_MAX;
        for(auto x:path1){
            for(auto y:path2){
                // distace between two points (x1-y1)+ (x2-y2)
                ans = min(ans,(abs(x.first-y.first)+abs(x.second-y.second)-1 ) );
            }
        }
        return ans;
    }
};