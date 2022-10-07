class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count[26][26]={0};
        int ans=0;
        
        for(auto i:words){
            int a = i[0]-'a';
            int b = i[1]-'a';
            if(count[b][a]){
                ans+=4;
                count[b][a]--;
            }
            else
                count[a][b]++;
        }
        for(int i=0; i<26; i++){
            if(count[i][i]){
                ans+=2;
                break;
            }
        }
        return ans;
    }
};