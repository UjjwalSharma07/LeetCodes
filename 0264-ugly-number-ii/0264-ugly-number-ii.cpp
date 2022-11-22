class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0] = 1;
        int p2 = 0; 
        int p3 = 0;
        int p5 = 0;
        
        for(int i=1; i<n; i++){
            int two = dp[p2]*2;    // 1*2 = 2;
            int three = dp[p3]*3; // 1*3  = 3;
            int five = dp[p5]*5; // 1*5 = 5;
            
            dp[i] = min({two,three,five});  // dp[1] = 1;
            
            if(dp[i] == two)
                p2++;
            if(dp[i] == three)
                p3++;
            if(dp[i] == five)
                p5++;
        }
        return dp[n-1];
    }
};