//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        // code here
        int count=0;
        // code here
        for(int i=0;i<S.length()-1;i++)
        { 
            int s=0; int l=0;
            if(S[i]>=97 && S[i]<=122)
                s+=1;
            else
                l+=1;
            for(int j=i+1;j<S.length();j++)
            {
               if(S[j]>=97 && S[j]<=122) 
                    s+=1;
                else
                    l+=1;
                if(s-l==0)
                    count++;
            }
        }
      return count;  
    
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends