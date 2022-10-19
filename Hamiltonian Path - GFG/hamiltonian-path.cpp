//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    bool dfs(int n, vector<int> adj[], vector<int> &vist, int src){
        if(n==0){
            return true;
        }
        vist[src]=1;
        for(auto &x:adj[src]){
            if(vist[x]==0){
                if(dfs(n-1,adj,vist,x)){
                    return true;
                }
            }
        }
        vist[src]=0;
        return false;
    }
    
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        vector<int> adj[N];
        
        for(auto &x:Edges){
            adj[x[0]-1].push_back(x[1]-1);
            adj[x[1]-1].push_back(x[0]-1);
        }
        
        vector<int> vist(N,0);
        
        for(int i=0;i<N;i++){
            if(dfs(N-1,adj,vist,i)){
                return true;
            }
        }
        return false;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends