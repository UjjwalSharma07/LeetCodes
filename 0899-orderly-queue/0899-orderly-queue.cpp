class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1){
            int n = s.size();
            string doublestr = s+s;
            string ans = s;
            
            for(int i=1; i<n; i++){
                string str = doublestr.substr(i,n);
                
                if(str<ans){
                    ans = str;
                }
            }
            return ans;
        }
        sort(begin(s),end(s));
        return s;
    }
};