class Solution {
public:
    int reverse(int x) {
        long long rev =0;
        while(x){
            int digit = x%10;
            x/=10;
            
            rev = rev*10+digit;
            
            if(rev<INT_MIN || rev>INT_MAX)
                return 0;
        }
        return (int)rev;
    }
};