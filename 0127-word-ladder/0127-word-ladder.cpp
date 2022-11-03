class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int cnt = 1;
        unordered_set<string>st;
        queue<string>q;
        
        q.push(beginWord);
        for(auto i:wordList){
            st.insert(i);
        }
        if(!st.count(endWord)){
            return 0;
        }
        while(!q.empty()){
            int size = q.size();
            
            while(size--){
                auto front = q.front();
                q.pop();
                st.erase(front);
                
                if(front == endWord){
                    return cnt;
                }
                
                for(int i=0; i<beginWord.size(); i++){
                    char temp = front[i];
                    
                    for(char ch = 'a'; ch<='z'; ch++){
                        front[i] = ch;
                        
                        if(st.find(front) != st.end()){
                            q.push(front);
                        }
                    }
                    front[i] = temp;
                }
            }
            cnt++;
        }
        return 0;
    }
};