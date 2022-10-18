//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	void fillArray(vector<int>& ans,vector<vector<int>>& A,int i,int j,int n){
	    if(i>=n || j<0){
	        return;
	    }
	    ans.push_back(A[i][j]);
	    fillArray(ans,A,i+1,j-1,n);
	}
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
		vector<int>ans;
		for(int i=0; i<N; i++){
		    fillArray(ans,A,0,i,N);
		}
		
		for(int i=1; i<N; i++){
		    fillArray(ans,A,i,N-1,N);
		}
		return ans;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends