class Solution {
public:
    int solve(vector<int>& arr,int n){
	   
	    vector<int>dp(n+2,0);
	    
	    for(int index=n-1; index>=0; index--){
	        
	        int include = arr[index]+dp[index+2];
	    
	        int exclude = 0+dp[index+1];
	    
	        dp[index] = max(include,exclude);
	    }
	    return dp[0];
	}
    int rob(vector<int>& nums) {
        int index=0;
        int n=nums.size();
	    return solve(nums,n);
    }
};