class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>endIndx(26,0);
        for(int i=0; i<s.length(); i++){
            endIndx[s[i]-'a'] = i;
        }
        vector<int>result;
        int start = 0;
        int end = 0;
        for(int i=0; i<s.length(); i++){
            end = max(endIndx[s[i]-'a'],end);
            
            if(i==end){
                result.push_back(i-start+1);
                start = i+1;
            }
        }
        return result;
    }
};