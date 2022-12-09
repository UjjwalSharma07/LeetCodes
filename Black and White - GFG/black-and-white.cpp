//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
bool isval(int n, int m, int i, int j)
{
    if(i < 0 || i>= n || j < 0 || j >= m)
        return false;
    return true;
}

long long numOfWays(int N, int M)
{
    long long mod = 1e9 + 7;
    long long ans = 0;
    long long tot = M*N;
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<M;j++)
        {
            int c = 0;
            if(isval(N, M, i - 2, j - 1))
                c++;
            if(isval(N, M, i - 2, j + 1))
                c++;
            if(isval(N, M, i + 1, j - 2))
                c++;
            if(isval(N, M, i - 1, j - 2))
                c++;
            if(isval(N, M, i + 2, j - 1))
                c++;
            if(isval(N, M, i + 2, j + 1))
                c++;
            if(isval(N, M, i - 1, j + 2))
                c++;
            if(isval(N, M, i + 1, j + 2))
                c++;
    
            ans = (ans%mod + (tot%mod - c%mod - 1%mod)%mod)%mod;
        }
    }
    return ans;
}