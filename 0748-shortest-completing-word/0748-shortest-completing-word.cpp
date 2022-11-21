class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
         
        vector<int>map(26, 0);
        for (auto ch : licensePlate) {
            if (isalpha(ch)) {
                map[tolower(ch) - 'a']++;
            }
        }
        
        int mini = INT_MAX;;
        string ans = "";
      
        for (auto& word : words) {
            vector<int> word_map(26, 0);
            for (auto ch : word) {
                word_map[ch - 'a']++;
            }
            
            bool total = true;
            for (int i = 0; i < 26; ++i) {
                if (word_map[i] < map[i]) {
                    total = false;
                    break;
                }
            }
           
            if (total && word.size() <mini) {
                ans = word;
                mini = word.size();
            }
        }
        
        return ans;
    }
};