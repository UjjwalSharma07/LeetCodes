class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        queue<int>q;
        vector<bool>visited(rooms.size(),0);
        for(int i=0; i<rooms[0].size(); i++){
            q.push(rooms[0][i]);
        }
        visited[0]= 1;
        
        while(!q.empty()){
            
            int front = q.front();
            
            if(!visited[front]){
                int size = rooms[front].size();
            
                for(int i=0; i<size; i++){
                    if(!visited[rooms[front][i]]){
                        q.push(rooms[front][i]);
                    }
                }
                visited[front] = 1;
            }
            q.pop();
        }
        for(int i=0; i<visited.size(); i++){
            if(!visited[i])
                return false;
        }
        return true;
    }
};