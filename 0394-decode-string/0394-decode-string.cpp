class Solution {
public:
    string decode(string &s,int& i){
        string res="";
        
        while(i<s.size() && s[i] != ']'){
            if(!isdigit(s[i]) ){
                res+=s[i++];
            }
            else {
                int n=0;
                while(i<s.size() && isdigit(s[i]))
                    n = n*10+s[i++]-'0';
                
                i++;  // ignore '['
                string temp = decode(s,i);
                i++;  // ignore ']'
                
                while(n-- > 0){
                    res+=temp;
                }
            }
        }
        return res;
    }
    string decodeString(string s) {
        int indx =0;
        return decode(s,indx);
    }
};