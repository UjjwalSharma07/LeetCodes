class Solution {
public:
    // Memoazation Method
    
//     int solveMem(vector<int>& coins,int target,vector<int>&dp){
        
//         if(target == 0)
//             return 0;
        
//         if(target<0)
//             return INT_MAX;
        
//         if(dp[target] != -1)
//             return dp[target];
        
//         int mini = INT_MAX;
        
//         for(int i=0; i<coins.size(); i++){
//             int ans = solveMem(coins,target-coins[i],dp);
            
//             if(ans != INT_MAX)
//                 mini = min(mini,1+ans);
            
    
//         }
//         return dp[target] = mini;
//     }
    
    // Tabulation Method
    
    int solveTab(vector<int>& coins,int t){
         
        vector<int>dp(t+1,INT_MAX);
        dp[0]=0;
         
        for(int target=1; target<=t; target++){
            
            int mini = INT_MAX;
            
            for(int i=0; i<coins.size(); i++){
                
                if(target-coins[i] >=0){
                    int ans = dp[target-coins[i]];
                    
                    if(ans != INT_MAX)
                        mini = min(mini,1+ans);
                }     
            }
            dp[target] = mini;
        }
        return dp[t];    
    }
    
    int coinChange(vector<int>& coins, int amount) {
         // Memoazation Method
        
        // vector<int>dp(amount+1,-1);
        // int res= solveMem(coins,amount,dp);
        
        // Tabulation Method
        
        int res= solveTab(coins,amount);
        if(res == INT_MAX){
            return -1;
        }
        return res;
    }
};