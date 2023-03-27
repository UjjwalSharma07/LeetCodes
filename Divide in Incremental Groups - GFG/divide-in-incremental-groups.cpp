//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int sum,int k,int curr, vector<vector<vector<int>>>& dp){
        if(k == 0){
            if(sum==0)
                return 1;
            return 0;
        }
        if(sum==0)
            return 0;
            
        if(dp[sum][curr][k] != -1)
            return dp[sum][curr][k];
            
        int ways=0;
        for(int i=curr; i<=sum; i++){
            ways+=solve(sum-i,k-1,i,dp);
        }
        return dp[sum][curr][k] = ways;
    }
    int countWaystoDivide(int N, int K) {
        // Code here
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(N+1,vector<int>(K+1,-1)));
        return solve(N,K,1,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends