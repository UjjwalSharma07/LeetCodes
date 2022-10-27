//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   
    unordered_map<int,int>mp;
  
    void solve(int &i,int n,int arr[],vector<int>&in,int l,int r,vector<int>&ans){
        if(i>=n||l>r)
            return;
            
        if(l==r){
          ans.push_back(arr[i]);
        }
        
        int ind=mp[arr[i]];
        i++;
        solve(i,n,arr,in,l,ind-1,ans);
      
        solve(i,n,arr,in,ind+1,r,ans);

        return;
    }
    vector<int> leafNodes(int arr[],int n) {
       vector<int>in(n);
        
       for(int i=0;i<n;i++)
            in[i]=arr[i];
       sort(in.begin(),in.end());
       
       for(int i=0;i<n;i++)
            mp[in[i]]=i;
       
       vector<int>ans;
       int i=0;
       solve(i,n,arr,in,0,n-1,ans);
       return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends