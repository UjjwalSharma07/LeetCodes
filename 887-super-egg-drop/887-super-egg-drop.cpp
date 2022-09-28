class Solution {
public:
     int solve(int e,int f, vector<vector<int>>& dp){
        if(e == 1 )
            return f;
        if(f == 0 || f == 1)
            return f;
        if(dp[e][f] != -1)
            return dp[e][f];
            
        int mini = INT_MAX;
        
        for(int k=1; k<=f; k++){
            int tempans = 1+max(solve(e-1,k-1,dp),solve(e,f-k,dp));
            mini = min(mini,tempans);
        }
        return dp[e][f] = mini;
    }
   // memo + binary search
    int solveMem(int e,int f,vector<vector<int>>& dp){
        if(f == 0 || f == 1)
            return f;
        
        if(e == 1)
            return f;
        
        if(dp[e][f] != -1)
            return dp[e][f];
        
        int mini = INT_MAX;
        int high = f;
        int low = 0;
      
        while(low<=high){
            int mid = (low + high)/2;
            int left = solveMem(e-1,mid-1,dp);
            int right = solveMem(e,f-mid,dp);
            
            int tempAns= 1+max(left,right);
            
            if(left<right)
                low = mid+1;
            
            else
                high = mid-1;
            
            mini = min(mini,tempAns);
        }
        return dp[e][f] = mini;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        // return solve(k,n,dp);
        
        
        return solveMem(k,n,dp);
    }
};