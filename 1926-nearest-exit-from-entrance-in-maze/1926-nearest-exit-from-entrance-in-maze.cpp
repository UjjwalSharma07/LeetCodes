class Solution {
public:
    bool isAtBorder(int i,int j,vector<vector<char>>& maze){
        if(i == 0 || i == maze.size()-1)
            return true;
        if( j == 0 || j == maze[0].size()-1)
            return true;
        return false;
    }
    bool isValid(int i,int j,vector<vector<char>>& maze){
        if(i<0 || i>=maze.size() || j<0 || j>= maze[0].size() || maze[i][j] == '+' )
            return false;
        return true;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(); int n = maze[0].size();
        // vector<vector<bool>> vis(m,vector<bool>(n+1));
        vector<vector<int>>dir{{0,1},{1,0},{0,-1},{-1,0}};
        
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        // vis[entrance[0]][entrance[1]] = true;
        maze[entrance[0]][entrance[1]] = '+';
        int cnt=0;
        
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                auto top = q.front();
                q.pop();
                int x = top.first;
                int y = top.second;
                
                for(auto d:dir){
                    int i = x+d[0];
                    int j = y+d[1];
                    
                    if(isValid(i,j,maze)){
                        maze[i][j] = '+';
                        q.push({i,j});
                            if(isAtBorder(i,j,maze))
                                return cnt+1;         
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};