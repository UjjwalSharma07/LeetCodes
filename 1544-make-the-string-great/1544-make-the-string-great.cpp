class Solution {
public:
    string makeGood(string s) {
        
        int i=0;
        int n = s.size();
        
        if(n==0 || n==1)
            return s;
        
        while(i<n-1){
            if(abs(s[i]-s[i+1]) == 32){
                s.erase(i,2);
                if(i>0)
                    i--;
                n = s.size();
            }
            else
                i++;
            
        }
        return s;
    }
};