class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size()-1;
        int n2 = num2.size()-1;
        string ans="";
        int carry = 0;
        while(n1>=0 || n2>=0){
            if(n1<0){
                ans.push_back(((num2[n2]-'0' +carry)%10)+'0');
                carry = (num2[n2]-'0'+carry)/10;
                n2--;
            }
            else if(n2<0){
                ans.push_back(((num1[n1]-'0'+carry)%10)+'0');
                carry = (num1[n1]-'0'+carry)/10;
                n1--;
            }
            else{
                ans.push_back(((num1[n1]-'0'+num2[n2]-'0'+carry)%10)+'0');
                carry = (num1[n1]-'0'+num2[n2]-'0'+carry)/10;
                n1--;
                n2--;
            }
        }
        if(carry){
            ans.push_back(carry+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};