//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          unordered_map<char,int>m;
          
          for(int i=0; i<n; i++){
              m[x[i]] = b[i];
          }
          
          int ans = INT_MIN;
          int sum=0;
          string s,temp;
          
          for(auto x: w){
              temp.push_back(x);
              sum+= m.count(x)?m[x]:x;
              
              if(ans<=sum){
                  ans = sum;
                  s=temp;
              }
              if(sum<0){
                  sum=0;
                  temp.clear();
              }
          }
          return s;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends