class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        unordered_set<int>row(n);
        vector<unordered_set<int>>col(n);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int val = matrix[i][j];
                
                if(val>=1 && val<=n){
                    if(row.count(val) || col[j].count(val))
                        return false;
                    else{
                        row.insert(val);
                        col[j].insert(val);
                    }
                      
                }
                else
                    return false;
                
            }
            row.clear();
        }
        return true;
    }
};