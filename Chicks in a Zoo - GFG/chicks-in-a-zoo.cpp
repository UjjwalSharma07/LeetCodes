//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    long long sum(deque<long long>dq){
        long long s=0;
        while(!dq.empty()){
            s+=dq.front();
            dq.pop_front();
        }
        return s;
    }
	long long int NoOfChicks(int n){
	    deque<long long>dq;
	    dq.push_back(1);
	    
	    for(int i=2; i<=n; i++){
	        if(dq.size()==6){
	            dq.pop_front();
	        }
	        dq.push_back(sum(dq)*2);
	    }
	    return sum(dq);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends