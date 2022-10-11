//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decode(string& s,int& i){
        string res="";
        while(i<s.size() && s[i] != ']'){
            if(!isdigit(s[i])){
                res+=s[i++];
            }
            else{
                int n=0;
                while(i<s.size() && isdigit(s[i]))
                    n = n*10+s[i++]-'0';
                i++; // ignore '['
                string temp = decode(s,i);
                i++; // ignore ']'
                
                while(n--){
                    res+=temp;
                }
            }
        }
        return res;
        
    }
    string decodedString(string s){
        int indx=0;
        return decode(s,indx);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends