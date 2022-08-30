class Solution {
public:
    int solve(vector<int>& obs,int currpos,int currlane){
        if(currpos==obs.size()-1)
            return 0;
        
        // straight forward momennt
        int finalans = 0;
        if(obs[currpos+1]!= currlane){
            finalans = solve(obs,currpos+1,currlane);
        }
        else{
            // sideways prblms
            int ans = INT_MAX;
            for(int i=1; i<=3; i++){
                if(i!= currlane && obs[currpos] != i){
                    ans = min(ans,1+solve(obs,currpos,i));
                }
            }
            finalans = ans;
        }
        return finalans;
    }
    // mem
    int solveMem(vector<int>& obs,int currlane,int currpos,vector<vector<int>>&dp){
        int lastpos = obs.size()-1;
        if(currpos==lastpos)
            return 0;
        
        if(dp[currlane][currpos] != -1){
            return dp[currlane][currpos];
        }
        // straight forward momennt
        int finalans = 0;
        if(obs[currpos+1]!= currlane){
            finalans = solveMem(obs,currlane,currpos+1,dp);
        }
        else{
            // sideways prblms
            int ans = INT_MAX;
            for(int i=1; i<=3; i++){
                if(i!= currlane && obs[currpos] != i){
                    ans = min(ans,1+solveMem(obs,i,currpos,dp));
                }
            }
            finalans = ans;
        }
        return dp[currlane][currpos] = finalans;
    }
    int minSideJumps(vector<int>& obstacles) {
        int currpos = 0;
        int currlane = 2;
        int n = obstacles.size();
        // return solve(obstacles,currpos,currlane);
        vector<vector<int>>dp(4,vector<int>(n,-1));
        return solveMem(obstacles,currlane,currpos,dp);
    }
};