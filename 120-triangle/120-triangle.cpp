class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>dp(n,0);
        for(int i=0; i<n; i++){
            dp[i] = triangle[n-1][i];  // initialise the dp vector with last row of triangle
                                        // for eg. vector<int>dp = 4,1,8,3 initialization
        }
        for(int i=n-2; i>=0; i--){  // run outer loop from n-2 bcoz n-1 already in dp vector
            for(int j=0; j<triangle[i].size(); j++){  // run inner loop in every rows one by one
                dp[j] = min(dp[j],dp[j+1])+triangle[i][j];  //dp[n-2] = 6,5,7
                                                            // min of j=0 (6), j+1=5 
                                                            // 5+ triagle[i][j] (4) = 9;
            }
        }
        return dp[0];
    }
};