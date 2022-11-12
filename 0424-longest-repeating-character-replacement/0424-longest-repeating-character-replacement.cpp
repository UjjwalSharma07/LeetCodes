class Solution {
public:
    int characterReplacement(string s, int k) {
            int i=0;
		    int j=0;
		    int ans=0;
		    int maxi = INT_MIN;
		    
		    unordered_map<char,int>mp;
		    
		    while(j<s.size()){
		        mp[s[j]]++;
		        
		        maxi = max(maxi,mp[s[j]]);
		        
		        int max_size = j-i+1-maxi;
		        
		        if(max_size>k){
		            mp[s[i]]--;
		            i++;
		        }
		        ans = max(ans,j-i+1);
		        j++;
		    }
		    return ans;
    }
};