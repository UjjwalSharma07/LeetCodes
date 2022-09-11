class Solution {
public:
    
    string shortestCommonSupersequence(string str1, string str2) {
        string a = str1;
        string b = str2;
        int N=str1.size();
        int M=str2.size();
        
        // ***LCS***
        vector<vector<int>>dp(N+1,vector<int>(M+1,0));
         for(int n=1; n<N+1; n++){
             for(int m=1; m<M+1; m++){
                 if(a[n-1] == b[m-1]){
                     dp[n][m] = 1+dp[n-1][m-1];
                 }
                 else
                     dp[n][m] = max(dp[n-1][m],dp[n][m-1]);
             }
         }
        
        // *****print SCS*****
        string ans="";
        int i = N;
        int j = M;
        
        while(i > 0 && j > 0){
        
            if(a[i-1] == b[j-1]) {
                ans.push_back(a[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    ans.push_back(a[i-1]);
                    i--;
                }else{
                    ans.push_back(b[j-1]);
                    j--;
                }
            }
        }
        while(i>0){
            ans.push_back(a[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(b[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};