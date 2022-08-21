class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size();i++){
            for(int j=i; j<matrix[0].size(); j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(int i=0; i<matrix.size(); i++){
            int leftindex = 0;
            int rightindex = matrix[i].size()-1;
            
            while(leftindex<rightindex){
                int temp = matrix[i][leftindex];
                matrix[i][leftindex] =  matrix[i][rightindex];
                matrix[i][rightindex] = temp;
                
                leftindex++;
                rightindex--;
            }
        }
    }
};