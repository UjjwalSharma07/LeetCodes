class Solution {
public:
    // Recursion
    int solveRec(vector<int>& arr,int index,int n){
	    if(index >= n){
	        return 0;
	    }
	    int include = arr[index]+solveRec(arr,index+2,n);
	    
	    int exclude = 0+solveRec(arr,index+1,n);
	    
	    return max(include,exclude);
	}
    // Memoaization
    int solveMem(vector<int>& arr,int index,int n,vector<int>&dp){
	    if(index >= n){
	        return 0;
	    }
	    if(dp[index] != -1){
	        return dp[index];
	    }
	    int include = arr[index]+solveMem(arr,index+2,n,dp);
	    
	    int exclude = 0+solveMem(arr,index+1,n,dp);
	    
	    return dp[index] = max(include,exclude);
	}
    
    // Tabulation
    int solveTab(vector<int>& arr,int n){
	   
	    vector<int>dp(n+2,0);
	    
	    for(int index=n-1; index>=0; index--){
	        
	        int include = arr[index]+dp[index+2];
	    
	        int exclude = 0+dp[index+1];
	    
	        dp[index] = max(include,exclude);
	    }
	    return dp[0];
	}
    // Spapce OPtimization
    
    int solveSO(vector<int>& arr,int n){
	 
	    int next1=0;
	    int next2=0;
	    int curr=0;
	    
	    for(int index=n-1; index>=0; index--){
	        
	        int include = arr[index]+next2;
	    
	        int exclude = 0+next1;
	    
	        curr = max(include,exclude);
	        
	        next2 = next1;
	        next1 = curr;
	    }
	    return curr;
	}
    int rob(vector<int>& nums) {
        
        int index=0;
        
        int n=nums.size();
	    return solveTab(nums,n);
    }
};