class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int>res;
        vector<int>row(matrix.size(),0);
        vector<int>col(matrix[0].size(),0);
        
        for(int i=0; i<matrix.size(); i++){
            int mini = matrix[i][0];
            
            for(int j=1; j<matrix[0].size(); j++){
                mini = min(mini,matrix[i][j]);
            }
            row[i] = mini;
        }
        
        for(int j=0; j<matrix[0].size(); j++){
            int maxi = matrix[0][j];
            
            for(int i=1; i<matrix.size(); i++){
                maxi = max(maxi,matrix[i][j]);
            }
            col[j] = maxi;
        }
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(row[i] == col[j]){
                    res.push_back(row[i]);
                }
            }
        }
        return res;
    }
};