class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs,int index){
        if(index >= days.size()){
            return 0;
        }
        
        // for 1day pass
        int option1 = costs[0]+solve(days,costs,index+1);
        
        // for 7days pass
        int i;
        // 7 th day k baad next index bhejne k liye 7 din aage bhda do
        for(i=index; i<days.size() && days[i]<days[index]+7; i++); 
        int option2 = costs[1]+solve(days,costs,i);
        
        // for 30days pass
        
        // 30 th day k baad next index bhejne k liye 30 din aage bhda do
        for(i=index; i<days.size() && days[i]<days[index]+30; i++); 
        int option3 = costs[2]+solve(days,costs,i);
        
        return min(option1,min(option2,option3));
    }
    
    // memo
    int solveMem(vector<int>& days, vector<int>& costs,int index, vector<int>& dp){
        if(index >= days.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        // for 1day pass
        int option1 = costs[0]+solveMem(days,costs,index+1,dp);
        
        // for 7days pass
        int i;
        // 7 th day k baad next index bhejne k liye 7 din aage bhda do
        for(i=index; i<days.size() && days[i]<days[index]+7; i++); 
        int option2 = costs[1]+solveMem(days,costs,i,dp);
        
        // for 30days pass
       
        // 30 th day k baad next index bhejne k liye 30 din aage bhda do
        for(i=index; i<days.size() && days[i]<days[index]+30; i++); 
        int option3 = costs[2]+solveMem(days,costs,i,dp);
        
        return dp[index] = min(option1,min(option2,option3));
    }
    // tabulation
    int solveTab(vector<int>&days,vector<int>&costs){
        int N = days.size();
        vector<int>dp(N+1,0);
        
        for(int index=N-1; index>=0 ; index--){
            
            // for 1day pass
            int option1 = costs[0]+dp[index+1];
        
            // for 7days pass
            int i;
             // 7 th day k baad next index bhejne k liye 7 din aage bhda do
            for(i=index; i<days.size() && days[i]<days[index]+7; i++); 
            int option2 = costs[1]+dp[i];
        
            // for 30days pass
       
            // 30 th day k baad next index bhejne k liye 30 din aage bhda do
            for(i=index; i<days.size() && days[i]<days[index]+30; i++); 
            int option3 = costs[2]+dp[i];
        
            dp[index] = min(option1,min(option2,option3));
        }
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int index= 0;
        // solve(days,costs,index);
        int n=days.size();
        vector<int>dp(n+1,-1);
        // return solveMem(days,costs,index,dp);
        return solveTab(days,costs);
    }
};