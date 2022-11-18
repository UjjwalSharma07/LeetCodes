class Solution {
public:
    int diviser(int num,int div){
        while(num%div == 0){
            num /= div;
        }
        return num;
    }
    bool isUgly(int n) {
        if(n<=0){
            return false;
        }
        
        for(auto it: {2,3,5}){
            n = diviser(n,it);
        }
        return n==1;
    }
};