class Solution {
public:
    void CheckAdj(vector<vector<char>>& grid,int row, int col){
        
        if(row < 0 || row >= grid.size() || col >= grid[0].size() || col<0)
            return;
        
        if(grid[row][col]=='0')
            return;
        
        grid[row][col]='0';
        
        CheckAdj(grid,row+1,col);
        CheckAdj(grid,row,col+1);
        CheckAdj(grid,row-1,col);
        CheckAdj(grid,row,col-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    CheckAdj(grid,i,j);
                    count++;
                }     
            }
        }
        return count;
    }
};