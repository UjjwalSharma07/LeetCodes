class Solution {
public:
    bool isSafe(vector<vector<int>>& grid,int x,int y,vector<vector<int>>&vis){
        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y] == 0 && !vis[x][y])
                return true;
        return false;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        queue<pair<pair<int,int>,int>> q;
        
        q.push({{0,0},1});
        
        // Base cases
        if(grid[0][0] == 1) 
            return -1;
        
        if(grid[0][0] == 0 and grid.size()==1 and grid[0].size() == 1) 
            return 1;

        vector<vector<int>>visited(grid.size(),vector<int>(grid.size(),0));
        
        visited[0][0] = 1;
       
        while(!q.empty())
        {
            auto top= q.front();
            q.pop();
            
            int row= top.first.first;
            
            int col= top.first.second;
           
            int no_of_visited_nodes = top.second;
         
            vector<pair<int,int>>directions = {{0,1}, {0,-1}, {1,0}, {-1,0},{1,1}, {-1,-1}, {1,-1},{-1,1}};

            for(auto dir: directions )
            {
                int newx= dir.first + row;
                int newy= dir.second + col;
            
                if(isSafe(grid,newx,newy,visited))
                {
                    q.push({{newx , newy},no_of_visited_nodes+1});
                
                    visited[newx][newy] = true;
                    
                    if(newx==grid.size()-1 and newy== grid[0].size()-1) 
                        return no_of_visited_nodes+1;
                }
            }  
        }
        return -1; 
    }
};