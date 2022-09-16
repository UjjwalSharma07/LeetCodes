class Solution {
public:
    int solve(int index,int l,int r,vector<int>& nums,vector<int>& multipliers, vector<vector<int>>& dp){
        if(index == multipliers.size())
            return 0;
        
        if(dp[index][l] != INT_MIN){ 
            return dp[index][l];
        }
        
        int left = nums[l]*multipliers[index]+ solve(index+1,l+1,r,nums,multipliers,dp);
        int right = nums[r]*multipliers[index]+ solve(index+1,l,r-1,nums,multipliers,dp);
        
        return dp[index][l] =  max(left,right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
       
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,INT_MIN));
        return solve(0,0,n-1,nums,multipliers,dp);
    }
};