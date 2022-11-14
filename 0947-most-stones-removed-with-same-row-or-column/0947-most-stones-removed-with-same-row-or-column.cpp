class Solution {
public:
    void dfs(vector<vector<int>>& stones,vector<int>&vis,int index){
        vis[index] = 1;
        
        for(int i=0; i<stones.size(); i++){
            if(vis[i]!= 1 and (stones[i][0]==stones[index][0]||stones[i][1]==stones[index][1]) )
                dfs(stones,vis,i);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int>vis(n,false);
        int count=n;
        
        for(int i=0; i<n; i++){
            if(vis[i])
                continue;
            count--;
            dfs(stones,vis,i);
        }
        return count;
    }
};