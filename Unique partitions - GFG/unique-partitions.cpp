//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	vector<vector<int>> res;
	void helper(int n,vector<int>& t,int target){

         if(target==0){
             if(!t.empty())
                res.push_back(t);
             return;        
         }
         if(n==0 || target<0) 
            return;
         
         t.push_back(n);
         helper(n,t,target-n);
         t.pop_back();
         helper(n-1,t,target);
    }
    vector<vector<int>> UniquePartitions(int n) {
        // Code here
        vector<int> t;
        helper(n,t,n);
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends