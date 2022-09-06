class Solution {
public:
    int solve(vector<int>&coins,int amount,int i){
        if(i==0 || amount<=0){
            if(amount == 0)
                return 1;
            return 0;
        }
        int ans = 0;
        if(coins[i-1]<=amount){
            ans = solve(coins,amount-coins[i-1],i)+solve(coins,amount,i-1);
        }
        else
            ans = solve(coins,amount,i-1);
        
        return ans;
    }
    int solveTab(vector<int>&coins,int amnt,int n){
        vector<vector<int>>dp(n+2,vector<int>(amnt+2,0));
        
        for(int i=0; i<=n; i++){
            dp[i][0] = 1;
        }
   
        for(int i=1; i<n+1; i++){
            for(int amount=1; amount<amnt+1; amount++){
              
                if(coins[i-1]<=amount){
                     dp[i][amount] = dp[i][amount-coins[i-1]]+dp[i-1][amount];
                }
                else{
                     dp[i][amount] = dp[i-1][amount];
     
                }     
            }
        }
        return dp[n][amnt];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // return solve(coins,amount,n);
        return solveTab(coins,amount,n);
    }
};