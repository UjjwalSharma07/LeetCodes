class Solution {
public:
    bool isPalindrome(string& s,int i,int j){
       
        while(i<j){
            if(s[i]!=s[j])
               return false;
            i++;
            j--;
        }
        return true;
    }
   int solve(string &s,int i,int j,vector<int>&dp)
    {
        if(i>=j || isPalindrome(s,i,j))
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int res=INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            if(isPalindrome(s, i, k)){                         
                int temp=solve(s,k+1,j,dp)+1;
                res=min(res,temp);
            }
        }
        return dp[i]=res;
    }

    int minCut(string s) {
       
        int n=s.length();
        vector<int>dp(n+1,-1);
        return solve(s,0,n-1,dp);
        
    }   
};