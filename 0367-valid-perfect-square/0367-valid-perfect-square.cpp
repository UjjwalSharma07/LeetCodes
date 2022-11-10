class Solution {
public:
     bool mySqrt(int x) {
        int s=0;
        int e=x;

        while(s<=e){
            long long mid = s+(e-s)/2;
            
            if(mid*mid == x){
                return true;
            }
            else if(mid*mid > x){
                e = mid-1;
            }
            else if(mid*mid<x){
                s = mid+1;
            }
        }
        return false;
    }
    bool isPerfectSquare(int num) {
       return mySqrt(num);
        
    }
};