//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        // Write your code here
        vector<int> ans;
        for(int j=0;j<q;j++){
            int count=0;
            for(long long i=4;i<=query[j];i++){
                long long s=sqrt(i);
                if(i==s*s && i%2!=0){
                    bool flag=1;
                    for(long long k=3;k<sqrt(i);k+=2){
                        if(i%k==0) flag=0;
                    }
                    if(flag) count++;
                }
                else if(i==4) count++;
            }
            ans.emplace_back(count);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends