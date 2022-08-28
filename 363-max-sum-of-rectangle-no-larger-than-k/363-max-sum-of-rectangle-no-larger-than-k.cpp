class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int res = INT_MIN;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int left = 0; left<cols; left++){
            vector<int>sums(rows);
            for(int right = left; right<cols; right++){
                for(int i=0; i<rows; i++){
                    sums[i] += matrix[i][right];
                }
                set<int>s={0};
                int runSum = 0;
                for(auto sum:sums){
                    runSum+=sum;
                    // cummulativeSum[i]  = cummulativeSum[j] - k;
                    auto it = s.lower_bound(runSum-k);
                    if(it != end(s))
                        res = max(res,(runSum - *it));
                    s.insert(runSum);
                }
            }
        }
        return res;
    }
};