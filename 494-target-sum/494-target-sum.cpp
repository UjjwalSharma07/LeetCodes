class Solution {
public:
    int solve(vector<int>& nums,int sum,int i,map<pair<int,int>,int>& dp){
        if(i<0){
            if(sum == 0)
                return 1;
            return 0;
        }
        if(dp.find({i,sum}) != dp.end()){
            return dp[{i,sum}];
        }
        int ans = solve(nums,sum-nums[i],i-1,dp)+solve(nums,sum+nums[i],i-1,dp);
    
        return dp[{i,sum}] = ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       
        int n = nums.size();
        
        // return solve(nums,target,n-1);
        map<pair<int,int>,int>dp;
        return solve(nums,target,n-1,dp);
    }
};