class Solution {
public:
    int calculate(string s) {
        int num = 0;
        int res = 0;
        int sign = 1;
        
        stack<int>st;
        
        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])){
                num = num*10 + (s[i]-'0');  // number bnayege
            }
            else if(s[i] == '+'){
                res+= (num*sign);
                num = 0;
                sign = 1;
            }
            else if(s[i] == '-'){
                res+= (num*sign);   
                num = 0;
                sign = -1;
            }
            else if(s[i] == '('){  // open braket mtlb ki new calculation start hogi so previous ka sign and result stack mai store kr lenge
                st.push(res);
                st.push(sign);
                num = 0; 
                res = 0;
                sign = 1;
            }
            else if(s[i] == ')'){
                res+= (num*sign);
                num = 0;
                int stack_sign = st.top();
                st.pop();
                int prev_res = st.top();
                st.pop();
                
                res*=stack_sign;
                res+=prev_res;
            }
        }
        res+=(num*sign);
        return res;
    }
};