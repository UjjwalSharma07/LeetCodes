int dp[101][27][101][101];
class Solution {
public:
    string temp ;
    int solve(int i,int prev,int len,int k){
        if(k<0)
            return INT_MAX;
        if(i>=temp.size())
            return 0;
        // case :1 not take
        if(dp[i][prev][len][k] != -1){
            return dp[i][prev][len][k];
        }
        int del = solve(i+1,prev,len,k-1);
        // case :2 take
        int keep=0;
        // if prev element match
        if(temp[i]-'a' == prev){
            if(len == 1 || len == 9 || len == 99){
                keep+=1;
            }
            keep += solve(i+1,temp[i]-'a',len+1,k);
        }
        // else not match
        else{
            keep = 1+solve(i+1,temp[i]-'a',1,k);
        }
        return dp[i][prev][len][k] = min(keep,del);
    }
    int getLengthOfOptimalCompression(string s, int k) {
        temp =s;
        int prev = 26;
        int len=0;
        memset(dp,-1,sizeof(dp));
        return solve(0,prev,len,k);
    }
};