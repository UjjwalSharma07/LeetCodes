//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) {
        // code here
        unordered_map<char,int>mp;
        for(auto i:S){
            mp[i]++;
        }
        int s=0;
        int e=S.size()-1;
        
        int dir =0;
        
        while(s<=e){
            if(dir == 0){
                if(mp[S[s]] == 1){
                    s++;
                }
                else{
                    mp[S[s]]--;
                    S[s] = '#';
                    s++;
                    dir=1;
                }
            }
            else{
                if(mp[S[e]] == 1){
                    e--;
                }
                else{
                    mp[S[e]]--;
                    S[e]='#';
                    e--;
                    dir =0;
                }
            }
        }
        string ans="";
        for(auto i:S){
            if(i != '#')
                ans.push_back(i);
        }
        if(dir == 1){
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends