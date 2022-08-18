class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string>ss = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
    };
    
        unordered_set<string>ans;
    
        for(auto word:words){
            string temp="";
            for(auto i:word){
                temp += ss[i-'a'];
            }
            ans.insert(temp);
        }
        return ans.size();
    }
};