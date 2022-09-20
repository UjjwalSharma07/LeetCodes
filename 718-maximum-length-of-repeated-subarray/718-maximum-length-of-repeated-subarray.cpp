class Solution {
public:
    int solve(vector<int>& a,vector<int>& b,int N,int M){
        vector<vector<int>>dp(N+1,vector<int>(M+1,0));
        int max = 0;
        for(int n=1; n<N+1; n++){
            for(int m=1; m<M+1; m++){
                if(a[n-1]==b[m-1]){
                    dp[n][m] = 1+dp[n-1][m-1];
                    
                    if(dp[n][m]>max){
                        max = dp[n][m];
                    }
                }
                else{
                    dp[n][m] = 0;
                }
            }
        }
        return max;
    }
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1,nums2,nums1.size(),nums2.size());
    }
};