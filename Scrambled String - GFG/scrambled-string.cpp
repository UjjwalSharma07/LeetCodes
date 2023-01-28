//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    bool solve(string s1,string s2,unordered_map<string,bool>&dp){
        if(s1.compare(s2)==0)
            return true;
        if(s1.length()<=1)
            return false;
        
        string key = s1;
        key.push_back(' ');
        key.append(s2);
        
        if(dp.find(key) != dp.end()){
            return dp[key];
        }
        bool flag = false;
        int n = s1.size();
        for(int i=1; i<=n-1; i++){
           if((solve(s1.substr(0, i), s2.substr(n-i, i),dp)&&solve(s1.substr(i, n-i), s2.substr(0, n-i),dp))||((solve(s1.substr(0, i), s2.substr(0, i),dp)&&solve(s1.substr(i, n-i), s2.substr(i, n-i),dp))))
        {
            flag = true;
            break;
        }        
        }
        return dp[key] = flag;
    }
    bool isScramble(string S1, string S2){
        //code here
        if(S1.length() != S2.length())
            return false;
        if(S1 == "" && S2=="")
            return true;
        unordered_map<string,bool>dp;
        return solve(S1,S2,dp);
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends