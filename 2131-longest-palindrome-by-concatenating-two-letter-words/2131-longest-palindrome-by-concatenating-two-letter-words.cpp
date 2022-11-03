class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int ans=0;
        for(string x:words){
            string y=x;
            reverse(y.begin(),y.end());
            cout<<y<<" ";
            if(mp.find(y)!=mp.end()){
                ans+=4;
                mp[y]--;
                if(mp[y]==0){
                    mp.erase(y);
                }
                
            }else{
                mp[x]++;
            }
        }
        for(auto x:mp){
            if(x.first[0]==x.first[1]){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};