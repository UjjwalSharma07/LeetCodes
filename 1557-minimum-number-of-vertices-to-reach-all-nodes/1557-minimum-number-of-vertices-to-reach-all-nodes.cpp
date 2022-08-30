class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>indegree(n,0);
        
        for(int i=0; i<edges.size(); i++){
            indegree[edges[i][1]]++;
        }
        for(int j=0; j<indegree.size(); j++){
            if(indegree[j]==0){
                ans.push_back(j);
            }
        }
        return ans;
    }
};