class Solution {
public:
    int find_max(int row,vector<vector<int>>& mat){
        int maxi = 0;
        int col_index=0;
        for(int i=0; i<mat[0].size(); i++){
            if(mat[row][i]>maxi){
                maxi = mat[row][i];
                col_index = i;
            }
        }
        return col_index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int s=0;
        int e = mat.size()-1;
        
        while(s<=e){
            int mid = s+(e-s)/2;
            int col = find_max(mid,mat);
            
            if(mid == 0){
                if(mat[mid+1][col]<mat[mid][col]){
                    return {mid,col};
                }
            }
            else if(mid == mat.size()-1){
                if(mat[mid-1][col]<mat[mid][col]){
                     return {mid,col};
                }
            }
            else{
                if(mat[mid+1][col]<mat[mid][col] && mat[mid-1][col]<mat[mid][col]){
                    return {mid,col};
                }
            }
            if(mat[mid][col]<mat[mid+1][col]){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return {-1,-1};
    }
};