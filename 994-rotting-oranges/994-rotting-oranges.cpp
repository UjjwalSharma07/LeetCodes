
class Solution {
public:
    bool isSafe(vector<vector<int>>& grid,int x,int y){
        
    if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y] == 2 || grid[x][y] == 0)
            return false;
        
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int> > q;
      
        int time = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2)
                    q.push({{i,j},0});
            }
        }
        while(!q.empty()){
            
            auto top = q.front();
            q.pop();
          
  
            int row = top.first.first;
            int col = top.first.second;
            time = top.second;
            
            int Xaxis[4] = {1,0,-1,0};
            int Yaxis[4] = {0,1,0,-1};
            
            for(int i=0; i<4; i++){
                int newx = row+Xaxis[i];
                int newy = col+Yaxis[i];
                if(isSafe(grid,newx,newy) == true){
                    grid[newx][newy] = 2;
                    q.push({{newx,newy},time+1});
                }
            } 
        }
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return time;
    }
};