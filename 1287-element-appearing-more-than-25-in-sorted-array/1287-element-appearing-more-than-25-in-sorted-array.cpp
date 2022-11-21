class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int cnt = 0;
        int n = arr.size();
        
        int prev = -1;
        int require = n/4;
        
        for(auto i:arr){
            if(i == prev)
                cnt++;
            else{
                prev = i;
                cnt = 1;
            }
            if(cnt>require)    
                return i;
        }
        return -1;
    }
};