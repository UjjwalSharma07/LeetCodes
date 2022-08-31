class Solution {
public:
    void solve(vector<vector<int>>& heights,int i, int j,int prev, vector<vector<int>>&ocean){
        if(i>=heights.size() || j>=heights[0].size() || i<0 || j<0)
            return;
        if(heights[i][j]<prev)
            return;
        if(ocean[i][j]==1)
            return;
        
        ocean[i][j]=1;
        solve(heights,i+1,j,heights[i][j],ocean);
        solve(heights,i-1,j,heights[i][j],ocean);
        solve(heights,i,j+1,heights[i][j],ocean);
        solve(heights,i,j-1,heights[i][j],ocean);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        if(heights.size()<1){
            return ans;
        }
        vector<vector<int>>pacific(heights.size(),vector<int>(heights[0].size(),0));
        vector<vector<int>>atlantic(heights.size(),vector<int>(heights[0].size(),0));
        
        // for col
        for(int i=0; i<heights[0].size(); i++){
            solve(heights,0,i,INT_MIN,pacific);
            solve(heights,heights.size()-1,i,INT_MIN,atlantic);
        }
        
        // for row
        for(int i=0; i<heights.size(); i++){
            solve(heights,i,0,INT_MIN,pacific);
            solve(heights,i,heights[0].size()-1,INT_MIN,atlantic);
        }
        
        for(int i=0; i<heights.size(); i++){
            for(int j=0; j<heights[0].size(); j++){
                if(pacific[i][j]==1 && atlantic[i][j]==1){
                    vector<int>temp(2);
                    temp[0] = i;
                    temp[1] = j;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};