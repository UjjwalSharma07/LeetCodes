class Solution {
public:
    int solve(vector<int>& coins,int target,vector<int>&dp){
        
        if(target == 0)
            return 0;
        
        if(target<0)
            return INT_MAX;
        
        if(dp[target] != -1)
            return dp[target];
        
        int mini = INT_MAX;
        
        for(int i=0; i<coins.size(); i++){
            int ans = solve(coins,target-coins[i],dp);
            
            if(ans != INT_MAX)
                mini = min(mini,1+ans);
            
    
        }
        return dp[target] = mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int res= solve(coins,amount,dp);
        
        if(res == INT_MAX){
            return -1;
        }
        return res;
    }
};