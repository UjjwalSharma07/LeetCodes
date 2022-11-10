class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        int e=x;
        long long ans=-1;
        while(s<=e){
            long long mid = s+(e-s)/2;
            
            if(mid*mid == x){
                return mid;
            }
            else if(mid*mid > x){
                e = mid-1;
            }
            else if(mid*mid<x){
                ans=mid;
                s = mid+1;
            }
        }
        return ans;
    }
};