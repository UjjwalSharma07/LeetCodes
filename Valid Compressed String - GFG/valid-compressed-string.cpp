//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string S, string T) {
         int i = 0, j = 0;

        while (i < S.size() && j < T.size())
        {
            string sum = "0";

            while (T[j] >= '0' && T[j] <= '9')
            {
                sum +=T[j];
                j++;
            }
            i += stoi(sum);
            if (S[i] != T[j])
                return 0;

            else if (S[i] == T[j] and i < S.size() and j < T.size())
            {
                i++;
                j++;
            }

        }
        if (i == S.size() && j == T.size())
            return 1;
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends