class Solution {
public:
     int solve(int k, int index,int flag,vector<int>& prices, vector<vector<vector<int>>>&dp){
        if(k==0 || index >= prices.size()){
            return 0;
        }
        if(dp[k][index][flag] != -1){
            return dp[k][index][flag];
        }
        int ans = 0;
        if(flag){ // for sell(1)
            ans = max(prices[index]+solve(k-1,index+1,0,prices,dp), solve(k,index+1,1,prices,dp));
        }
        else{ // for buy(0)
            ans = max(solve(k,index+1,0,prices,dp), -1*prices[index]+solve(k,index+1,1,prices,dp));
        }
        
        return dp[k][index][flag] = ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k=2;
        vector<vector<vector<int>>>dp(k+1,vector<vector<int>>(n,vector<int>(2,-1)));
        int flag=0;
        int index=0;
        
        // flag ->0 means buy and 1-> means sell
        return solve(k,index,flag,prices,dp);
    }
};