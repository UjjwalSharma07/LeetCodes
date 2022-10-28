class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i=1; i<words.size(); i++){
            string a = words[i];
            sort(begin(a),end(a));
            
            string b = words[i-1];
            sort(begin(b),end(b));
            
            if(a==b){
                words.erase(words.begin()+i);
                i--;
            }
        }
        return words;
    }
};