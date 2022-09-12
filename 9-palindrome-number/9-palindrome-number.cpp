class Solution {
public:
    bool isPalindrome(int x) {
        int orginalnum = x;
        long long revnum=0;
        while(x>0){
            int digit = x%10;
            revnum = 10*revnum+digit;
            x/=10;
        }
        
        if(revnum == orginalnum)
            return true;
        return false;
    }
};