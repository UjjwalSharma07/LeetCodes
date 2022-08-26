class Solution {
public:
    vector<int> count(int n){
        vector<int>num(10);
        while(n){
            num[n%10]++;
            n=n/10;
        }
        return num;
    }
    bool reorderedPowerOf2(int n) {
       vector<int>temp = count(n);
       for(int i=0; i<=30; i++){
           if(temp==count(1<<i))
               return true;
       }
       return false;
    }
};