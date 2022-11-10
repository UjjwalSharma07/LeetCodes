class Solution {
public:
    bool judgeSquareSum(int c) {
        int s =0 ;
        int e = sqrt(c);
        while(s<=e){
           long long sumsquare = (long long)s*s + e*e ;
           if(sumsquare == c){
               return true;
           }
           sumsquare < c ? s++:e--;
        }
        return false;
    }
};