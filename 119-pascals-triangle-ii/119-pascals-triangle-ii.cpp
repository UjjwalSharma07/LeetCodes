class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>t;
        vector<vector<int>>temp;
        for(int i=0; i<=rowIndex; i++){
            vector<int>ans(i+1,1);
            for(int j=1;j<i; j++){
                ans[j] = temp[i-1][j]+temp[i-1][j-1];
                t = ans;
            }
            temp.push_back(ans);
            t = ans;
        }
        return t;
    }
};