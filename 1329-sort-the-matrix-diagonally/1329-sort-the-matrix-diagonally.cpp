class Solution {
public:
    void CountSort(vector<vector<int>>& mat,int row,int col){
        int m= mat.size();
        int n=mat[0].size();
        
        int map[101]={0};
        int i = row;
        int j = col;
        while(i<m && j<n){
            map[mat[i][j]]++;
            i++;
            j++;
        }
        i=row;
        j=col;
        for(int k=1; k<101; k++){
            while(map[k]>0){
                 mat[i][j] = k;
                 map[k]--;
                 i++;
                 j++;
            }  
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m= mat.size();
        int n=mat[0].size();
        
        for(int i=0; i<m; i++){
            CountSort(mat,i,0);
        }
        for(int j=1; j<n; j++){
            CountSort(mat,0,j);
        }
        return mat;
    }
};