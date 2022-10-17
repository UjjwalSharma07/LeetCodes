class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int changed = 0;
        for(int i=0; i<num.size(); i++){
            
            if(num[i]-'0'< change[num[i]-'0'] && changed == 0){
                num[i] =  change[num[i]-'0']+'0';
                changed = 1;
            }
            
            else if(changed == 1 && num[i]-'0' <= change[num[i]-'0'])
                 num[i] =  change[num[i]-'0']+'0';
            
            else if(changed == 1){
                break;
            }
        }
        return num;
    }
};