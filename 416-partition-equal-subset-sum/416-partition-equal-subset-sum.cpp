class Solution {
public:
    bool SubsetSum(vector<int>& nums,int i,int sum,vector<vector<int>>& dp){
        if(i == 0){
            return (nums[i]==sum);
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        int include = 0;
        
        if(nums[i]<=sum){
            include = SubsetSum(nums,i-1,sum-nums[i],dp);
        }
        int exclude = SubsetSum(nums,i-1,sum,dp);
        
        return dp[i][sum] = include||exclude;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n =nums.size();
       
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
         vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        if(sum & 1) // if sum is odd then return false;
            return false;
        return SubsetSum(nums,n-1,sum/2,dp);
    }
};