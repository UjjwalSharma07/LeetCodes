class Solution {
public:
    // recursion
    int solve(int indx,int n,vector<int>& nums){
        if(indx >= n)
            return 0;
        
        int jump=INT_MAX;
        for(int i=1; i<=nums[indx]; i++){
            if(indx+i>n){
                break;
            }
            jump = min( jump,1+solve(indx+i,n,nums) );
        }
        return jump;
    }
    // memoazation
     long long solveMemo(int indx,int n,vector<int>& nums,vector<int>& dp){
        if(indx >= n)
            return 0;
         
        if(dp[indx] != -1)
            return dp[indx];
         
        long long jump=INT_MAX;
        for(int i=1; i<=nums[indx]; i++){
            if(indx+i>n){
                break;
            }
            jump = min( jump,1+solveMemo(indx+i,n,nums,dp) );
        }
        return dp[indx] = jump;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return solveMemo(0,n-1,nums,dp);
    }
};