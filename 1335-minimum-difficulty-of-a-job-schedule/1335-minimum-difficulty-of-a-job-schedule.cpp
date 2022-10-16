class Solution {
public:
    int solve(vector<int>& job, int d,int indx,vector<vector<int>>& dp){
        if(d == 1){
            int maxDiffi = job[indx];
            
            for(int i=indx; i<job.size(); i++){
                maxDiffi = max(maxDiffi,job[i]);
            }
            return maxDiffi;
        }
        if(dp[indx][d] != -1)
            return dp[indx][d];
        
        int maxi = INT_MIN;
        int ans = INT_MAX;
        
        for(int i = indx; i<=job.size()-d; i++){
            maxi = max(maxi,job[i]);
            ans = min(ans,maxi+solve(job,d-1,i+1,dp));
        }
        return dp[indx][d] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
       
        int n = jobDifficulty.size();
        if(n<d)
            return -1;
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        
        return solve(jobDifficulty,d,0,dp);
    }
};
