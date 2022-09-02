class Solution {
public:
    // recursion
    int len=0;
    int solve(int n,int si,int ei,vector<int>& cuts){
        if(si>=ei)
            return 0;
        
        int ans = INT_MAX;
        for(int cut =si; cut<ei;cut++){
            int leftEndindPoint = si==0?0:cuts[si-1];
            int rightEndingPoint = ei==cuts.size()? len:cuts[ei];
            
            int cost = rightEndingPoint-leftEndindPoint;
            
            int minleftcut = solve(n,si,cut,cuts);
            int minrightcut = solve(n,cut+1,ei,cuts);
            
            int myans = minleftcut+minrightcut+cost;
            
            ans = min(myans,ans);
        }
        return ans;
    }
    
    // memoazation
    
    int solveMem(int n,int si,int ei,vector<int>& cuts,vector<vector<int>>&dp){
        if(si>=ei)
            return 0;
        if(dp[si][ei]!=-1){
            return dp[si][ei];
        }
        int ans = INT_MAX;
        for(int cut =si; cut<ei;cut++){
            int leftEndindPoint = si==0?0:cuts[si-1];
            int rightEndingPoint = ei==cuts.size()? len:cuts[ei];
            
            int cost = rightEndingPoint-leftEndindPoint;
            
            int minleftcut = solveMem(n,si,cut,cuts,dp);
            int minrightcut = solveMem(n,cut+1,ei,cuts,dp);
            
            int myans = minleftcut+minrightcut+cost;
            
            ans = min(myans,ans);
        }
        return dp[si][ei] = ans;
    }
    int minCost(int n, vector<int>& cuts) {
        len=n;
        sort(cuts.begin(),cuts.end());
        // return solve(n,0,cuts.size(),cuts);
        int l = cuts.size();
        vector<vector<int>>dp(l+1,vector<int>(l+1,-1));
        return solveMem(n,0,cuts.size(),cuts,dp);
    }
};