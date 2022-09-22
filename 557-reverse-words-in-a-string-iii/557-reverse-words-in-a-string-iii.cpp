class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        string ans = "";
        for(int i=0; i<s.length(); i++){
            temp.push_back(s[i]);
            if(s[i] == ' ' || s[i] == '/0'){
                temp.pop_back();
                reverse(temp.begin(),temp.end());
                ans+=temp+' ';
                temp.clear();
            }
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        return ans;
    }
};