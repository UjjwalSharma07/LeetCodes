class Solution {
public:
    int dfs(int row,int col,vector<vector<int>>& grid){
        if(row>=grid.size())
            return col;
        // current col ki value 1 ho and col outofrange na ho and next col ki value bhi one ho to ball left to right move kar skti hai
        if(grid[row][col] == 1 && col+1<grid[0].size() && grid[row][col+1] == 1)
            return dfs(row+1,col+1,grid);
        
        // right to left
        else if(grid[row][col] == -1  && col-1>=0 && grid[row][col-1] == -1 )
            return dfs(row+1,col-1,grid);
        
        else if(grid[row][col]==1 && col+1>=grid[0].size())
            return -1;
        else
            return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        // store passing ball cols in ans vector
        vector<int>ans(grid[0].size(),0);
        for(int j=0; j<grid[0].size(); j++){
            ans[j] = dfs(0,j,grid);
        }
        return ans;
    }
};